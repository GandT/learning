/*
  �v���O�������Ftest-0008
  ��������F2008�N5��8���`2008�N5��8��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�Fscanf�e�X�g
*/
#include <stdio.h>
int main(){
	int gt1;
	majick:
	printf("��������͂��Ă�������\n���͂���������");
	scanf("%d",&gt1);
	printf("���Ȃ������͂���������%d�ł���",gt1);
	goto majick;
	return 0;
}