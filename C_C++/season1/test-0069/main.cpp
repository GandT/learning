/*
  �v���O�������Ftest-0067
  ����ҁF���v�Y
  ��������F2008�N6��9���`2008�N6��9��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�f�[�^�ǂݏ����v���O����
*/
#include<stdio.h>
#define FILE_NAME "Gakusei.dat"
int main(int argc, char *argv[]){
	FILE *fp;//�t�@�C���|�C���^
	char shimei[80];//����
	int tokuten;//���_
	long offset;//�t�@�C���̓ǂݏ����ʒu
	int i;//���[�v�J�E���^�[
	
	//��������
	
	fp = fopen(FILE_NAME,"wb");
	if(fp == NULL){
		//�ُ�I��
		return 0;
	}
	printf("��������\n");
	for(i = 0;i < 3;++i){
		//�f�[�^�̓���
		printf("�����F");
		scanf("%s",shimei);
		printf("���_�F");
		scanf("%d",&tokuten);
		//��������������
		offset = (sizeof(shimei) + sizeof(tokuten) * i);
		fseek(fp,offset,0);
		fwrite(shimei,sizeof(shimei),1,fp);
		//���_����������
		offset += sizeof(shimei);
		fseek(fp,offset,0);
		fwrite(&tokuten,sizeof(tokuten),1,fp);
	}
	fclose(fp);
}