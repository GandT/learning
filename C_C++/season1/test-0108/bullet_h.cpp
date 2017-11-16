#include "bullet_h.h"
#include <math.h>
extern short gx,gy;

void TAMA2::Move()
{
	float np = GetDegree(x - px,y - py);
	float tn = GetDegree(gx - x,gy - y);
	//規定の角度内に目標があるかどうか
	if(DegreeSub2(tn,np) < T2_MAGARI_MAX)
	{
		px = x;
		py = y;

		float dist_tn = sqrt((gx - x)*(gx - x) + (gy - y)*(gy - y));
		x += static_cast<float>(gx - x) / dist_tn * T2_SPEED_MAX;
		y += static_cast<float>(gy - y) / dist_tn * T2_SPEED_MAX;
	}
	else
	{
		px = x;
		py = y;

		float nprad = np / 180.0f * 3.14159265358979;
		//目標が右にあるか左にあるか
		if (DegreeSub(tn,np) < 180)//左
		{
			nprad -= T2_MAGARI_MAX_R; 
		}else
		{
			nprad += T2_MAGARI_MAX_R;
		}
		x += cos(nprad) * T2_SPEED_MAX;
		y += sin(nprad) * T2_SPEED_MAX;
	}
	

	
}