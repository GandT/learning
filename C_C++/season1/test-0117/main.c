/*
  �v���O�������Ftest-0117
  ����ҁF�f���s
  ��������F2011�N8��4��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�t�@�C���o���̓v���O����
*/

#include "stdio.h"


int main()
{
	//�t�@�C���ۂ��񂽂�U������Ȃ���
	FILE *file = fopen("�ǂ�.txt","r");
	int moji;						//�������A�����ł��o�͂��悤����Ȃ���

	//�ʂ�ۂ�������
	if(file == NULL){
		
		//�A��A��[�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O
		printf("���A�艺����");
		
		return -1;
		
	}
	
	//���āA�ǂݍ��߂��킯����
	
	moji = fgetc(file);
	printf("�u%c�v���ēǂ߂܂����[�͂��͂��́[�n������Ȃ��̌N�[�[�[�[�[�O�|�O�|�O�|�O�|�O�|�O",moji);
	
	//����
	fclose(file);
	
	return 0;
	
}