/*
  �v���O�������F�Z�b�R�n�̔���������
  ��������F2008�N5��1���`2008�N5��1��
  ����F�f���s
  ����\�t�g�F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̓��e�F�e�X�g�v���O����
*/
#include <stdio.h>
int main(){
	int takoyaki=0;
	umiusi:
	
	printf("�Ȃ񂩓��͂��냔�H�P\n");
	scanf("%d",&takoyaki);
	switch(takoyaki){
		case 1:
			printf("�Z�b�R���H�@�Ȃɂ�����������́H\n");
			break;
		case 2:
			printf("�Z�b���ċT�̕i�킶��Ȃ������́H\n");
			break;
		case 3:
			printf("�L�b�R�[�����̏ݖ��̂ق�����΂ɔ��������ƕۏ؂���\n");
			break;
		case 4:
			printf("������[����݂Ⴍ���Ă������炵��[�䂾��ˁ[��\n");
			break;
		case 5:
			printf("���̖�Y�I�I�I\n���̂����ɏܖ������؂ꂾ�ƁI�I�I\n�����Ȃ����獂���ٔ����ɑi���Ă��I�I�I�I�I\n");
			break;
		case 6:
			printf("�Z�b�R���̔����������͂������ł����[�H\n");
			break;
		case 7:
			printf("�ݖ�����߂�����Ȃ����I\n�ُ�������\n");
			break;
		case 8:
			printf("���܁A�Z�b�R���Ŏ�ꂽ���ş{������ĂĂ��܂��B\n���������������ڂ��Ȃ�̂����҂��Ă��܂���A���́I\n");
			break;
		case 9:
			printf("�Ȃ��Ɓ[���Ă݂������������񂾂ˁI�I�I\n�͂��߂Ă�������(�y��\n");
			break;
		case 10:
			printf("�Z�b�R���̔���������\n");
			break;
		case 11:
			printf("�A���R�E�̖��X��\n");
			break;
		case 12:
			printf("\a\a���̖�Y�I�I�I\n�x�����ȁI�I\n");
			break;
		case 13:
			printf("�Ɓ[�ӁA�Ɓ[�ӁA�����������������Ղ����������邡�����Ɓ[�[�[�[��������������\n");
			break;
		case 14:
			printf("�G�u������A�X�[�����ĉ�����v\n�f���s�u�������A����͏ݖ��ł��v\n");
			break;
		case 15:
			printf("�Z�b�R���Ȃ�Ă��傤�т͂��ˁ[�񂾂�A���H�P���I\n�ʂ̉�����(ry\n");
			break;
		case 16:
			printf("�R�~�J���ȘZ�b�̓������܂Ȃ�㊄����(ry\n");
			break;
		case 17:
			printf("�ΏĂ����ŗL���ȘZ�b�R���ւ悤����\n");
			break;
		case 18:
			printf("�l��̈����͂��ꂩ�炾��\n");
			break;
		default:
			printf("�������邼�I\n��H�A0�ȉ��Ȃ̂ɑ�������ƌ���ꂽ�H�I\n\a\a\a�����������ȁI�I�I�I�I\n");
			break;
		
		}
	goto umiusi;
}