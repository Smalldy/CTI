#include <stdio.h>
#include "ctioutput.h"


//ע��:
//1.��ϵͳ������ϵͳԭ��Ϊ�������Ͻ� ����Ϊy����Ϊx
//2.���ڿ�Ⱥ͸߶��Ǵ�1��ʼ����(������0) �벻Ҫ������ϵͳ����! 

int main(int argc, char** argv) {
	LIST cl;
	SCREEN sc;
	setScreenSize(&sc,80,15);
	creatScreen(&sc);
	SetConsoleTitle("���ģ����Գ���"); 
	//׷�Ӳ��� : ���� 
	addStrToScreen(&sc,"ɫ���ͷ�,��������",28);
	addStrToScreen(&sc,"�ǺǺ�",46);
	addStrToScreen(&sc,"���ǲ�������",10);
	addStrToScreen(&sc,"���ǲ�������",10);
	addStrToScreen(&sc,"��֪�����һ��bug\n�������!",15);
	//���ǲ��� : ʹ��һ����ĸ�������� ���������! ��������ѽ�� = = 
	sc.xCrd = 0;
	sc.yCrd = 0;
	addStrToScreen(&sc,"ɫ���ͷ�,��������a ",29);
	//�������� :  
	screenClean(&sc);
	addStrToScreen(&sc,"���ǲ�������,��������ʾ���ı�",10);
	//printf("%s",sc.screen);
	//�����ۺϲ��� 
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
			addStrToScreen(&sc,"ɫ���ͷ�,��������",28);
		}
		else
		{
			addStrToScreen(&sc,"��������,�ž���˸",10);
		}
		
	 	ctiPrint(&sc);
	 	Sleep(200); 
	 	screenClean(&sc);
	 	i++;
	}

	return 0;
}
