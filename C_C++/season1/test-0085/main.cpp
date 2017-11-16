/*
  �v���O�������Ftest-0085
  ����ҁFDxLibrary
  ��������F2008�N6��18���`2008�N6��18��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�L�[�{�[�h���̓v���O����
*/
#include "DxLib.h"

// WinMain�֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine, int nCmdShow )
{
	int BallX , BallY , BallGraph ;
	int SikakuX , SikakuY , SikakuMuki , SikakuGraph ;

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode( 640 , 480 , 16 ) ;

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1;

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// �{�[���N�̃O���t�B�b�N���������Ƀ��[�h���\�����W���Z�b�g
	BallGraph = LoadGraph( "Gewy001.bmp" ) ;
	BallX = 288 ; BallY = 400 ;

	// �l�p�N�̃O���t�B�b�N���������Ƀ��[�h���\�����W���Z�b�g
	SikakuGraph = LoadGraph( "�G���L�V���[�^�[.bmp" ) ;
	SikakuX = 0 ; SikakuY = 50 ;

	// �l�p�N�̈ړ��������Z�b�g
	SikakuMuki = 1 ;

	// �ړ����[�`��
	while( 1 )
	{
		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen() ;

		// �{�[���N�̑��샋�[�`��
		{
			// ���L�[�������Ă�����{�[���N����Ɉړ�������
			if( CheckHitKey( KEY_INPUT_UP ) == 1 ) BallY -= 1 ;

			// ���L�[�������Ă�����{�[���N�����Ɉړ�������
			if( CheckHitKey( KEY_INPUT_DOWN ) == 1 ) BallY += 1 ;

			// ���L�[�������Ă�����{�[���N�����Ɉړ�������
			if( CheckHitKey( KEY_INPUT_LEFT ) == 1 ) BallX -= 1 ;

			// ���L�[�������Ă�����{�[���N���E�Ɉړ�������
			if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 ) BallX += 1 ;

			// �{�[���N����ʍ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if( BallX < 0 ) BallX = 0 ;

			// �{�[���N����ʉE�[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if( BallX > 640 - 64 ) BallX = 640 - 64  ;

			// �{�[���N����ʏ�[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if( BallY < 0 ) BallY = 0 ;

			// �{�[���N����ʉ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
			if( BallY > 480 - 64 ) BallY = 480 - 64 ;

			// �{�[���N��`��
			DrawGraph( BallX , BallY , BallGraph , true ) ;
		}


		// �l�p�N�̈ړ����[�`��
		{
			// �l�p�N�̍��W���ړ����Ă�������Ɉړ�����
			if( SikakuMuki == 1 ) SikakuX += 1 ;
			if( SikakuMuki == 0 ) SikakuX -= 1 ;

			// �l�p�N����ʉE�[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
			if( SikakuX > 576 )
			{
				SikakuX = 576 ;
				SikakuMuki = 0 ;
			}
			// �l�p�N����ʍ��[����ł����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă����A�ړ�������������]����
			if( SikakuX < 0 )
			{
				SikakuX = 0 ;
				SikakuMuki = 1 ;
			}

			// �l�p�N��`��
			DrawGraph( SikakuX , SikakuY , SikakuGraph ,true ) ;
		}

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip() ;


		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if( ProcessMessage() < 0 ) break ;

		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break ;
	}

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;					// �\�t�g�̏I��
}


