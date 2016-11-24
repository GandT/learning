/*
  2016.11.7
  OpenGL - 立体作成演習

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
  寺西忠勝(発行年不明)「GLUT API リファレンス」,<http://www.asahi-net.or.jp/~yw3t-trns/opengl/glut/glut.htm#shapes>
 */


#include <cmath>
#include <GL/glut.h>

//各種define
#define WINDOW_WIDTH   500
#define WINDOW_HEIGHT  500
#define WINDOW_NAME    "pic"
#define DRAW_NORMAL_MODE  0
#define DRAW_OBJECT_MODE  1

//プロトタイプ宣言
void InitGL(int argc, char *argv[]);
void Initialization();
void SetCallbackFunctions();
void CheckHitKey(unsigned char k, int x, int y);
void CheckMouseClick(int b, int s, int x, int y);
void CheckMouseMove(int x, int y);
void UpdateDisplay();
void DrawPyramid();

//変数宣言
double ang1, ang2;
double dist = 20;
bool mlfl = false;  //マウス左ボタン押下フラグ
bool mrfl = false;  //マウス右ボタン押下フラグ
int objmode = DRAW_NORMAL_MODE;



//main関数
int main(int argc, char *argv[])
{
  InitGL(argc, argv);
  Initialization();

  SetCallbackFunctions();

  glutMainLoop();  
}



//OpenGLの初期化処理
void InitGL(int argc, char *argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
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
  //キーボード入力時コールバック関数
  glutKeyboardFunc(CheckHitKey);

  //マウス入力時コールバック関数
  glutMouseFunc(CheckMouseClick);

  //マウスドラッグ時コールバック関数
  glutMotionFunc(CheckMouseMove);

  //マウス移動時コールバック関数
  glutPassiveMotionFunc(CheckMouseMove);

  //画面変化時コールバック関数登録
  glutDisplayFunc(UpdateDisplay);
}



//キーボード入力対応処理
void CheckHitKey(unsigned char k, int x, int y)
{
  switch(k){
  //モード変更 
  case 'n':
  case 'N':
    objmode = DRAW_NORMAL_MODE;
    break;
  case 'o':
  case 'O':
    objmode = DRAW_OBJECT_MODE;
    break;
 //終了
  case 'q':
  case 'Q':
  case '\033': //ESC
    exit(0);
  }

  //ディスプレイの変化を通達
  glutPostRedisplay();
}



//マウス入力対応処理
void CheckMouseClick(int b, int s, int x, int y)
{
  //ボタンのクリック状況を更新
  if(b == GLUT_LEFT_BUTTON){
         if(s == GLUT_UP  )mlfl = false;
    else if(s == GLUT_DOWN)mlfl =  true;
  }
  if(b == GLUT_RIGHT_BUTTON){
         if(s == GLUT_UP  )mrfl = false;
    else if(s == GLUT_DOWN)mrfl =  true;
  }
}



//マウス移動時対応処理
void CheckMouseMove(int x, int y)
{
  //前回マウス座標
  static int x0 = -1;
  static int y0 = -1;

  //左クリック時
  if(mlfl){
    //前回クリック時処理
    if(x0 >= 0 && y0 >= 0){
      ang1 += (double)-(x-x0)/20;
      ang2 += (double)+(y-y0)/20;
    }
    //座標更新
    x0 = x;
    y0 = y;
  }

  //右クリック時
  else if(mrfl){
    //前回クリック時処理
    if(x0 >= 0 && y0 >= 0){
      dist += (double)+(y-y0)/20;
    }
    //座標更新
    x0 = x;
    y0 = y;
  }

  //非クリック時
  else{
    x0 = y0 = -1;
  }

  //画面更新
  glutPostRedisplay();
}



//ディスプレイ更新処理
void UpdateDisplay()
{
  /*【注意】※※※各種変換はスタックに積まれるため実際の処理順序は記述の逆順※※※【注意】*/

  /***ビューポート変換***/
  //なし

  /***投影変換***/
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30,    //カメラの画角
		 1,     //アスペクト比
		 0.1,   //最近奥行き
		 100);  //最遠奥行き

  /***モデルビュー変換***/
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //カメラ視点移動
  if(cos(ang2) > 0){
    gluLookAt(dist * cos(ang2) * sin(ang1), dist * sin(ang2) , dist * cos(ang2) * cos(ang1) ,
	      0,  0, 0,
	      0, +1, 0
	      );
  }else{
    gluLookAt(dist * cos(ang2) * sin(ang1), dist * sin(ang2) , dist * cos(ang2) * cos(ang1) ,
	      0,  0, 0,
	      0, -1, 0
	      );
  }

  //バッファの初期化
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //デプスバッファ機能の有効化
  glEnable(GL_DEPTH_TEST);

  //通常描画
  if(objmode == DRAW_NORMAL_MODE){
    //ティーポットを初期位置から移動して描画
    glPushMatrix();
    glTranslatef(-1, 3, 0);  //平行移動
    glRotatef(-30, 0, 0, 1); //回転移動
    glColor3f(1,1,1);        //色設定
    glutWireTeapot(1.0);
    glPopMatrix();

    //ピラミッドを初期位置から移動して描画
    glPushMatrix();
    glTranslatef(0, -2, 0);
    DrawPyramid();
    glPopMatrix();
  }

  //家オブジェクトの描画
  if(objmode == DRAW_OBJECT_MODE){
    //立方体の描画
    glPushMatrix();
    glTranslatef(0.85, 0.9, 0.2);
    glColor3f(1,1,1);
    glutSolidCube(0.5);
    glPopMatrix();

    //ピラミッドの描画
    glPushMatrix();
    glTranslatef(0, 1, 0);
    DrawPyramid();
    glPopMatrix();

    //立方体の描画
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glColor3f(1,1,1);
    glutSolidCube(2.0);
    glPopMatrix();
  }

  glFlush();
  glDisable(GL_DEPTH_TEST);
  glutSwapBuffers();
}



//ピラミッド体を描画
void DrawPyramid()
{
  //GL座標設定
  GLdouble O[] = {   0, +1,    0};
  GLdouble A[] = {+1.5, -1, +1.5};
  GLdouble B[] = {-1.5, -1, +1.5};
  GLdouble C[] = {-1.5, -1, -1.5};
  GLdouble D[] = {+1.5, -1, -1.5};

  /* 各種面作成 */
  glBegin(GL_TRIANGLES);
  glColor3d(1, 0, 0);
  glVertex3dv(O);
  glVertex3dv(A);
  glVertex3dv(B);
  glEnd();
  
  glBegin(GL_TRIANGLES);
  glColor3d(1, 1, 0);
  glVertex3dv(O);
  glVertex3dv(B);
  glVertex3dv(C);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3d(0, 1, 1);
  glVertex3dv(O);
  glVertex3dv(C);
  glVertex3dv(D);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3d(1, 0, 1);
  glVertex3dv(O);
  glVertex3dv(D);
  glVertex3dv(A);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3d(1, 1, 1);
  glVertex3dv(A);
  glVertex3dv(B);
  glVertex3dv(C);
  glVertex3dv(D);
  glEnd();
}
