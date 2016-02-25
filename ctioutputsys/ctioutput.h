#ifndef _CTIOUTPUT_H_
#define _CTIOUTPUT_H_
#include "strcolorsys.h"
#include <windows.h> 
#include <wincon.h> 
typedef struct screen
{
	int width;//��� 
	int height;//�߶�
	int xCrd;
	int yCrd;//������� 
	char* screen; 
	LIST list; //��ɫ�� 
}SCREEN,*PSCREEN;
//====================user==============
void setScreenSize(PSCREEN pscreen,int cxWidth,int cyHeight);
void crdMove(PSCREEN pscreen,int x, int y);
char* creatScreen(PSCREEN pscreen);
void addStrToScreen(PSCREEN pscreen,char*str,int colorNumber);
void setColorByAddr(PSCREEN pscreen,char* addr1, char * addr2,int colorNumber);
void ctiPrint(PSCREEN pscreen);
void screenClean(PSCREEN pscreen);
//====================tool===============
int  sizeStrByByte(char* str);
char* addrByCrd(PSCREEN pscreen, int xCrd, int yCrd);//ͨ���������������ַ 
void fillCharToMemory(char* Memoryaddr,char ch,int num);

#endif
