#include <stdio.h>
#include "ctioutput.h"


//注意:
//1.本系统的坐标系统原点为窗口左上角 向下为y向右为x
//2.窗口宽度和高度是从1开始计算(而不是0) 请不要与坐标系统混淆! 

int main(int argc, char** argv) {
	LIST cl;
	SCREEN sc;
	setScreenSize(&sc,80,15);
	creatScreen(&sc);
	SetConsoleTitle("输出模块测试程序"); 
	//追加测试 : 完美 
	addStrToScreen(&sc,"色彩缤纷,随心所欲",28);
	addStrToScreen(&sc,"呵呵呵",46);
	addStrToScreen(&sc,"这是测试文字",10);
	addStrToScreen(&sc,"这是测试文字",10);
	addStrToScreen(&sc,"已知的最后一个bug\n调试完成!",15);
	//覆盖测试 : 使用一个字母覆盖中文 会造成乱码! 此问题很难解决 = = 
	sc.xCrd = 0;
	sc.yCrd = 0;
	addStrToScreen(&sc,"色彩缤纷,随心所欲a ",29);
	//清屏测试 :  
	screenClean(&sc);
	addStrToScreen(&sc,"这是测试文字,清屏后将显示本文本",10);
	//printf("%s",sc.screen);
	//清屏综合测试 
	int i = 0;
	while(1)
	{
		if(i == 100)
		{
			i = 0;
			break; 
		}
		if(i%2 == 0)
		{
			addStrToScreen(&sc,"色彩缤纷,随心所欲",28);
		}
		else
		{
			addStrToScreen(&sc,"高速清屏,杜绝闪烁",10);
		}
		
	 	ctiPrint(&sc);
	 	Sleep(200); 
	 	screenClean(&sc);
	 	i++;
	}

	return 0;
}
