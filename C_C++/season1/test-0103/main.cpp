/*
  �v���O�������Ftest-0103
  ����ҁF�f���s
  ��������F2008�N7��5���`2008�N7��5��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF������\���v���O����
*/
#include"DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	if(DxLib_Init() == -1){
		return -1;
	}
	
	PlayMovie("�L�[�{�[�h�N���b�V���[.wmv",1,DX_MOVIEPLAYTYPE_NORMAL);
	
	DxLib_End();

	return 0;
}