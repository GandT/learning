/*
  �v���O�������Ftest-0108
  ����ҁF�f���s
  ��������F2008�N8��2���`�N����
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�V���[�e�B���O�q�o�f
*/

#include"DxLib.h"
#include"gazoukanri.h"

#define CHARAMAX 128


//�v���g�^�C�v�錾
#include "system.h" //�V�X�e���֌W
int GetFreeTama(void); //system.cpp
int GewySpeed(int Gewyspeed); //system.cpp
void GewyShot(void); //system.cpp
void ShotITI(void); //system.cpp

//�O���[�o���ϐ�
char speed;//���@�̃X�s�[�h
int ShotInterval;//�e���o���Ƃ��Ɏg��
short gx; //Gewy��X���W
short gy; //Gewy��Y���W
int Bw; //�e���o���̂Ɏg��
int Sw; //�e���o���̂Ɏg��

chara[CHARAMAX];

void stage1to1(void)
{
	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen( DX_SCREEN_BACK );
	
	gx = 370; //X���W�ݒ�
	gy = 705; //Y���W�ݒ�

	while(1)
	{
		
		speed = 3;//Gewy�̈ړ����x
	
		
		//FPS�𐧌䂷��
		FPSCheck();
				
		//�S�Ă��p�[
		ClearDrawScreen();
	
		//Windows�����Ă��Ȃ����`�F�b�N����(��
		WindowsCheck();
		
		//��������C���H
		speed = GewySpeed(speed);
		
		//�����邼�I������I
		if(CheckHitKey( KEY_INPUT_LEFT) == 1) gx -= speed;
		if(CheckHitKey( KEY_INPUT_RIGHT) == 1) gx += speed;
		if(CheckHitKey( KEY_INPUT_UP) == 1) gy -= speed;
		if(CheckHitKey( KEY_INPUT_DOWN) == 1) gy += speed;
		
		//�s���߂����ე�H�N�F
		//���ɂ��
		if(gx < -1)gx = 0;
		//���ɂ��
		if(gx > 728)gx = 728;
		//���ɂ��
		if(gy < -1)gy = 0;
		//���ɂ��
		if(gy > 705)gy = 705;

		//�D�F�̋��������E
		Cgazoukanri.draw(5,0,0);
		
		//�E�̂���@���O�͒m��Ȃ�
		Cgazoukanri.draw(6,780,0);
		
		//Gewy�Q��I
		Cgazoukanri.draw(1,gx,gy);
		
		//�e���ˁI
		GewyShot();
		ShotITI();
		
		//������\�֑�ړ�
		ScreenFlip();
	}
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(1);
	SetGraphMode ( 1024 , 768 , 32 ) ;//John����ɂ�������t���X�N���[�����[�h
	if(DxLib_Init() == -1)return -1;
	pictureinput();
	stage1to1();
	
	DxLib_End();
	return 0;
}

//�����f�O