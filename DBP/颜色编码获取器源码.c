#include <windows.h> 
#include <winnt.h> 
#include <stdio.h> 
int color3[7] = {0,1,2,4,16,32,64};
//背景颜色组合
int bcolor[8] = {0,16,32,48,64,80,96,112};
int fcolor[8] = {0,1,2,3,4,5,6,7};
 
int main(int argc, char* argv[]) 
{ 
HANDLE consolehwnd; 
consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE); 
int i,j,num; 
int k = 0;
printf("===============颜色编码表===============\n");
SetConsoleTextAttribute(consolehwnd,1+8+1024);
printf("加上划线请在编码的基础上 + 1024\n");
SetConsoleTextAttribute(consolehwnd,1+8+2048);
printf("加左划线请在编码的基础上 + 2048\n");
SetConsoleTextAttribute(consolehwnd,1+8+4096);
printf("加右划线请在编码的基础上 + 4096\n");
 SetConsoleTextAttribute(consolehwnd,1+2+4+8);
printf("\n===============无高亮系===============\n");
k = 0;
for(i = 0; i < 8; i++)
{
	for(j = 0; j < 8; j++)
	{
			SetConsoleTextAttribute(consolehwnd,bcolor[i]+fcolor[j]);
			printf("测试文字");
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
printf("===============前景高亮系===============\n");
k = 0;
for(i = 0; i < 8; i++)
{
	for(j = 0; j < 8; j++)
	{
			SetConsoleTextAttribute(consolehwnd,bcolor[i]+fcolor[j] + 8);
			printf("测试文字");
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
printf("\n===============背景高亮系===============\n");

k = 0;
for(i = 0; i < 8; i++)
{
	for(j = 0; j < 8; j++)
	{
			SetConsoleTextAttribute(consolehwnd,bcolor[i]+fcolor[j] + 128);
			printf("测试文字");
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
printf("\n===============全高亮系===============\n");
k = 0;
for(i = 0; i < 8; i++)
{
	for(j = 0; j < 8; j++)
	{
			SetConsoleTextAttribute(consolehwnd,bcolor[i]+fcolor[j]+128+8);
			printf("测试文字");
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
