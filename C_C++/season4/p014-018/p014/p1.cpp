/*
  2016.11.1
  OpenGL - 領域加工演習

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
 */


#include <cmath>
#include <GL/glut.h>

//各種define
#define WINDOW_WIDTH   500
#define WINDOW_HEIGHT  500
#define WINDOW_NAME    "pic"

//プロトタイプ宣言
void InitGL(int argc, char *argv[]);
void Initialization();
void SetCallbackFunctions();
void CheckHitKey(unsigned char k, int x, int y);
void CheckChangeDisplay();
void DrawSquare1();
void DrawSquare2();
void DrawSquare3();
void DrawHexagon();
void Draw2DPolygon();

//変数宣言
int drawmode = 1;
int polynum = 0;
bool addmode = false;


//main関数
int main(int argc, char *argv[])
{
  //初期化
  InitGL(argc, argv);
  Initialization();

  //コールバック関数の登録
  SetCallbackFunctions();

  //メインループ
  glutMainLoop();
  
}


//OpenGLの初期化処理
void InitGL(int argc, char *argv[])
{
  //OpenGLの初期化
  glutInit(&argc,argv);

  //OpenGLのウィンドウ初期設定
  glutInitDisplayMode(GLUT_RGBA);                   //ディスプレイ色の設定
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow(WINDOW_NAME);

}


//プログラムの初期化処理
void Initialization()
{
  //背景色の設定
  glClearColor(0, 0, 0, 0);
}


//コールバック関数登録処理
void SetCallbackFunctions()
{
  //画面変化時コールバック関数登録
  glutDisplayFunc(CheckChangeDisplay);

  //キーボード入力時コールバック関数
  glutKeyboardFunc(CheckHitKey);
}


//ディスプレイ変化時対応処理
void CheckChangeDisplay()
{
  //画面の表示をすべて削除  cf.ClearDrawScreen
  glClear(GL_COLOR_BUFFER_BIT);

  //モードに応じて図形を表示
  switch(drawmode){
  case 1: DrawSquare1();   break;
  case 2: DrawSquare2();   break;
  case 3: DrawSquare3();   break;
  case 4: DrawHexagon();   break;
  case 5: Draw2DPolygon(); break;
  }

  //実際の画面に描画　cf.ScreenFlip
  glFlush();
}


//キーボード入力対応処理
void CheckHitKey(unsigned char k,  //入力キー
		 int x, int y)     //キー入力時マウス座標
{
  //多角形モードの時
  if(drawmode == 5){
    //qかnが入力されたらモード1へ
    if(k == 'q' || k == 'n')drawmode = 1;
    
    //_が入力されたら桁数を増やすモードに
    else if(k == '_')addmode = true;
    
    //数値が入力されたら入力数値を多角形の頂点数にする
    else if('0' <= k && k <= '9'){
      if(addmode){
	polynum = polynum * 10 + k-'0';
	addmode = false;
      }else{
	polynum = k-'0';
      }
    }
  }else{

    switch(k){
    //終了
    case 'q':
    case 'Q':
    case '\033': //ESC
      exit(0);

    //モード変更
    case '1':  drawmode = 1; break;
    case '2':  drawmode = 2; break;
    case '3':  drawmode = 3; break;
    case '4':  drawmode = 4; break;
    case '5':  drawmode = 5; break;
    }
  }

  //ディスプレイのコールバック関数を呼ぶ
  glutPostRedisplay();
}


//四角形描画①
void DrawSquare1()
{
  //図形情報の指示を開始
  glBegin(GL_LINE_LOOP);  //始点と終点の結ばれた折れ線を表示
  
  //色情報
  glColor3d(1.0, 0.0, 0.0);

  //頂点情報
  glVertex2d(-0.9, -0.9);
  glVertex2d(+0.9, -0.9);
  glVertex2d(+0.9, +0.9);
  glVertex2d(-0.9, +0.9);

  //図形情報の指示を終了
  glEnd();
}

//四角形描画②
void DrawSquare2()
{
  //図形情報の指示を開始
  glBegin(GL_POLYGON);   //凸多角形ポリゴン≒色の塗られた平面
  
  //色情報
  glColor3d(1.0, 0.0, 0.0);

  //頂点情報
  glVertex2d(-0.9, -0.9);
  glVertex2d(+0.9, -0.9);
  glVertex2d(+0.9, +0.9);
  glVertex2d(-0.9, +0.9);

  //図形情報の指示を終了
  glEnd();
}


//四角形描画③
void DrawSquare3()
{
  //図形情報の指示を開始
  glBegin(GL_POLYGON);   //凸多角形ポリゴン≒色の塗られた平面
  
  //色・頂点情報
  glColor3d(1.0, 0.0, 0.0);
  glVertex2d(-0.9, -0.9);
  glColor3d(1.0, 1.0, 0.0);
  glVertex2d(+0.9, -0.9);
  glColor3d(0.0, 1.0, 1.0);
  glVertex2d(+0.9, +0.9);
  glColor3d(0.0, 0.0, 0.0);
  glVertex2d(-0.9, +0.9);

  //図形情報の指示を終了
  glEnd();
}


//六角形描画
void DrawHexagon()
{
  //図形情報の指示を開始
  glBegin(GL_POLYGON);   //凸多角形ポリゴン≒色の塗られた平面
  
  //色情報
  glColor3d(1.0, 0.0, 0.0);

  //頂点情報
  for(int i = 0;i < 6;++i)glVertex2d(0.9 * cos(i * M_PI*2 / 6), 0.9 * sin(i * M_PI*2 / 6));

  //図形情報の指示を終了
  glEnd();
}


//多角形描画
void Draw2DPolygon()
{
  //図形情報の指示を開始
  glBegin(GL_POLYGON);   //凸多角形ポリゴン≒色の塗られた平面
  
  //色・頂点情報
  for(int i = 0;i < polynum;++i){
    //グラデーション
    glColor3d(1.0 - (double)i / polynum, (double)i / polynum, (double)i / polynum);
    //頂点
    glVertex2d(0.9 * cos(i * M_PI*2 / polynum), 0.9 * sin(i * M_PI*2 / polynum));
  }

  //図形情報の指示を終了
  glEnd();
}
