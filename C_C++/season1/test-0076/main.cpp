/*
  �v���O�������Ftest-0076
  ����ҁFDxLibrary
  ��������F2008�N6��14���`2008�N6��14��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF���Z�v���O����
*/
#include "Dxlib.h"
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						 LPSTR lpCmdLine, int nCmdShow ){
	int i ;

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1 ;

	// �`���𗠉�ʂɂ���
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// ��ԍ���ɊG��\���A�Q�O���̂P�b�҂A���P�R��J��Ԃ�
	for( i = 0 ; i < 45 ; i ++ )
	{
		// ��ʂɕ`����Ă�����̂����S������
		ClearDrawScreen() ;

		// �G��\��
		LoadGraphScreen( i * 10 , 100 , "chaos2.bmp" , FALSE ) ;

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip() ;

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