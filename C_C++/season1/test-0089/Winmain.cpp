/*
  �v���O�������Ftest-0089
  ����ҁFDxLibrary
  ��������F2008�N6��19���`2008�N6��19��
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
	int ShotX , ShotY , ShotFlag , ShotGraph ;

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
	SikakuGraph = LoadGraph( "�w�i�P.bmp" ) ;
	SikakuX = 0 ; SikakuY = 0 ;

	// �e�̃O���t�B�b�N���������Ƀ��[�h
	ShotGraph = LoadGraph( "Gewy�̒e�A.bmp" ) ;

	// �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����O�������Ă���
	ShotFlag = 0 ;

	// �l�p�N�̈ړ��������Z�b�g
	SikakuMuki = 1 ;

	// �ړ����[�`��
	while( 1 )
	{
		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen() ;
				// �l�p�N�̈ړ����[�`��
		{
			// �l�p�N�̍��W���ړ����Ă�������Ɉړ�����
			if( SikakuMuki == 1 ) SikakuX += 0 ;
			if( SikakuMuki == 0 ) SikakuX -= 0 ;

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
			DrawGraph( SikakuX , SikakuY , SikakuGraph , true ) ;
		}

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

			// �X�y�[�X�L�[�������Ă��āA���e�������o����Ă��Ȃ�������e�𔭎˂���
			if( CheckHitKey( KEY_INPUT_SPACE ) == 1 && ShotFlag == 0 )
			{
				int Bw, Bh, Sw, Sh ;

				// �{�[���N�ƒe�̉摜�̃T�C�Y�𓾂�
				GetGraphSize( BallGraph , &Bw , &Bh ) ;
				GetGraphSize( ShotGraph , &Sw , &Sh ) ;

				// �e�̈ʒu���Z�b�g�A�ʒu�̓{�[���N�̒��S�ɂ���
				ShotX = ( Bw - Sw ) / 2 + BallX ;
				ShotY = ( Bh - Sh ) / 2 + BallY ;

				// �e�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ��ɂP��������
				ShotFlag = 1 ;
			}

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

		// ���@�̒e�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e���P(���݂���)�̏ꍇ�̂ݍs�� )
		if( ShotFlag == 1 )
		{
			// �e���P�U�h�b�g��Ɉړ�������
			ShotY -= 16 ;

			// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ��ɂO(���݂��Ȃ�)��������
			if( ShotY < -80 )
			{
				ShotFlag = 0 ;
			}

			// ��ʂɒe��`�悷��
			DrawGraph( ShotX , ShotY , ShotGraph , true ) ;
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

