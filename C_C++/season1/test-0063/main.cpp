/*
  �v���O�������Ftest-0062
  ����ҁFDxLibrary
  ��������F2008�N6��5���`2008�N6��5��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�摜�\���v���O����
*/
#include<stdio.h>
#include "DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	if( DxLib_Init() == -1 ) return -1 ;
	printf("#include<stdio.h>");
	WaitKey();
	return 0;
}