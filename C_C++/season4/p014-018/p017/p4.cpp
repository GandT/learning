/*
  2016.11.7
  OpenGL - 光源作成演習

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
void DrawPlane();

//変数宣言
double ang1, ang2, ang3, ang4 = M_PI/4;
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
      ang3 += (double)+(y-y0)/20;
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

  //描画前準備
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);

  //光源位置に球体を描画
  glPushMatrix();
  glTranslatef(5 * cos(ang4) * sin(ang3),
	       5 * sin(ang3),
	       5 * cos(ang4) * cos(ang3));
  glutSolidSphere(0.2, 50, 50);  //後ろ２つはカクカク度合い
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0,10,0);
  glutSolidSphere(0.2, 10, 10);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(5,1,1);
  glutSolidSphere(0.2, 10, 10);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(1,8,8);
  glutSolidSphere(0.2, 10, 10);
  glPopMatrix();
  
  //陰影処理開始
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);

  //光源設定
  GLfloat lightpos[] = {5 * cos(ang4) * sin(ang3),
                        5 * sin(ang4),
                        5 * cos(ang4) * cos(ang3),
                        1.0};
  GLfloat light1[] = {0,10, 0, 1};
  GLfloat light2[] = {5, 1, 1, 1};
  GLfloat light3[] = {1, 8, 8, 1};
  GLfloat diffuse[] = {1, 1, 1, 1};
  GLfloat diff1[] = {0.8, 0.7, 0.6, 1};
  GLfloat diff2[] = {0.3, 0  , 0  , 1};
  GLfloat diff3[] = {0  , 0  , 0.9, 1};
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
  glLightfv(GL_LIGHT1, GL_POSITION, light1);
  glLightfv(GL_LIGHT2, GL_POSITION, light2);
  glLightfv(GL_LIGHT3, GL_POSITION, light3);
  glLightfv(GL_LIGHT0, GL_DIFFUSE , diffuse);
  glLightfv(GL_LIGHT1, GL_DIFFUSE , diff1);
  glLightfv(GL_LIGHT2, GL_DIFFUSE , diff2);
  glLightfv(GL_LIGHT3, GL_DIFFUSE , diff3);

  //物体描画
  glPushMatrix();
  glTranslatef(0, -2, 0);
  DrawPlane();
  glPopMatrix();

  glPushMatrix();
  glScalef(1, 2, 1);
  DrawPyramid();
  glPopMatrix();
  
  glFlush();
  glDisable(GL_LIGHT3);
  glDisable(GL_LIGHT2);
  glDisable(GL_LIGHT1);
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHTING);
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

  //GL色設定
  GLfloat col1[] = {1, 0, 0, 0.8};
  GLfloat col2[] = {1, 1, 0, 0.8};
  GLfloat col3[] = {0, 1, 1, 0.8};
  GLfloat col4[] = {1, 0, 1, 0.8};
  GLfloat col5[] = {1, 1, 1, 1.0};

  /* 各種面作成 */
  glMaterialfv(GL_FRONT, GL_DIFFUSE, col1);
  glNormal3d(0, 0.6, 0.8);
  glBegin(GL_TRIANGLES);
  glVertex3dv(O);
  glVertex3dv(A);
  glVertex3dv(B);
  glEnd();
  
  glMaterialfv(GL_FRONT, GL_DIFFUSE, col2);
  glNormal3d(-0.8, 0.6, 0);
  glBegin(GL_TRIANGLES);
  glColor3d(1, 1, 0);
  glVertex3dv(O);
  glVertex3dv(B);
  glVertex3dv(C);
  glEnd();

  glMaterialfv(GL_FRONT, GL_DIFFUSE, col3);
  glNormal3d(0 , 0.6, -0.8);
  glBegin(GL_TRIANGLES);
  glColor3d(0, 1, 1);
  glVertex3dv(O);
  glVertex3dv(C);
  glVertex3dv(D);
  glEnd();

  glMaterialfv(GL_FRONT, GL_DIFFUSE, col4);
  glNormal3d(0.8, 0.6, 0);
  glBegin(GL_TRIANGLES);
  glColor3d(1, 0, 1);
  glVertex3dv(O);
  glVertex3dv(D);
  glVertex3dv(A);
  glEnd();

  glMaterialfv(GL_FRONT, GL_DIFFUSE, col5);
  glNormal3d(0, -1, 0);
  glBegin(GL_POLYGON);
  glVertex3dv(A);
  glVertex3dv(B);
  glVertex3dv(C);
  glVertex3dv(D);
  glEnd();
}


//平板描画
void DrawPlane()
{
  //材質設定
  GLfloat col[] = {0.9, 0.9, 0.9, 1};
  glMaterialfv(GL_FRONT, GL_DIFFUSE, col);
  glNormal3d(0, 1, 0);

  //描画
  glBegin(GL_QUADS);
  glVertex3d(+4, 0, +4);
  glVertex3d(+4, 0, -4);
  glVertex3d(-4, 0, -4);
  glVertex3d(-4, 0, +4);
  glEnd();
}
