/*
  �v���O�������Ftest-0081
  ����ҁFDxLibrary
  ��������F2008�N6��18���`2008�N6��18��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�s�N�`���[�\���v���O����
*/
#include "DxLib.h"

// WinMain�֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	int GraphHandle ;

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1;

	// �O���t�B�b�N�wtest1.bmp�x���������Ƀ��[�h
	GraphHandle = LoadGraph( "Gewy001.bmp" ) ;

	// 0,0 ���W�Ƀ������ɓǂ݂��񂾃O���t�B�b�N��`��
	DrawGraph( 0 , 0 , GraphHandle , FALSE ) ;

	// �L�[���͂�҂�
	WaitKey() ;

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}