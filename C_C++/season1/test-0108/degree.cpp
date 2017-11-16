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


float DegreeSub(float dest,float src)	//�p�x�̈����Z
{
	return NormalizeDegree(dest - src);
}
float DegreeSub2(float dest,float src)	//�p�x�̈����Z�����āA�������ق���Ԃ��B
{
	float tmp = DegreeSub(dest,src);
	if(tmp >=180)return 360 - tmp;
	return tmp;
}
float NormalizeDegree(float dest)		//�p�x���O�`�R�U�O�̒��Ɏ��߂�B
{
	while(dest < 0)dest += 360;
	while(dest >= 360)dest -= 360;
	return dest;
}
