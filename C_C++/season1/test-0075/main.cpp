/*
  �v���O�������Ftest-0075
  ����ҁF�f���s�AJohn
  ��������F2008�N6��11���`2008�N6��11��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF���Z�v���O����
*/
#include<stdio.h>
int kouyakusuu(int y1,int y2){
	int count/*for���J�E���^�[*/,kakunou1/*y1���������*/,kakunou2/*y2���������*/,save/*�������f*/,memo = 0,kiroku;
	if(y1>y2){
		save = y1;
		kiroku = 0;
	} else if(y1 < y2){
		save = y2;
		kiroku = 1;
	} else{
		return y1;
	}
	for(count = 1/*�������萔*/;;++count){
		kakunou1 = (y1 % count);
		kakunou2 = (y2 % count);
		if(kakunou1 == kakunou2){
			if(kakunou1 == 0) memo = count;
			}
			if(count > y1+y2) break;
		}
	return memo;
}
int main(){
	int test1,test2,test3;
	printf("�ő���񐔂����߂�����������͓���Ă�������\n��ځ�");
	scanf("%d",&test1);
	printf("��ځ�");
	scanf("%d",&test2);
	test3 = kouyakusuu(test1,test2);
	printf("�ő���񐔁�%d",test3);
	return 0;
}