#ifndef _STRCOLORSYS_H_
#define _STRCOLORSYS_H_
#include "list.h"
#include <stdio.h>
//=============�ַ�����ɫ����ϵͳ============
//�û����� 
void addStrColorAddr(LIST * list,char* addr1, char* addr2,int colorNumber);
void reSet(LIST* list,char* addr1, char* addr2, int colorNumber);
void delList(LIST* list);
//���ߺ���
/**
*�˺���Ϊ�û�����addStrColorAddrֱ�ӷ���
*����:���һ����� 
*addr ��addr������ĵ�ַ��ĳ����� ����addrΪ���� ����Ǹ���� ��Ϊ������� 
*���� ����ֵĽ�� 
*/ 
PCOLORNODE splitNode(LIST* list,char* addr);
/**
*�˺���Ϊ�û�����addStrColorAddrֱ�ӷ���
*����:�ϲ�����ָ���Ľ�� ��ɫ�����޸�Ϊ����ָ������ɫ 
*����Ҫ��:addr1����Ϊĳһ�ڵ��startAddr addr2����Ϊ��һ������endAddr 
*/
void mergeNode(LIST* list,char* addr1,char* addr2, int colorNumber); 


#endif
