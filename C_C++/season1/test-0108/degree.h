#ifndef DEGREE_H__
#define DEGREE_H__
float GetDegree(int x,int y);			//度数単位のatan2
float GetDegreeF(float x,float y);

float DegreeSub(float dest,float src);	//角度の引き算
float DegreeSub2(float dest,float src);	//角度の引き算をして、小さいほうを返す。
float NormalizeDegree(float dest);		//角度を０〜３６０の中に収める。

#endif