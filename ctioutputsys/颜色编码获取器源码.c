#include <windows.h> 
#include <winnt.h> 
#include <stdio.h> 
int color3[7] = {0,1,2,4,16,32,64};
//������ɫ���
int bcolor[8] = {0,16,32,48,64,80,96,112};
int fcolor[8] = {0,1,2,3,4,5,6,7};
 
int main(int argc, char* argv[]) 
{ 
HANDLE consolehwnd; 
consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
int i,j,num; 
int k = 0;
printf("===============��ɫ�����===============\n");
SetConsoleTextAttribute(consolehwnd,1+8+1024);
printf("���ϻ������ڱ���Ļ����� + 1024\n");
SetConsoleTextAttribute(consolehwnd,1+8+2048);
printf("���������ڱ���Ļ����� + 2048\n");
SetConsoleTextAttribute(consolehwnd,1+8+4096);
printf("���һ������ڱ���Ļ����� + 4096\n");
 SetConsoleTextAttribute(consolehwnd,1+2+4+8);
printf("\n===============�޸���ϵ===============\n");
k = 0;
for(i = 0; i < 8; i++)
{
	for(j = 0; j < 8; j++)
	{
			SetConsoleTextAttribute(consolehwnd,bcolor[i]+fcolor[j]);
			printf("��������");
			SetConsoleTextAttribute(consolehwnd,1+2+4+8);
			printf("=%4d   ",bcolor[i]+fcolor[j]);
			k++;
			if(k%4 == 0)
			{
				printf("\n");
			}
	}
} 

SetConsoleTextAttribute(consolehwnd,1+2+4+8);
printf("===============ǰ������ϵ===============\n");
k = 0;
for(i = 0; i < 8; i++)
{
	for(j = 0; j < 8; j++)
	{
			SetConsoleTextAttribute(consolehwnd,bcolor[i]+fcolor[j] + 8);
			printf("��������");
			SetConsoleTextAttribute(consolehwnd,1+2+4+8);
			printf("=%4d   ",bcolor[i]+fcolor[j] + 8);
			k++;
			if(k%4 == 0)
			{
				printf("\n");
			}
	}
} 

SetConsoleTextAttribute(consolehwnd,1+2+4+8);
printf("\n===============��������ϵ===============\n");

k = 0;
for(i = 0; i < 8; i++)
{
	for(j = 0; j < 8; j++)
	{
			SetConsoleTextAttribute(consolehwnd,bcolor[i]+fcolor[j] + 128);
			printf("��������");
			SetConsoleTextAttribute(consolehwnd,1+2+4+8);
			printf("=%4d   ",bcolor[i]+fcolor[j] + 128);
			k++;
			if(k%4 == 0)
			{
				printf("\n");
			}
	}
} 
SetConsoleTextAttribute(consolehwnd,1+2+4+8);
printf("\n===============ȫ����ϵ===============\n");
k = 0;
for(i = 0; i < 8; i++)
{
	for(j = 0; j < 8; j++)
	{
			SetConsoleTextAttribute(consolehwnd,bcolor[i]+fcolor[j]+128+8);
			printf("��������");
			SetConsoleTextAttribute(consolehwnd,1+2+4+8);
			printf("=%4d   ",bcolor[i]+fcolor[j]+128+8);
			k++;
			if(k%4 == 0)
			{
				printf("\n");
			}
	}
} 

	system("pause"); 
return 0; 
} 
