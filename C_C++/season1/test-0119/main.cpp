/*
  �v���O�������Ftest-0119
  ����ҁF�f���s
  ��������F2011�N8��4��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�t�@�C���o���̓v���O����
*/

#include "stdio.h"

#define efor(X)			for(int i = 0;i < X;++i)

int main()
{
	char mojis[201];
	
	//������ǂݍ��݂Ȃ�
	printf("�������������A�����A�����傭���ė~�����̂ł�����\n�c�c���ĊԈႦ���I�@�ɂイ��傭�A���͂Ȃ̂ł����I�I\n�F");
	fgets(mojis,sizeof(mojis),stdin);
	
	//�ӂ�����[�[�[�[�[�[�[
	FILE *file = fopen("�т���.txt","w");
	
	//���������Ȃ̂ł�����
	if(file == NULL)
	{
		printf("�ӂ��A�ӂ�����オ������Ȃ������̂ł��c�c");
	}
}