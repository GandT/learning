/*
  �v���O�������Ftest-0106
  ����ҁF�f���s
  ��������F2008�N7��16���`2008�N7��16��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include"DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	if(DxLib_Init() != 0)return -1;
	LoadGraphScreen(0,0,"Gewy001.png",true);
	LoadGraphScreen(235,168,"Gewy001.png",true);
	LoadGraphScreen(0,300,"Gewy001.png",true);
	LoadGraphScreen(256,0,"Gewy001.png",true);
	WaitTimer(5000);
	DxLib_End();
	return 0;
}