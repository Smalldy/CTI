#include "strcolorsys.h"

PCOLORNODE splitNode(LIST* list,char* addr)
{
	PCOLORNODE pTemp = list->HeadAddr;
	int i;
	for(pTemp = list->HeadAddr, i = 1; pTemp != NULL; pTemp = pTemp->pNext,i++)
	{
		if(pTemp->addrEnd == addr)
		{
			//.... 
			//printf("pTemp->addrEnd == addr\n");
			return pTemp;
		}
		else if(pTemp->addrStart == addr)
		{
			//....
			//printf("pTemp->addrStart == addr\n"); 
			return pTemp;
		}else if(pTemp->addrStart < addr && pTemp->addrEnd > addr)
		{//拆分结点 不变更颜色信息 只更改地址信息 
			insert_b(list,i,addr,pTemp->addrEnd,pTemp->colorNumber);
			pTemp->addrEnd = addr;
			//printf("调试: 拆分结点!\n"); 
			return pTemp;	
		}else
		{//不正确的数据 
			//printf("数据有误!%p,%p,%p\n",pTemp->addrStart,addr,pTemp->addrEnd);
			continue;
		} 
	} 
	return NULL;
}
void mergeNode(LIST* list,char* addr1,char* addr2, int colorNumber)
{
	int i;
	PCOLORNODE pTemp = list->HeadAddr;
	PCOLORNODE p1,p2;
	int i1,i2;
	for(i=1; pTemp != NULL; pTemp = pTemp->pNext,i++)
	{
		if(pTemp->addrStart == addr1)
		{
			p1 = pTemp;
			i1 = i;
		}
		if(pTemp->addrEnd == addr2)
		{
			p2 = pTemp;
			i2 = i;
			break;
		}
	}
	p1->addrEnd = p2->addrEnd;
	p1->colorNumber = colorNumber;
	for(i=i1+1; i <= i2; i++)
	{
		delet(list,i);
	}
	return ;
}
void addStrColorAddr(LIST * list,char* addr1, char* addr2,int colorNumber)
{
	if(list->HeadAddr == NULL )
	{
		//printf("初始化链表\n");
		initList(list, addr1, addr2, colorNumber);		
	}
	else
	{
		//printf("addr1:%p,addr2:%p\n",addr1,addr2); 
		PCOLORNODE pTemp1,pTemp2;
		char *startAddr,*endAddr;
		pTemp1 = splitNode(list, addr1);
		if(pTemp1->addrStart == addr1)
		{
			startAddr = pTemp1->addrStart;
		}else if(pTemp1->addrEnd == addr1)
		{
			pTemp1 = pTemp1->pNext;//合并起点为返回值的下一个结点 
			startAddr = pTemp1->addrStart;
		}else
		{	
			pTemp1 = pTemp1->pNext;//合并起点为返回值的下一个结点 
			startAddr = pTemp1->addrStart;			
		}
	//	printf("完成第一个节点的拆分!\n"); 
		//..
		pTemp2 =  splitNode(list, addr2);
		if(pTemp2->addrStart == addr2)
		{
			endAddr = pTemp2->addrStart;
		}else if(pTemp2->addrEnd == addr2)
		{
			endAddr = pTemp2->addrEnd;	
		}else
		{
			endAddr = pTemp2->addrEnd;
		}
	//	printf("将要合并的地址:%p,%p\n",startAddr, endAddr); 
		mergeNode(list,startAddr,endAddr,colorNumber);
	}
	return ;
}
void reSet(LIST* list,char* addr1, char* addr2, int colorNumber)
{
	PCOLORNODE pTemp = list->HeadAddr;
	int i = 2;
	for(i = 2; i <= list->len; i++)
	{
		delet(list,i);
	}
	pTemp->addrStart = addr1;
	pTemp->addrEnd = addr2;
	pTemp->colorNumber = colorNumber;
	return ;
}
void delList(LIST* list)
{
	int i;
	for(i = 1; i <= list->len; i++)
	{
		delet(list,i);
	}
	return ;
}
