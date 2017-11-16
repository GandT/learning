/*
  �v���O�������Ftest-0113
  ����ҁF�f���s
  ��������F2009�N8��12���`2009�N8��12��
  ����F�a�b�b
  �R���p�C���F�a�b�b
  �v���O�����̎�ށF�R�c�`��v���O����
*/

#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
			 LPSTR lpCmdLine, int nCmdShow )
{
	int GrHandle ;
	float Z;
	VERTEX_3D Vertex[6] ;// �|���S���Q���Ȃ̂ŁA���_�͂U��

	// �c�w���C�u��������������
	if( DxLib_Init() == -1 )	
		 return -1 ;	// �G���[���N�����璼���ɏI��

	// �`���𗠉�ʂɂ���
	SetDrawScreen( DX_SCREEN_BACK ) ;
	
	SetGraphMode(1024,768,32) ;

	// �e�N�X�`���̓ǂݍ���
	GrHandle = LoadGraph( "Gewy001.png" ) ;

	// �y�l�̏�����
	Z = 0.0F ;
	
	// ���_���̃Z�b�g
	{
		// ��ʂ̒����ɕ��E����100�ŕ`��
		Vertex[0].pos.x = 512 - 50;	Vertex[0].pos.y = 768;	Vertex[0].pos.z = 0 ;
		Vertex[0].u = 0.0F ;
		Vertex[0].v = 0.0F ;

		Vertex[1].pos.x = 512 + 50;	Vertex[1].pos.y = 768;	Vertex[1].pos.z = 0 ;
		Vertex[1].u = 1.0F ;
		Vertex[1].v = 0.0F ;

		Vertex[2].pos.x = 512 - 50;	Vertex[2].pos.y = 668;	Vertex[2].pos.z = 0 ;
		Vertex[2].u = 0.0F ;
		Vertex[2].v = 1.0F ;

		Vertex[3].pos.x = 512 + 50;	Vertex[3].pos.y = 668;	Vertex[3].pos.z = 0 ;
		Vertex[3].u = 1.0F ;
		Vertex[3].v = 1.0F ;

		Vertex[4].pos.x = 512 - 50;	Vertex[4].pos.y = 668;	Vertex[4].pos.z = 0 ;
		Vertex[4].u = 0.0F ;
		Vertex[4].v = 1.0F ;

		Vertex[5].pos.x = 512 + 50;	Vertex[5].pos.y = 768;	Vertex[5].pos.z = 0 ;
		Vertex[5].u = 1.0F ;
		Vertex[5].v = 0.0F ;

		
		// �P�x�͑S�v�f100%
		for(int i = 0;i < 6;++i)Vertex[i].r = Vertex[i].g = Vertex[i].b = 255 ;

		// a ���ő�l
		for(int i = 0;i < 6;++i)Vertex[i].a = 255 ;
	}

	// �����L�[���������܂Ń��[�v
	while( CheckHitKeyAll() == 0 )
	{
		// ���b�Z�[�W����
		if( ProcessMessage() != 0 ) break ;

		// ��ʂ̏�����
		ClearDrawScreen() ;

		//�ǂ�ǂ�傫���Ȃ�
		for(int i = 0;i < 6;++i){
			/*if(Vertex[i].pos.z > -128.0f)*/--Vertex[i].pos.z;//else Vertex[i].pos.z = 0.0f;
		}
		
		//�㉺�ړ�
		for(int i = 0;i < 6;++i){
			--Vertex[i].pos.y;
		}

		// �|���S���𓧉ߐF�����łQ���`��
		DrawPolygon3D( Vertex, 2, GrHandle, true ) ;

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip() ;
	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End() ;

	// �\�t�g�̏I��
	return 0 ;
}

