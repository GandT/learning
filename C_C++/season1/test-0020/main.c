/*
  �v���O�������Ftest-0019
  ����ҁF�f���s
  ��������F2008�N5��13���`�N����
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF���Z�v���O����
*/
#include<stdio.h>
#include<windows.h>
tester(int a,int b);
int main(){
	int mono;
	char c,d;
	kokonattu:
	printf("�ꕶ���ځ�");
	scanf("%d",c);
	printf("\n�񕶎��ځ�");
	scanf("%d",d);
	mono=tester(c,d);
	printf("�A���Ă������%d",mono);
	Sleep(5000);
	printf("���Ă�����x");
	goto kokonattu;
}
tester(int a,int b){
	int testaning;
	printf("\n%d\n%d",a,b);
	testaning=a+b;
	testaning++;
	return testaning;
}