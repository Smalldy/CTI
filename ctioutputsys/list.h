#ifndef _LIST_H_
#define _LIST_H_
typedef struct colornode
{
	char* addrStart;
	char* addrEnd;
	int colorNumber;
	struct colornode* pNext;
}COLORNODE, *PCOLORNODE;
typedef struct listData
{
	PCOLORNODE HeadAddr;
	PCOLORNODE TailAddr;
	int len;
}LIST;
int  isEmpty(LIST* list);
void p(LIST* list); 
void initList(LIST* list,char* addrStart, char* addrEnd, int colorNumber);
void pushBack(LIST* list,char* addrStart, char* addrEnd, int colorNumber);
void pushFront(LIST* list,char* addrStart, char* addrEnd, int colorNumber);
void insert_f(LIST* list, int pos, char* addrStart, char* addrEnd, int colorNumber);
void insert_b(LIST* list, int pos, char* addrStart, char* addrEnd, int colorNumber);
void delet(LIST* list, int pos);



#endif
