/*
  �v���O�������Ftest-0062
  ����ҁFDxLibrary
  ��������F2008�N6��5���`2008�N6��5��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�摜�\���v���O����
*/
#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
			 LPSTR lpCmdLine, int nCmdShow )
{
	int i ;
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1 ;


	// ��ԍ���ɊG��\���A�Q�O���̂P�b�҂A���P�R��J��Ԃ�
	for( i = 0 ; i < 80 ; i ++ )
	{
		// �G��\���A�G��`���w���W�� i ���P�����邲�ƂɂP�O�h�b�g�ÂE�ɂ���Ă䂭
		LoadGraphScreen( i * 10 , 100 , "test1.bmp" , FALSE ) ;

		// �Q�O���̂P�b�҂�
		WaitTimer( 50 ) ;
	}

	// �L�[�̓��͑҂�
	WaitKey() ;


	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}

