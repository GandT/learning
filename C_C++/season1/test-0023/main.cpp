/*
  �v���O�������Ftest-0023
  ����ҁF�f���s
  ��������F2008�N5��15���`2008�N5��24��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�M�����u���v���O����
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int main(){
	int test1,test2;
	test2=0;
	srand((unsigned)time(NULL));
	printf("100���ł���I�������I\n����ŏI�����邩�ŃM�����u���ł�����΁H\n");
	while(test1!=100){
		test1=rand()%101;
		printf("�����������c%d\n",test1);
		test2++;
		Sleep(100);
	}
	printf("�v���I���I\n");
	Sleep(1000);
	printf("\n�S���ł�܂łɂ��������񐔁c%d��\n���肪�Ƃ��������܂���\n�܂������p��������\n",test2);
	Sleep(5000);
	return 0;
}