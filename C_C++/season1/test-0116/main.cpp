/*
  �v���O�������Ftest-0116
  ����ҁF�f���s
  ��������F2011�N8��4��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�t�@�C���o���̓v���O����
*/

#include "stdio.h"

int main()
{
	//�t�@�C���ǂݍ��݂̂�����
	FILE *file = fopen("�ӂ��邾/test.txt","r");
	
#if 0
	���������������ǂ���uFILE *file = fopen("�ӂ��邾\\test.txt","r");�v�ł������̂恦��������
#endif

	//���ɂǂ߂ȂȂ̂ł��߂�Ƃ͂����Ȃ��̂ł���
	if(file == NULL){
		
		puts("�i�@�E�́E�j < �t�@�C�����~�����Ȃ玩���ō�邱�Ƃ���");
		
		return -1;
	}
	
	printf("�y�@�E�́E�z < �킴�킴�t�@�C����p�ӂ��Ă��ꂽ�N�ɂ͓��ʂɂ���printf�������悤����Ȃ������h�Ɏv��\n\n\n\n\n\n\n\n\n\n\n");
	
	fclose(file);
	
	puts("���[���A�P���P���O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O�|�O");
	
	return 0;
	
}