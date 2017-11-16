/*
角度は0～360度の度数で扱う。
*/

#include "degree.h"

#define T2_MAGARI_MAX  1
#define T2_MAGARI_MAX_R (T2_MAGARI_MAX / 180 * 3.14159265358979)
//static const float T2_MAGARI_MAX = 1;
static const float T2_SPEED_MAX = 1;

struct TAMA2
{
	int x,y;
	char exist;
	int px,py;	//前回の位置
	void Move();
};
