#ifndef DEGREE_H__
#define DEGREE_H__
float GetDegree(int x,int y);			//�x���P�ʂ�atan2
float GetDegreeF(float x,float y);

float DegreeSub(float dest,float src);	//�p�x�̈����Z
float DegreeSub2(float dest,float src);	//�p�x�̈����Z�����āA�������ق���Ԃ��B
float NormalizeDegree(float dest);		//�p�x���O�`�R�U�O�̒��Ɏ��߂�B

#endif