#include "degree.h"
#include <math.h>
float GetDegree(int x,int y)
{
	return NormalizeDegree(atan2(y,x) * 180.0f / 3.14159265358979f);
}
float GetDegreeF(float x,float y)
{
	return NormalizeDegree(atan2(y,x) * 180.0f / 3.14159265358979f);
}


float DegreeSub(float dest,float src)	//角度の引き算
{
	return NormalizeDegree(dest - src);
}
float DegreeSub2(float dest,float src)	//角度の引き算をして、小さいほうを返す。
{
	float tmp = DegreeSub(dest,src);
	if(tmp >=180)return 360 - tmp;
	return tmp;
}
float NormalizeDegree(float dest)		//角度を０〜３６０の中に収める。
{
	while(dest < 0)dest += 360;
	while(dest >= 360)dest -= 360;
	return dest;
}
