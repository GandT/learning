/*
  �v���O�������Ftest-0104
  ����ҁF�f���s
  ��������F2008�N7��5���`2008�N7��5��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include"DxLib.h"

int BGM = 100;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	int test1;
	if(DxLib_Init() == -1) return -1;
	
	BGM = LoadSoundMem("kbc.wav");
	test1 = PlaySoundMem(BGM,DX_PLAYTYPE_NORMAL);
	
	while(ProcessMessage() != -1 && CheckHitKeyAll() == 0 ){
		if(test1 == -1)LoadGraphScreen( BGM , 0 , "0120.bmp" , true);
		if(BGM == -1)LoadGraphScreen( BGM , 100 , "0120.bmp" , true);
	}
	
	DxLib_End() ;
	return 0;
}
