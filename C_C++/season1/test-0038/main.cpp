/*
  �v���O�������Ftest-0038
  ����ҁF�f���s
  ��������F2008�N5��18���`2008�N5��26��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
#include<windows.h>
#include<time.h>
long main(){
	long testa=0;
	srand((unsigned)time(NULL));
	testa=rand()%1001;
	while(testa!=1000){
		printf("%d\n",testa);
		testa++;
		Sleep(100);
	}
	printf("�͂��A�I���I");
	Sleep(2000);
	return 0;
}