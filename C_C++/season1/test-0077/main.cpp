/*
  �v���O�������Ftest-0077
  ����ҁF�f���s
  ��������F2008�N6��14���`2008�N6��14��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF���Z�v���O����
*/
#include<stdio.h>
#include<time.h>
int main(){
	unsigned __int64 test1 = 0,test2;
	while(test1 != 4200000000){
	if(test1%1000000==0)printf("%d\n",test1);
	++test1;
	
	}
	test2 = clock();
	test2 /= 1000;
	printf("\n\n�I���܂łɂ����������ԁc%d",test2);
}