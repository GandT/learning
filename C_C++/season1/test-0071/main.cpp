/*
  �v���O�������Ftest-0071
  ����ҁF�f���s
  ��������F2008�N6��11���`2008�N6��911��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�������x�v���v���O����
*/
#include<stdio.h>
#include<time.h>
int main(){
	int test1,test2,test3;
//	printf("�������x�v���v���O������\n");
	for(test1 = 0;test1 < 200000000;test1++){
	}
	test2 = clock();
	test1 = 0;
	for(test1 = 0;test1 < 200000000;++test1){
	}
	test3 = clock();
	test3 -= test2;
//	test2 /= 1000;
//	test3 /= 1000;
	printf("test++�̏ꍇ�c%d\n++test�̏ꍇ�c%d\n",test2,test3);
	return 0;
}
//�Ȃ񂩎��s���ʂ����傭���傭�ς��