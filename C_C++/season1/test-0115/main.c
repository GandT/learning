/*
  �v���O�������Ftest-0115
  ����ҁF�f���s
  ��������F2011�N8��4��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�t�@�C���o���̓v���O����
*/

#include "stdio.h"

int main()
{
	//�t�@�C�����J��
	FILE *file = fopen("test.txt","r");
	
	//�G���[���o�Ă��̂��Ȃǂ��Ȃ̂���
	if(file == NULL){
		
		printf("�t�@�C���Ȃ�ĂȂ�����");
		
	}else {
		
		printf("�t�@�C����������܂����O�|�O�|�O�|�O�|�O�|�O�|�O");
		
		//�������������Ă�낤�ł͂Ȃ���
		fclose(file);
		
		printf("\n\n\n\n\n\n\n\n\n\n���Ă�������O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O");
		
	}
	
	//���[����
	return 0;
	
}