/*
  �v���O�������Ftest-0042
  ����ҁF�f���s
  ��������F2008�N5��20���`2008�N5��26��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include<stdio.h>
#include<string.h>
int main(){
	int test1,test2;
	char test3[49];
	printf("�e�L�g�[�ɐ������Ԃ�����\n");
	scanf("%d",&test1);
	if(test1==0){
		test2=57;
		strcpy(test3,"������`��");
	}else if(test1<0){
		test2=36598;
		strcpy(test3,"������������`�`��");
	}else if(test1<-657){
		test2=89;
		strcpy(test3,"�֐{�q���׉䗘�q");
	}else if(test1<-3656){
		test2=327;
		strcpy(test3,"jut,xjgrely");
	}else if(test1>0){
		test2=-8947;
		strcpy(test3,"�Â��݂Ⴂ����");
	}else if(test1>74){
		test2=987;
		strcpy(test3,"hahhahhaninatta");
	}else if(test1>945){
		test2=-9456;
		strcpy(test3,"�킠���`�`");
	}
	printf("\n%d%s",test2,test3);
	return 0;
}