/*
  �v���O�������Ftest-0072
  ����ҁF�f���s
  ��������F2008�N6��11���`2008�N6��911��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF���Z�v���O����
*/
#include<stdio.h>
int Gtest(int g){
	int g2;
	g2 = g % 2;
	return g2;
}
int main(){
	int test1,test2;
	printf("�������ǂ������f���������������Ă�������");
	scanf("%d",&test1);
	test2 = Gtest(test1);
	if(test2 == 0){
		printf("���͂��ꂽ�����͋����ł�");
	} else {
		printf("���͂��ꂽ�����͊�ł�");
	}
	return 0;
}