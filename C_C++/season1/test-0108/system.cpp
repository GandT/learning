#include "DxLib.h"
#include "gazoukanri.h"

#define TAMA_MAX 128 //弾の最大数

int SikakuMuki;
int SikakuGraph;
int SikakuW;
int SikakuH;

const int SHOT_INTERVAL = 4;
const int SHOT_SPEED = 16;

extern short gx; //GewyのX座標のコピー
extern short gy; //GewyのY座標のコピー
extern int Bw; //弾を出すのに使う奴のコピー
extern int Sw; //弾を出すのに使う奴のコピー
extern int ShotInterval; //弾を出すときに使う奴のコピー

//弾の構造体
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

//ＦＰＳコントロール
void FPSCheck(void)
{
	static float a,b;
	b = a;
	while(GetNowCount() - b <16)Sleep(0);
	a = GetNowCount();
	clsDx();
	printfDx("%fFPS\n",1000/(a-b));
}

//残りの弾を取得する
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

//よく分からんが必要らしい
void WindowsCheck(void)
{
	if (ProcessMessage() == -1){
		DxLib_End();
		exit(-1);//エラーがあったらすぐ終了
	}
}

//画像入力
void pictureinput(void)
{
	//画像読み込み
	Cgazoukanri.set (1,"Gewy001.png"); //Gewy001
	Cgazoukanri.set (2,"メニュー画面.bmp"); //メニュー画面
	Cgazoukanri.set (3,"矢印.png"); //メニュー画面の矢印
	Cgazoukanri.set (4,"ばっくぐらうんど.png"); //メニューの切れ端
	Cgazoukanri.set (5,"背景２.png"); //灰色の世界
	Cgazoukanri.set (6,"横のあれ.png"); //横のスコアとか
	Cgazoukanri.set (7,"Gewyの弾①.png"); //Gewyの弾＠追尾
	Cgazoukanri.set (8,"Gewyの弾②.png"); //Gewyの弾＠パワー
	GetGraphSize(Cgazoukanri.get(1),&Bw,NULL);
	GetGraphSize(Cgazoukanri.get(7),&Sw,NULL);
/*	Cgazoukanri.set (9,"W・O・N3.png"); //タイトル画面
	Cgazoukanri.set (10,"yazirushi.bmp"); //矢印
	Cgazoukanri.set (11,"Zkey.bmp"); //Ｚで次へ
	Cgazoukanri.set (12,"Xkey.bmp"); //Ｘでスキップ
	Cgazoukanri.set (13,"hikokuUP.bmp"); //被告の顔
	Cgazoukanri.set (14,"hikoku.bmp"); //被告
	Cgazoukanri.set (15,"blueB.bmp") ; //青いボウリング球
	Cgazoukanri.set (16,"redB.bmp") ; //赤いボウリング球
	Cgazoukanri.set (17,"greenB.bmp") ; //緑のボウリング球
	Cgazoukanri.set (18,"gameover2.bmp");//げーむおーばー
	Cgazoukanri.set (19,"cloud.bmp") ; //雲
	Cgazoukanri.set (20,"gameover3.bmp");//GAMEOVER
	Cgazoukanri.set (21,"guard1.bmp") ; //ｗｗｗｗｗ
	Cgazoukanri.set (22,"guard2.bmp") ; //ｗｗｗｗ
	Cgazoukanri.set (23,"guard3.bmp") ; //ｗｗｗ
	Cgazoukanri.set (24,"guard4.bmp") ; //ｗｗ
	Cgazoukanri.set (25,"power0.bmp") ; //空のエネルギー
	Cgazoukanri.set (26,"gameover4.bmp");//バナナが食べたい
	Cgazoukanri.set (27,"gameover5.bmp");//あきらめも肝心
	Cgazoukanri.set (28,"gameover6.bmp");//目指せ世界一	
	Cgazoukanri.set (29,"gameover7.bmp");//コマンド入力！！
	Cgazoukanri.set (30,"stage1clear.bmp");//ステージ1クリアー
	Cgazoukanri.set (31,"boss1-1.bmp");//stage1ボス先っちょのみ
	Cgazoukanri.set (32,"side.png");//情報サイドバー
	Cgazoukanri.set (33,"Hali.png");//針（時計的な意味で）
	Cgazoukanri.set (34,"W・O・N3-2-.png") ; //モード選択
	Cgazoukanri.set (35,"Hworld.bmp"); //超空間
	Cgazoukanri.set (36,"BOUSOU.bmp"); //暴走アイテム
	Cgazoukanri.set (37,"KAIHUKU.bmp"); //回復アイテム
	Cgazoukanri.set (38,"POWER.bmp"); //攻撃アイテム
	Cgazoukanri.set (39,"blackB.bmp"); //黒いボウリング球
	Cgazoukanri.set (40,"whiteB.bmp"); //白いボウリング球
	Cgazoukanri.set (41,"yellowB.bmp"); //黄色いボウリング球
	Cgazoukanri.set (42,"murasakiB.bmp"); //紫のボウリング球
	Cgazoukanri.set (43,"skyblueB.bmp"); //水色のボウリング球
	Cgazoukanri.set (44,"Mchara.bmp"); //無敵モード
	Cgazoukanri.set (45,"boss1-2.bmp");//無敵ボス1
	Cgazoukanri.set (46,"STOP.bmp"); //ゆとり発動アイテム
	Cgazoukanri.set (47,"Rchara.bmp"); //攻撃準備完了
	Cgazoukanri.set (48,"gameover1.bmp"); //敗訴
	Cgazoukanri.set (49,"peopleA.bmp"); //バルス
	Cgazoukanri.set (50,"peopleB.bmp"); //俺のターン
	Cgazoukanri.set (51,"peopleC.bmp"); //小指痛い
	Cgazoukanri.set (52,"peopleD.bmp"); //ぷよぷよするなぁー
	Cgazoukanri.set (53,"KAIHUKUver2.0.bmp"); //二回復アイテム
	Cgazoukanri.set (54,"BALLBOSS.bmp"); //stage1ボス顔（？
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
	Cgazoukanri.set (65,"peopleR.bmp");//こっち見んな
	Cgazoukanri.set (66,"peopleF.bmp");//酸素くれ
	Cgazoukanri.set (67,"peopleG.bmp");//どっかにいいポストない？
	Cgazoukanri.set (68,"sky2.bmp");//空2
	Cgazoukanri.set (69,"HaiB.bmp");//灰色ボール
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
	Cgazoukanri.set (81,"boss2UP.bmp");//stage2boss顔
	Cgazoukanri.set (82,"kabe.bmp");//壁
	Cgazoukanri.set (83,"boss2M.bmp");//ボス2無敵
	Cgazoukanri.set (84,"boss2-2.bmp");//stage2boss(残life3)
	Cgazoukanri.set (85,"boss2-2M.bmp");//stage2boss(残life3)無敵
	Cgazoukanri.set (86,"boss2-3UP.bmp");//ボス2顔（負け）
	Cgazoukanri.set (87,"boss2-3.bmp");//ボス2（負け）
	Cgazoukanri.set (88,"stage2clear.bmp");//名前の通り
	Cgazoukanri.set (89,"UP.bmp");
	Cgazoukanri.set (90,"gcloud.bmp");//くろいくも
	Cgazoukanri.set (91,"W・O・N3-RED-.png");
	Cgazoukanri.set (92,"W・O・N3-RED-2.png");
	Cgazoukanri.set (93,"kabe2.bmp");//壁2
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
	//加速後のスピード
	int UpSpeed = Gewyspeed;
	
	//SHIFTが押されていれば加速
	if(CheckHitKey(KEY_INPUT_LSHIFT) == 1 || CheckHitKey(KEY_INPUT_RSHIFT) == 1) UpSpeed *= 2;
	
	//加速後のスピードを返す
	return UpSpeed;
	
}

class chara{
	public:
	int x; //X座標
	int y; //Y座標
	short HP; //体力
	short SPEED; //速度
};

//弾を発射できるようにする
void GewyShot(void)
{
	--ShotInterval;
	if (CheckHitKey(KEY_INPUT_SPACE) && ShotInterval <= 0)
	{
		//使われていない弾を探す
		int i = GetFreeTama();
		if(i != -1)
		{
			//値を設定
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

//弾を発射する
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