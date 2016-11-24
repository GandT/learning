/*
  2016.11.1
  OpenGL - 立体作成演習

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
 */


#include <cmath>
#include <GL/glut.h>

//各種define
#define WINDOW_WIDTH   500
#define WINDOW_HEIGHT  500
#define WINDOW_NAME    "pic"
#define DRAW_PYRAMID_MODE  0
#define DRAW_CUBE_MODE     1
#define MOVE_CAMERA_MODE   0
#define MOVE_OBJECT_MODE   1

//プロトタイプ宣言
void InitGL(int argc, char *argv[]);
void Initialization();
void SetCallbackFunctions();
void CheckHitKey(unsigned char k, int x, int y);
void CheckMouseClick(int b, int s, int x, int y);
void CheckMouseMove(int x, int y);
void UpdateDisplay();
void DrawPyramid();
void DrawCube();

//変数宣言
double ang1, ang2;
double dist = 20;
bool mlfl = false;  //マウス左ボタン押下フラグ
bool mrfl = false;  //マウス右ボタン押下フラグ
int objmode = DRAW_PYRAMID_MODE;
int movmode = MOVE_CAMERA_MODE;



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

  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);  //ディスプレイ色の設定
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
  case 'p':
  case 'P':
    objmode = DRAW_PYRAMID_MODE;
    break;
  case 'c':
  case 'C':
    objmode = DRAW_CUBE_MODE;
    break;
  case '1':
    movmode = MOVE_CAMERA_MODE;
    break;
  case '2':
    movmode = MOVE_OBJECT_MODE;
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
  /***投影変換***/
  //変換対象：投影行列
  glMatrixMode(GL_PROJECTION);
  //ターゲット行列を単位行列に変換
  glLoadIdentity();
  //透視投影変換行列の乗算
  gluPerspective(30,    //カメラの画角
		 1,     //アスペクト比
		 0.1,   //最近奥行き
		 100);  //最遠奥行き

  /***モデルビュー変換***/
  //変換対象：投影行列
  glMatrixMode(GL_MODELVIEW);
  //ターゲット行列を単位行列に変換
  glLoadIdentity();
  //モデルビュー変換
  if(movmode == MOVE_CAMERA_MODE){
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
  }else if(movmode == MOVE_OBJECT_MODE){
    gluLookAt(0,0,20,
	      0,0,0,
	      0,1,0);
    glRotatef(ang1 * 20, 0, 1, 0);
    glRotatef(ang2 * 20, 1, 0, 0);
    glScalef(-dist*0.05,-dist*0.05,-dist*0.05);
  }

  //バッファの初期化
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //デプスバッファ機能の有効化
  glEnable(GL_DEPTH_TEST);

  //ピラミッド/正六面体正四面体を描画
  if(objmode == DRAW_PYRAMID_MODE)DrawPyramid();
  if(objmode == DRAW_CUBE_MODE   )DrawCube();

  //（裏）画面に描画
  glFlush();

  //デプスバッファ機能の無効化
  glDisable(GL_DEPTH_TEST);

  //裏画面を表画面に反映
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



//正六面体を描画
void DrawCube()
{
  //GL座標設定
  GLdouble A[] = {+1.5, -1.5, +1.5};
  GLdouble B[] = {-1.5, -1.5, +1.5};
  GLdouble C[] = {-1.5, -1.5, -1.5};
  GLdouble D[] = {+1.5, -1.5, -1.5};
  GLdouble E[] = {+1.5, +1.5, +1.5};
  GLdouble F[] = {-1.5, +1.5, +1.5};
  GLdouble G[] = {-1.5, +1.5, -1.5};
  GLdouble H[] = {+1.5, +1.5, -1.5};

  /* 各種面作成 */
  glBegin(GL_POLYGON);
  glColor3d(1, 0, 0);
  glVertex3dv(A);
  glVertex3dv(B);
  glVertex3dv(C);
  glVertex3dv(D);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3d(0, 1, 0);
  glVertex3dv(A);
  glVertex3dv(B);
  glVertex3dv(F);
  glVertex3dv(E);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3d(0, 0, 1);
  glVertex3dv(B);
  glVertex3dv(C);
  glVertex3dv(G);
  glVertex3dv(F);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3d(1, 1, 0);
  glVertex3dv(C);
  glVertex3dv(D);
  glVertex3dv(H);
  glVertex3dv(G);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3d(0, 1, 1);
  glVertex3dv(D);
  glVertex3dv(A);
  glVertex3dv(E);
  glVertex3dv(H);
  glEnd();
  
  glBegin(GL_POLYGON);
  glColor3d(1, 0, 1);
  glVertex3dv(E);
  glVertex3dv(F);
  glVertex3dv(G);
  glVertex3dv(H);
  glEnd();

}
