/*
  �v���O�������Ftest-0082
  ����ҁFDxLibrary
  ��������F2008�N6��18���`2008�N6��18��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�s�N�`���[�\���v���O����
*/
#include "DxLib.h"

// WinMain�֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1;

	// 0,0 ���W�ɃO���t�B�b�N�wtest1.bmp�x��`��
	LoadGraphScreen( 0 , 0 , "Gewy001.bmp" , FALSE ) ;

	// �L�[���͂�҂�
	WaitKey() ;

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}

