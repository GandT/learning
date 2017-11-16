/*
  �v���O�������Ftest-0080
  ����ҁFDxLibrary
  ��������F2008�N6��18���`2008�N6��18��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�L�[�{�[�h���̓v���O����
*/
#include "DxLib.h"
// WinMain�֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	int x , y ;

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1;

	// �`����ʂ𗠉�ʂɂ���
	SetDrawScreen( DX_SCREEN_BACK ) ;

	x = 0 ; y = 0 ; 
	while( 1 )
	{
		// ��ʂɕ`����Ă�����̂����ׂď���
		ClearDrawScreen() ;

		// �㉺���E�̃L�[���͂ɑΉ����� x, y �̍��W�l��ύX����
		if( CheckHitKey( KEY_INPUT_LEFT ) == 1 ) x -= 8 ;
		if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 ) x += 8 ;
		if( CheckHitKey( KEY_INPUT_UP ) == 1 ) y -= 8 ;
		if( CheckHitKey( KEY_INPUT_DOWN ) == 1 ) y += 8 ;

		// x , y ��������ʍ��W�ɂa�l�o�摜 test1.bmp ��`�悷��
		LoadGraphScreen( x , y , "�G���L�V���[�^�[.bmp" , TRUE ) ;

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip() ;

		// �҂��Ȃ��Ə�������������̂ł����łQ�O�~���b�҂�
		WaitTimer( 20 ) ;

		// Windows �V�X�e�����炭�������������
		if( ProcessMessage() == -1 ) break ;

		// �d�r�b�L�[�������ꂽ�烋�[�v���甲����
		if( CheckHitKey( KEY_INPUT_ESCAPE ) == 1 ) break ;
	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}