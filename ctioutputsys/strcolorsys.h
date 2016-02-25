#ifndef _STRCOLORSYS_H_
#define _STRCOLORSYS_H_
#include "list.h"
#include <stdio.h>
//=============字符串颜色控制系统============
//用户函数 
void addStrColorAddr(LIST * list,char* addr1, char* addr2,int colorNumber);
void reSet(LIST* list,char* addr1, char* addr2, int colorNumber);
void delList(LIST* list);
//工具函数
/**
*此函数为用户函数addStrColorAddr直接服务
*功能:拆分一个结点 
*addr 若addr所代表的地址在某结点内 则以addr为界限 拆分那个结点 成为两个结点 
*返回 被拆分的结点 
*/ 
PCOLORNODE splitNode(LIST* list,char* addr);
/**
*此函数为用户函数addStrColorAddr直接服务
*功能:合并参数指定的结点 颜色都被修改为参数指定的颜色 
*参数要求:addr1必须为某一节点的startAddr addr2必须为下一个结点的endAddr 
*/
void mergeNode(LIST* list,char* addr1,char* addr2, int colorNumber); 


#endif
