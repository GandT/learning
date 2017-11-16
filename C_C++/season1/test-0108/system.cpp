#include "DxLib.h"
#include "gazoukanri.h"

#define TAMA_MAX 128 //�e�̍ő吔

int SikakuMuki;
int SikakuGraph;
int SikakuW;
int SikakuH;

const int SHOT_INTERVAL = 4;
const int SHOT_SPEED = 16;

extern short gx; //Gewy��X���W�̃R�s�[
extern short gy; //Gewy��Y���W�̃R�s�[
extern int Bw; //�e���o���̂Ɏg���z�̃R�s�[
extern int Sw; //�e���o���̂Ɏg���z�̃R�s�[
extern int ShotInterval; //�e���o���Ƃ��Ɏg���z�̃R�s�[

//�e�̍\����
struct TAMA
{
	int x,y;
	char exist;
	TAMA()
	{
		exist = 0;
		x = y = 0;
	}
	static int ShotX,ShotY,ShotW,ShotH;
};



int TAMA::ShotX = 0,TAMA::ShotY = 0;
int TAMA::ShotW = 0,TAMA::ShotH = 0;

TAMA JIKITAMA[TAMA_MAX];

//�e�o�r�R���g���[��
void FPSCheck(void)
{
	static float a,b;
	b = a;
	while(GetNowCount() - b <16)Sleep(0);
	a = GetNowCount();
	clsDx();
	printfDx("%fFPS\n",1000/(a-b));
}

//�c��̒e���擾����
int GetFreeTama(void)
{
	int i =0;
	for(; i < TAMA_MAX; ++i)
	{
		if(!JIKITAMA[i].exist)break;
	}
	if(i==TAMA_MAX-1&&JIKITAMA[i].exist)return -1;
	return i;
}

//�悭������񂪕K�v�炵��
void WindowsCheck(void)
{
	if (ProcessMessage() == -1){
		DxLib_End();
		exit(-1);//�G���[���������炷���I��
	}
}

//�摜����
void pictureinput(void)
{
	//�摜�ǂݍ���
	Cgazoukanri.set (1,"Gewy001.png"); //Gewy001
	Cgazoukanri.set (2,"���j���[���.bmp"); //���j���[���
	Cgazoukanri.set (3,"���.png"); //���j���[��ʂ̖��
	Cgazoukanri.set (4,"�΂������炤���.png"); //���j���[�̐؂�[
	Cgazoukanri.set (5,"�w�i�Q.png"); //�D�F�̐��E
	Cgazoukanri.set (6,"���̂���.png"); //���̃X�R�A�Ƃ�
	Cgazoukanri.set (7,"Gewy�̒e�@.png"); //Gewy�̒e���ǔ�
	Cgazoukanri.set (8,"Gewy�̒e�A.png"); //Gewy�̒e���p���[
	GetGraphSize(Cgazoukanri.get(1),&Bw,NULL);
	GetGraphSize(Cgazoukanri.get(7),&Sw,NULL);
/*	Cgazoukanri.set (9,"W�EO�EN3.png"); //�^�C�g�����
	Cgazoukanri.set (10,"yazirushi.bmp"); //���
	Cgazoukanri.set (11,"Zkey.bmp"); //�y�Ŏ���
	Cgazoukanri.set (12,"Xkey.bmp"); //�w�ŃX�L�b�v
	Cgazoukanri.set (13,"hikokuUP.bmp"); //�퍐�̊�
	Cgazoukanri.set (14,"hikoku.bmp"); //�퍐
	Cgazoukanri.set (15,"blueB.bmp") ; //���{�E�����O��
	Cgazoukanri.set (16,"redB.bmp") ; //�Ԃ��{�E�����O��
	Cgazoukanri.set (17,"greenB.bmp") ; //�΂̃{�E�����O��
	Cgazoukanri.set (18,"gameover2.bmp");//���[�ނ��[�΁[
	Cgazoukanri.set (19,"cloud.bmp") ; //�_
	Cgazoukanri.set (20,"gameover3.bmp");//GAMEOVER
	Cgazoukanri.set (21,"guard1.bmp") ; //����������
	Cgazoukanri.set (22,"guard2.bmp") ; //��������
	Cgazoukanri.set (23,"guard3.bmp") ; //������
	Cgazoukanri.set (24,"guard4.bmp") ; //����
	Cgazoukanri.set (25,"power0.bmp") ; //��̃G�l���M�[
	Cgazoukanri.set (26,"gameover4.bmp");//�o�i�i���H�ׂ���
	Cgazoukanri.set (27,"gameover5.bmp");//������߂��̐S
	Cgazoukanri.set (28,"gameover6.bmp");//�ڎw�����E��	
	Cgazoukanri.set (29,"gameover7.bmp");//�R�}���h���́I�I
	Cgazoukanri.set (30,"stage1clear.bmp");//�X�e�[�W1�N���A�[
	Cgazoukanri.set (31,"boss1-1.bmp");//stage1�{�X�������̂�
	Cgazoukanri.set (32,"side.png");//���T�C�h�o�[
	Cgazoukanri.set (33,"Hali.png");//�j�i���v�I�ȈӖ��Łj
	Cgazoukanri.set (34,"W�EO�EN3-2-.png") ; //���[�h�I��
	Cgazoukanri.set (35,"Hworld.bmp"); //�����
	Cgazoukanri.set (36,"BOUSOU.bmp"); //�\���A�C�e��
	Cgazoukanri.set (37,"KAIHUKU.bmp"); //�񕜃A�C�e��
	Cgazoukanri.set (38,"POWER.bmp"); //�U���A�C�e��
	Cgazoukanri.set (39,"blackB.bmp"); //�����{�E�����O��
	Cgazoukanri.set (40,"whiteB.bmp"); //�����{�E�����O��
	Cgazoukanri.set (41,"yellowB.bmp"); //���F���{�E�����O��
	Cgazoukanri.set (42,"murasakiB.bmp"); //���̃{�E�����O��
	Cgazoukanri.set (43,"skyblueB.bmp"); //���F�̃{�E�����O��
	Cgazoukanri.set (44,"Mchara.bmp"); //���G���[�h
	Cgazoukanri.set (45,"boss1-2.bmp");//���G�{�X1
	Cgazoukanri.set (46,"STOP.bmp"); //��Ƃ蔭���A�C�e��
	Cgazoukanri.set (47,"Rchara.bmp"); //�U����������
	Cgazoukanri.set (48,"gameover1.bmp"); //�s�i
	Cgazoukanri.set (49,"peopleA.bmp"); //�o���X
	Cgazoukanri.set (50,"peopleB.bmp"); //���̃^�[��
	Cgazoukanri.set (51,"peopleC.bmp"); //���w�ɂ�
	Cgazoukanri.set (52,"peopleD.bmp"); //�Ղ�Ղ悷��Ȃ��[
	Cgazoukanri.set (53,"KAIHUKUver2.0.bmp"); //��񕜃A�C�e��
	Cgazoukanri.set (54,"BALLBOSS.bmp"); //stage1�{�X��i�H
	Cgazoukanri.set (55,"life0.png");
	Cgazoukanri.set (56,"life1.png");
	Cgazoukanri.set (57,"life2.png");
	Cgazoukanri.set (58,"life3.png");
	Cgazoukanri.set (59,"life4.png");
	Cgazoukanri.set (60,"life5.png");
	Cgazoukanri.set (61,"life6.png");
	Cgazoukanri.set (62,"life7.png");
	Cgazoukanri.set (63,"life8.png");
	Cgazoukanri.set (64,"life9.png");
	Cgazoukanri.set (65,"peopleR.bmp");//�����������
	Cgazoukanri.set (66,"peopleF.bmp");//�_�f����
	Cgazoukanri.set (67,"peopleG.bmp");//�ǂ����ɂ����|�X�g�Ȃ��H
	Cgazoukanri.set (68,"sky2.bmp");//��2
	Cgazoukanri.set (69,"HaiB.bmp");//�D�F�{�[��
	Cgazoukanri.set (70,"0-s.png");
	Cgazoukanri.set (71,"1-s.png");
	Cgazoukanri.set (72,"2-s.png");
	Cgazoukanri.set (73,"3-s.png");
	Cgazoukanri.set (74,"4-s.png");
	Cgazoukanri.set (75,"5-s.png");
	Cgazoukanri.set (76,"6-s.png");
	Cgazoukanri.set (77,"7-s.png");
	Cgazoukanri.set (78,"8-s.png");
	Cgazoukanri.set (79,"9-s.png");
	Cgazoukanri.set (80,"boss2.bmp");//stage2boss
	Cgazoukanri.set (81,"boss2UP.bmp");//stage2boss��
	Cgazoukanri.set (82,"kabe.bmp");//��
	Cgazoukanri.set (83,"boss2M.bmp");//�{�X2���G
	Cgazoukanri.set (84,"boss2-2.bmp");//stage2boss(�clife3)
	Cgazoukanri.set (85,"boss2-2M.bmp");//stage2boss(�clife3)���G
	Cgazoukanri.set (86,"boss2-3UP.bmp");//�{�X2��i�����j
	Cgazoukanri.set (87,"boss2-3.bmp");//�{�X2�i�����j
	Cgazoukanri.set (88,"stage2clear.bmp");//���O�̒ʂ�
	Cgazoukanri.set (89,"UP.bmp");
	Cgazoukanri.set (90,"gcloud.bmp");//���낢����
	Cgazoukanri.set (91,"W�EO�EN3-RED-.png");
	Cgazoukanri.set (92,"W�EO�EN3-RED-2.png");
	Cgazoukanri.set (93,"kabe2.bmp");//��2
	Cgazoukanri.set (94,"boss3.bmp");
	Cgazoukanri.set (95,"boss3M.bmp");
	Cgazoukanri.set (96,"Boss3UP.bmp");
	Cgazoukanri.set (97,"boss3_2.bmp");
	Cgazoukanri.set (98,"boss3_3.bmp");
	Cgazoukanri.set (99,"boss3_4.bmp");
	Cgazoukanri.set (100,"boss3_5.bmp");
	Cgazoukanri.set (101,"boss3_6.bmp");
	Cgazoukanri.set (102,"boss3_7.bmp");
	Cgazoukanri.set (103,"boss3_2M.bmp");
	Cgazoukanri.set (104,"boss3_3M.bmp");
	Cgazoukanri.set (105,"boss3_4M.bmp");
	Cgazoukanri.set (106,"boss3_5M.bmp");
	Cgazoukanri.set (107,"boss3_6M.bmp");
	Cgazoukanri.set (108,"boss3_7M.bmp");	
	Cgazoukanri.set (109,"boss3_7UP.bmp");
	Cgazoukanri.set (110,"stage3clear.bmp");
	Cgazoukanri.set (111,"keijiUP.bmp");
	Cgazoukanri.set (112,"penguin.bmp");
	Cgazoukanri.set (113,"gameclear.bmp");
	Cgazoukanri.set (114,"hikoku-2.bmp");
	Cgazoukanri.set (115,"hikoku-2UP.bmp");
	Cgazoukanri.set (116,"scorearia.bmp");
	Cgazoukanri.set (117,"hiscorearia.bmp");
	Cgazoukanri.set (118,"true-gameclear.bmp");
	Cgazoukanri.set (119,"EASY.bmp");
	Cgazoukanri.set (120,"NOMAL.bmp");
	Cgazoukanri.set (121,"HARD.bmp");*/
}

int GewySpeed(int Gewyspeed)
{
	//������̃X�s�[�h
	int UpSpeed = Gewyspeed;
	
	//SHIFT��������Ă���Ή���
	if(CheckHitKey(KEY_INPUT_LSHIFT) == 1 || CheckHitKey(KEY_INPUT_RSHIFT) == 1) UpSpeed *= 2;
	
	//������̃X�s�[�h��Ԃ�
	return UpSpeed;
	
}

class chara{
	public:
	int x; //X���W
	int y; //Y���W
	short HP; //�̗�
	short SPEED; //���x
};

//�e�𔭎˂ł���悤�ɂ���
void GewyShot(void)
{
	--ShotInterval;
	if (CheckHitKey(KEY_INPUT_SPACE) && ShotInterval <= 0)
	{
		//�g���Ă��Ȃ��e��T��
		int i = GetFreeTama();
		if(i != -1)
		{
			//�l��ݒ�
			JIKITAMA[i].x = ( Bw - Sw ) / 2 + gx -10;
			JIKITAMA[i].y = /*( Bh - Sh ) / 2*/ + gy -5;
			JIKITAMA[i].exist = 1;
			ShotInterval = SHOT_INTERVAL;
		}
		i = GetFreeTama();
		if (i != -1)
		{
			JIKITAMA[i].x = ( Bw - Sw ) / 2 + gx +10;
			JIKITAMA[i].y = /*( Bh - Sh ) / 2*/ + gy -5;
			JIKITAMA[i].exist = 1;
		}
	}
}

//�e�𔭎˂���
void ShotITI(void)
{
	for(int i = 0;i < TAMA_MAX ; ++i )
	{
		if( JIKITAMA[i].exist )
		{
			JIKITAMA[i].y -= SHOT_SPEED;
			if ( JIKITAMA[i].y < -80 )
			{
				JIKITAMA[i].exist = 0;
			}
/*			if(HitCheck(i))
			{
				JIKITAMA[i].exist = 0;
			}*/
			Cgazoukanri.draw(8,JIKITAMA[i].x,JIKITAMA[i].y);
		}
	}
}