/*
  �v���O�������Ftest-0122
  ��������F2011�N8��20��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�����m�F�v���O����
*/

#include "stdio.h"

#define Null(X)		if(X == NULL)


void main()
{
	int a = 0;
	int *p = NULL;
	
	//p = &a;
	
	Null(p)puts("�ʂ��"); else puts("�K�b�I");
}