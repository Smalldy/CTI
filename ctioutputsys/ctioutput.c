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
	//分析字符串 写入screen内存
	char *pstr = str;//临时变量
	char *addr;//待操作地址 
	int width = pscreen->width;//屏幕宽度 
	int height = pscreen->height = pscreen->height;//屏幕高度
	int xCrd = pscreen->xCrd;
	int yCrd = pscreen->yCrd;//光标信息
	char *org_addr = addrByCrd(pscreen,xCrd, yCrd);//记录最初的待操作地址 
	int increment = 0;//内存增量 计算str跨越了多少内存空间 
	//开始解析字符串  
	//1.如果遇到普通字符:写入screen内存 并将光标左移1个单位
	//2.如果遇到\n则从\n的位置开始填充到本行末尾 光标x值同时自增
	//3.如果遇到\t则从\t的位置开始 填充四个空格 光标x值自增4
	//4.如果遇到\0 说明本字符串处理完毕 将字符串所占内存段载入list \0不会被写入到screen内存中
	for(pstr = str; ; pstr++)
	{
		if(*pstr != '\n' && *pstr != '\t' && *pstr != '\0')
		{//*pstr 为一般字符
			addr = addrByCrd(pscreen,xCrd, yCrd);//寻找操作地址
			*addr = *pstr;//写入内存
			xCrd++;//光标x坐标自增1 
			increment++; 
			if(xCrd == pscreen->width)
			{
				xCrd = 0;
				yCrd++;
			}
		}else if(*pstr == '\n')
		{
			addr = addrByCrd(pscreen, xCrd, yCrd);//寻找操作地址
			//填充空格
			fillCharToMemory(addr,' ',pscreen->width - xCrd);
			increment += pscreen->width - xCrd;
			xCrd = 0;
			yCrd++;
		}else if(*pstr == '\t')
		{
			addr = addrByCrd(pscreen, xCrd, yCrd);//寻找操作地址
			//填充空格
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
			//载入colorlist 
			//printf("载入颜色表\n");
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
	SetConsoleWindowInfo(hNewConsole,1,&rc);// 重置窗口位置和大小
	COORD size = {pscreen->width, pscreen->height + 2};
	SetConsoleScreenBufferSize(hNewConsole,size); // 重新设置缓冲区大小
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
