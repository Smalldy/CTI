#include "ctioutput.h"
#include <malloc.h>
#include <windows.h>
//==============tool==================

int  sizeStrByByte(char* str)
{
	int count = 0;
	char *tp = str;
	while(1)
	{
		if(*tp != '\0')
		{
			count++;
			tp++;
		}
		else
		{
			return count+1;
		}
	} 
}
char* addrByCrd(PSCREEN pscreen, int xCrd, int yCrd)
{
	char* addr;
	int increment = 0;
	addr = pscreen->screen;
	// * * * * * * *
	// * * * - * * *
	// * * * * * * *
	// * * * * * * *
	// * * * * * * * = 7
	//x = 3 y = 1 1*7+3=10
	increment = (yCrd)*pscreen->width + xCrd;
	addr += increment;
	//increment = 0;
	return addr; 
}
void fillCharToMemory(char* Memoryaddr,char ch,int num)
{
	int i = 0;
	for(i = 0; i <= num; i++)
	{
		*(Memoryaddr + i) = ch;
	}
	return ;
}
//==============user==================
void setScreenSize(PSCREEN pscreen,int cxWidth,int cyHeight)
{
	pscreen->width = cxWidth;
	pscreen->height = cyHeight;
	return ;
}
void crdMove(PSCREEN pscreen,int x, int y)
{
	pscreen->xCrd = x;
	pscreen->yCrd = y;
	return ;
}
char* creatScreen(PSCREEN pscreen)
{
	char *p = (char*)malloc(((pscreen->width) * (pscreen->height) + 1)*sizeof(char));
	fillCharToMemory(p,' ',(pscreen->width) * (pscreen->height));
	*(p+(pscreen->width) * (pscreen->height)) = '\0';
	pscreen->xCrd = 0;
	pscreen->yCrd = 0;
	pscreen->screen = NULL;
	pscreen->list.HeadAddr = NULL;
	pscreen->list.TailAddr = NULL;
	pscreen->screen = p;
	addStrColorAddr(&pscreen->list,p,p+(pscreen->width) * (pscreen->height),15);
	return pscreen->screen;	
}
void addStrToScreen(PSCREEN pscreen,char* str,int colorNumber)
{
	//�����ַ��� д��screen�ڴ�
	char *pstr = str;//��ʱ����
	char *addr;//��������ַ 
	int width = pscreen->width;//��Ļ��� 
	int height = pscreen->height = pscreen->height;//��Ļ�߶�
	int xCrd = pscreen->xCrd;
	int yCrd = pscreen->yCrd;//�����Ϣ
	char *org_addr = addrByCrd(pscreen,xCrd, yCrd);//��¼����Ĵ�������ַ 
	int increment = 0;//�ڴ����� ����str��Խ�˶����ڴ�ռ� 
	//��ʼ�����ַ���  
	//1.���������ͨ�ַ�:д��screen�ڴ� �����������1����λ
	//2.�������\n���\n��λ�ÿ�ʼ��䵽����ĩβ ���xֵͬʱ����
	//3.�������\t���\t��λ�ÿ�ʼ ����ĸ��ո� ���xֵ����4
	//4.�������\0 ˵�����ַ���������� ���ַ�����ռ�ڴ������list \0���ᱻд�뵽screen�ڴ���
	for(pstr = str; ; pstr++)
	{
		if(*pstr != '\n' && *pstr != '\t' && *pstr != '\0')
		{//*pstr Ϊһ���ַ�
			addr = addrByCrd(pscreen,xCrd, yCrd);//Ѱ�Ҳ�����ַ
			*addr = *pstr;//д���ڴ�
			xCrd++;//���x��������1 
			increment++; 
			if(xCrd == pscreen->width)
			{
				xCrd = 0;
				yCrd++;
			}
		}else if(*pstr == '\n')
		{
			addr = addrByCrd(pscreen, xCrd, yCrd);//Ѱ�Ҳ�����ַ
			//���ո�
			fillCharToMemory(addr,' ',pscreen->width - xCrd);
			increment += pscreen->width - xCrd;
			xCrd = 0;
			yCrd++;
		}else if(*pstr == '\t')
		{
			addr = addrByCrd(pscreen, xCrd, yCrd);//Ѱ�Ҳ�����ַ
			//���ո�
			fillCharToMemory(addr,' ',4);
			increment += 4;
			xCrd += 4;
			if(xCrd >= pscreen->width)
			{
				xCrd = xCrd % pscreen->width;
				yCrd += xCrd / pscreen->width;
			} 
		}else if(*pstr == '\0')
		{
			//����colorlist 
			//printf("������ɫ��\n");
			addStrColorAddr(&pscreen->list,org_addr,org_addr+increment,colorNumber);
			break; 
		}
	
	} 
	pscreen->xCrd = xCrd;
	pscreen->yCrd = yCrd;
	return ;
}
void screenClean(PSCREEN pscreen)
{
	pscreen->xCrd = 0;
	pscreen->yCrd = 0;
	fillCharToMemory(pscreen->screen,' ',(pscreen->width) * (pscreen->height));
	*(pscreen->screen+(pscreen->width) * (pscreen->height)) = '\0';
	//printf("%s",pscreen->screen); 
	//addStrColorAddr(&pscreen->list,pscreen->screen,pscreen->screen+(pscreen->width) * (pscreen->height),15);
	initList(&pscreen->list,pscreen->screen,pscreen->screen+(pscreen->width) * (pscreen->height),15);
	return ;
	
}
void ctiPrint(PSCREEN pscreen)
{
	HANDLE hNewConsole = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ,0,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
	SMALL_RECT rc = {0,0, pscreen->width -1, pscreen->height - 1 + 2}; 
	SetConsoleWindowInfo(hNewConsole,1,&rc);// ���ô���λ�úʹ�С
	COORD size = {pscreen->width, pscreen->height + 2};
	SetConsoleScreenBufferSize(hNewConsole,size); // �������û�������С
	PCOLORNODE pNode = pscreen->list.HeadAddr;
	char* addr1;
	char* addr2;
	int size1;
	char *s;
	s = (char*)malloc(pscreen->width*pscreen->height + 1);
	for(;pNode != NULL;pNode = pNode->pNext)
	{
		addr1 = pNode->addrStart;
		addr2 = pNode->addrEnd;
		size1 = addr2 - addr1;
		
		int i = 0;
		while(1)
		{
			
			*(s+i) = *(addr1+i);
			if(i == size1)
			{
				break;
			}
			i++;
		}
		*(s+size1) = '\0';
		SetConsoleTextAttribute(hNewConsole,pNode->colorNumber);
		WriteConsole(hNewConsole,s,strlen(s), NULL, NULL);
		
	}
	SetConsoleActiveScreenBuffer(hNewConsole);
	free(s);
	return ;
}
