/*
�p�x��0�`360�x�̓x���ň����B
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
	int px,py;	//�O��̈ʒu
	void Move();
};
