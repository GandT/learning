/*
  �v���O�������Ftest-0094
  ����ҁF�f���s
  ��������F2008�N6��28���`2008�N7��5��
  ����F�������A�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�e�X�g�v���O����
*/
#include"DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	if(DxLib_Init() == -1){
		return -1;
	}

	DxLib_End();

	return 0;
}