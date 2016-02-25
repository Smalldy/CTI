#ifndef _CTIOUTPUT_H_
#define _CTIOUTPUT_H_
#include "strcolorsys.h"
#include <windows.h> 
#include <wincon.h> 
typedef struct screen
{
	int width;//宽度 
	int height;//高度
	int xCrd;
	int yCrd;//光标坐标 
	char* screen; 
	LIST list; //颜色表 
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
char* addrByCrd(PSCREEN pscreen, int xCrd, int yCrd);//通过光标计算待操作地址 
void fillCharToMemory(char* Memoryaddr,char ch,int num);

#endif
