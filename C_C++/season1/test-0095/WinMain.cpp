/*
  �v���O�������Ftest-0095
  ����ҁF�f���s
  ��������F2008�N6��28���`2008�N7��5��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include"DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	if( DxLib_Init() == -1 )
	{
		 return -1;
	}

	DrawString(100,100,"�b���D��",0xffffff);
	
	WaitTimer(5000);

	DxLib_End();

	return 0;
}