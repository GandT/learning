/*
  vOΌFtest-0125
  §μϊF2011N91ϊ
  §μFfs
  §μ\tgFabb
  RpCFabb
  vOΜΰeFt@CoόΝvO
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("Άρ.txt","w");
	char moji[201];
	
	puts("ΆρπόΝ΅ΔΊ³’");
	
	fgets(moji,201,stdin);
	
	if(fp == NULL){
		puts(" ΑA²Αί[ρΐΝt@CJ―Δ³©Α½ν[ΑΔ±ΖΕ­§IΉ·ι―Η{ηΘ’ΕΛ[");
	}
	
	for(int i = 0;moji[i];++i)fputc(moji[i],fp);
	
	fclose(fp);
	
	return 0;
	
	
}