/*
  �v���O�������Ftest-0055
  ����ҁF�f���s
  ��������F2008�N5��31���`2008�N5��31��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�_���v�v���O����
*/
#include<stdio.h>
#define SIZE 200
int main(int argc, char* argv[]){
	FILE *fp_dmp;//�_���v�p�t�@�C���|�C���^
	int file_size;//�t�@�C���T�C�Y
	int buf;//�f�[�^�u����
	FILE *fp_result;//�������ݗp�t�@�C���|�C���^
	char line_buf[SIZE];//�������ւ̏�������
	file_size = 0;
	fp_dmp = fopen("th07.exe","rb");
	if(fp_dmp==NULL){
		return -1;	
	}
	fp_result = fopen("data.txt","wt");
	if(fp_result==NULL)return -1;
	while(1){
		buf = fgetc(fp_dmp);
		if(buf == EOF){
			break;
		}
		++file_size;
		printf("%02x",buf);
		sprintf(line_buf,"0x%x ",buf);
//		line_buf = buf;
		fputs(line_buf,fp_result);
		if(file_size % 16 == 0){
			printf("\n");
			fputs("\n",fp_result);
		}
	}
	fclose(fp_result);
	fclose(fp_dmp);
	return 0;
}
