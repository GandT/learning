/*
  �v���O�������Ftest-0105
  ����ҁFDxLibrary�A�f���s
  ��������F2008�N7��16���`2008�N7��16��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include"DxLib.h"
#include "DxLib.h"

// WinMain�֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine, int nCmdShow )
{
	int BallX , BallY , BallGraph ;
	int SikakuX , SikakuY , SikakuMuki , SikakuGraph ;
	int Shot1X , Shot1Y , Shot1Flag , ShotGraph ;
	int Shot2X , Shot2Y , Shot2Flag ;

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode( 640 , 480 , 16 ) ;
//	ChangeWindowMode(1);
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,255);

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// �{�[���N�̃O���t�B�b�N���������Ƀ��[�h���\�����W���Z�b�g
	BallGraph = LoadGraph( "Gewy001.png" ) ;
	BallX = 288 ; BallY = 400 ;

	// �l�p�N�̃O���t�B�b�N���������Ƀ��[�h���\�����W���Z�b�g
	SikakuGraph = LoadGraph( "�C���Z�N�g�{�b�N�X.png" ) ;
	SikakuX = 0 ; SikakuY = 50 ;

	// �e�̃O���t�B�b�N���������Ƀ��[�h
	ShotGraph = LoadGraph( "Gewy�̒e�@.png" ) ;
	
	//�w�i�ǂݍ���
	int bh = LoadGraph("�w�i�Q.bmp");

	// �e�P�E�Q����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����O�������Ă���
	Shot1Flag = 0 ;
	Shot2Flag = 0 ;

	// �l�p�N�̈ړ��������Z�b�g
	SikakuMuki = 1 ;

	// �ړ����[�`��
	while( 1 )
	{
		//�e�o�r�R���g���[��
		static float a,b;//��������
		b = a;
		while(GetNowCount() - b <16)Sleep(0);
		a = GetNowCount();
		clsDx();
		printfDx("FPS::%f\n",1000/(a-b));//�����܂�
		
		
		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen() ;
		
		//�w�i�`��
		DrawGraph( 0 , 0 , bh , true ) ;

		// �{�[���N�̑��샋�[�`��
		{
			// ���L�[�������Ă�����{�[���N����Ɉړ�������
			if( CheckHitKey( KEY_INPUT_UP ) == 1 ) BallY -= 3 ;

			// ���L�[�������Ă�����{�[���N�����Ɉړ�������
			if( CheckHitKey( KEY_INPUT_DOWN ) == 1 ) BallY += 3 ;

			// ���L�[�������Ă�����{�[���N�����Ɉړ�������
			if( CheckHitKey( KEY_INPUT_LEFT ) == 1 ) BallX -= 3 ;

			// ���L�[�������Ă�����{�[���N���E�Ɉړ�������
			if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 ) BallX += 3 ;

			// Z���X�y�[�X�L�[���������ꍇ�͏����𕪊�
			if( CheckHitKey( KEY_INPUT_Z ) || CheckHitKey(KEY_INPUT_SPACE))
			{
				if( Shot1Flag == 0 )
				{
					// �e�P����ʂɑ��݂��Ă��Ȃ��ꍇ�͒e�P���o��

					int Bw, Bh, Sw, Sh ;

					// �{�[���N�ƒe�̉摜�̃T�C�Y�𓾂�
					GetGraphSize( BallGraph , &Bw , &Bh ) ;
					GetGraphSize( ShotGraph , &Sw , &Sh ) ;

					// �e�P�̈ʒu���Z�b�g�A�ʒu�̓{�[���N�̒��S�ɂ���
					Shot1X = ( Bw - Sw ) / 2 + BallX ;
					Shot1Y = ( Bh - Sh ) / 2 + BallY ;

					// �e�P�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ��ɂP��������
					Shot1Flag = 1 ;
				}
				else if( Shot2Flag == 0 )
				{
					// �e�Q����ʂɑ��݂��Ă��Ȃ��ꍇ�͒e�Q���o��

					int Bw, Bh, Sw, Sh ;

					// �{�[���N�ƒe�̉摜�̃T�C�Y�𓾂�
					GetGraphSize( BallGraph , &Bw , &Bh ) ;
					GetGraphSize( ShotGraph , &Sw , &Sh ) ;

					// �e�Q�̈ʒu���Z�b�g�A�ʒu�̓{�[���N�̒��S�ɂ���
					Shot2X = ( Bw - Sw ) / 2 + BallX ;
					Shot2Y = ( Bh - Sh ) / 2 + BallY ;

					// �e�Q�͌����_�������đ��݂���̂ŁA���ݏ�Ԃ�ێ�����ϐ��ɂP��������
					Shot2Flag = 1 ;
				}
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

		// ���@�̒e�P�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e���P(���݂���)�̏ꍇ�̂ݍs�� )
		if( Shot1Flag == 1 )
		{
			// �e�P���P�U�h�b�g��Ɉړ�������
			Shot1Y -= 16 ;

			// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ��ɂO(���݂��Ȃ�)��������
			if( Shot1Y < -80 )
			{
				Shot1Flag = 0 ;
			}

			// ��ʂɒe�P��`�悷��
			DrawGraph( Shot1X , Shot1Y , ShotGraph , true ) ;
		}

		// ���@�̒e�Q�̈ړ����[�`��( ���ݏ�Ԃ�ێ����Ă���ϐ��̓��e���P(���݂���)�̏ꍇ�̂ݍs�� )
		if( Shot2Flag == 1 )
		{
			// �e�Q���P�U�h�b�g��Ɉړ�������
			Shot2Y -= 16 ;

			// ��ʊO�ɏo�Ă��܂����ꍇ�͑��ݏ�Ԃ�ێ����Ă���ϐ��ɂO(���݂��Ȃ�)��������
			if( Shot2Y < -80 )
			{
				Shot2Flag = 0 ;
			}

			// ��ʂɒe�Q��`�悷��
			DrawGraph( Shot2X , Shot2Y , ShotGraph , true ) ;
		}


		// �l�p�N�̈ړ����[�`��
		{
			// �l�p�N�̍��W���ړ����Ă�������Ɉړ�����
			if( SikakuMuki == 1 ) SikakuX += 3 ;
			if( SikakuMuki == 0 ) SikakuX -= 3 ;

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

		// ����ʂ̓��e��\��ʂɃR�s�[����
		ScreenFlip() ;


		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// -1 ���Ԃ��Ă����烋�[�v�𔲂���
		if( ProcessMessage() == -1 ) break ;

		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break ;
	}

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;					// �\�t�g�̏I��
}


