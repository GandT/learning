/*
  �v���O�������Ftest-0061
  ����ҁFDxLibrary
  ��������F2008�N6��5���`2008�N6��5��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�摜�\���v���O����
*/
#include<stdio.h>
#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	// �c�w���C�u����������
	if( DxLib_Init() == -1 ) return -1 ;


	// ��ʂɊG��\��
	LoadGraphScreen(120,156,"test1.bmp",FALSE);

	// �L�[�̓��͑҂�
	WaitKey();


	// �c�w���C�u�����g�p�̏I��
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}
