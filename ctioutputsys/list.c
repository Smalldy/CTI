#include<malloc.h>
#include<stdio.h> 
#include"list.h"
#define MALLOC (PCOLORNODE)malloc(sizeof(COLORNODE))
void initList(LIST* list,char* addrStart, char* addrEnd, int colorNumber)
{
	PCOLORNODE tpl = NULL;
	tpl = MALLOC;
	list->HeadAddr = tpl;
	list->TailAddr = tpl;
	tpl->addrStart = addrStart;
	tpl->addrEnd = addrEnd;
	tpl->colorNumber = colorNumber;
	tpl->pNext = NULL;
	list->len = 1;
	//printf("初始化:[%p,%p]\n",list->HeadAddr->addrStart,list->HeadAddr->addrEnd);
	return ;
}
void pushBack(LIST* list,char* addrStart, char* addrEnd, int colorNumber)
{
	PCOLORNODE tpl = NULL;
	tpl = MALLOC;
	tpl->addrStart = addrStart;
	tpl->addrEnd = addrEnd;
	tpl->colorNumber = colorNumber;
	tpl->pNext = NULL;
	list->TailAddr->pNext = tpl;
	list->TailAddr = tpl;
	list->len += 1;
	return ;
}
void pushFront(LIST* list,char* addrStart, char* addrEnd, int colorNumber)
{
	PCOLORNODE tpl = NULL;
	tpl = MALLOC;
	tpl->addrStart = addrStart;
	tpl->addrEnd = addrEnd;
	tpl->colorNumber = colorNumber;
	tpl->pNext = list->HeadAddr;
	list->HeadAddr = tpl;
	list->len += 1;
	return ;
}
void p(LIST* list)
{
	PCOLORNODE plt;
	plt = list->HeadAddr;  
	while(1)
	{
		printf("ADDR1:%p,ADDR2:%p,COLORNUMBER:%d\n",plt->addrStart,plt->addrEnd,plt->colorNumber);
		if(plt == list->TailAddr)
		{
			break; 
		} 
		else
		{
			plt = plt->pNext; 
		} 
	
	} 
}
void insert_f(LIST* list, int pos, char* addrStart, char* addrEnd, int colorNumber)
{
	PCOLORNODE pHead = list->HeadAddr;
	PCOLORNODE pTemp; 
	if(pos == 1)
	{
		pTemp = MALLOC;
		pTemp->addrStart = addrStart;
		pTemp->addrEnd = addrEnd;
		pTemp->colorNumber = colorNumber;
		pTemp->pNext = pHead;
		list->HeadAddr = pTemp; 
		list->len += 1;	
	}
	else
	{
		int i = 1;
		pHead = list->HeadAddr;
		pTemp = pHead;	
		while(1)
		{
			if(i == pos - 1)
			{
				PCOLORNODE newnode = MALLOC;
				newnode->addrStart = addrStart;
				newnode->addrEnd = addrEnd;
				newnode->colorNumber = colorNumber;
				newnode->pNext = pTemp->pNext;
				pTemp->pNext = newnode;
				list->len += 1;
				break;
			}
			pTemp = pTemp->pNext;
			i++;
		}
	}
	return ;
}
void insert_b(LIST* list, int pos, char* addrStart, char* addrEnd, int colorNumber)
{
	PCOLORNODE pHead = list->HeadAddr;
	PCOLORNODE pTemp = pHead; 
	int i = 1;
	while(1)
	{
		if(i == pos)
		{
			PCOLORNODE newnode = MALLOC;
			newnode->addrStart = addrStart;
			newnode->addrEnd = addrEnd;
			newnode->colorNumber = colorNumber;
			newnode->pNext = pTemp->pNext;
			pTemp->pNext = newnode;
			if(newnode->pNext == NULL)
			{
				list->TailAddr = newnode;
			}
			list->len += 1;
			break;
		}
		pTemp = pTemp->pNext;
		i++;
	}
	
	return ;
}
void delet(LIST* list, int pos)
{
	PCOLORNODE pHead = list->HeadAddr;
	PCOLORNODE pTemp = pHead;
	int i = 1;
	while(1)
	{
		if(pTemp == NULL)
		{
			return ;
		}
		if(pos == 1)
		{
			list->HeadAddr = pTemp->pNext;//更新头结点 
			free(pTemp);//释放内存 
			list->len -= 1;
			return ;
		}
		if(i == pos - 1)
		{
			PCOLORNODE pTemp2 = pTemp->pNext->pNext;//记录目标结点的指针域 
			if(pTemp2 == NULL)//如果目标结点的指针域是NULL 说明目标结点是尾节点 
			{
				list->TailAddr = pTemp;
			}
			free(pTemp->pNext);//释放目标结点
			pTemp->pNext = pTemp2;//重新指向
			list->len -= 1;
			return ;		
		}
		pTemp = pTemp->pNext;
		i = i + 1;
	}

}
int  isEmpty(LIST* list)
{
	if(list->TailAddr == NULL)
		return 1;
	else
		return 0; 
}







