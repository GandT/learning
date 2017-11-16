/*
  �v���O�������Ftest-0084
  ����ҁFDxLibrary
  ��������F2008�N6��18���`2008�N6��18��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�L�[�{�[�h���̓v���O����
*/
#include "DxLib.h"

// WinMain�֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	int BallX , BallY , BallGraph ;
	int SikakuX , SikakuY , SikakuGraph ;
	int i ;

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode( 640 , 480 , 16 ) ;

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1;

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// �{�[���N�̃O���t�B�b�N���������Ƀ��[�h���\�����W���Z�b�g
	BallGraph = LoadGraph( "�G���L�V���[�^�[.bmp" ) ;
	BallX = -32 ; BallY = 10 ;

	// �l�p�N�̃O���t�B�b�N���������Ƀ��[�h���\�����W���Z�b�g
	SikakuGraph = LoadGraph( "�R���N�^�[.bmp" ) ;
	SikakuX = 540 ; SikakuY = 400 ;

	// �ړ����[�`��
	for( i = 0 ; i < 400 ; i ++ )
	{
		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen() ;

		// �{�[���N�̍��W���������炷
		BallX += 1 ;

		// �{�[���N��`��
		DrawGraph( BallX , BallY , BallGraph , true ) ;

		// �l�p�N�̍��W���������炷
		SikakuX -= 1 ;
		SikakuY -= 1 ;

		// �l�p�N��`��
		DrawGraph( SikakuX , SikakuY , SikakuGraph , true ) ;

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip() ;

		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if( ProcessMessage() < 0 ) break;
	}
	WaitTimer(5000);

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}


