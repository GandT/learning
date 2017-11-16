/*
  ƒvƒƒOƒ‰ƒ€–¼Ftest-0130
  §ì“úF2011”N9Œ1“ú
  §ìF‚f•‚s
  §ìƒ\ƒtƒgF‚a‚b‚b
  ƒRƒ“ƒpƒCƒ‰F‚a‚b‚b
  ƒvƒƒOƒ‰ƒ€‚Ì“à—eFƒtƒ@ƒCƒ‹o“ü—ÍƒvƒƒOƒ‰ƒ€
*/

#include <stdio.h>

int main()
{
	FILE *fp = fopen("‚¾‚©‚ç“Ç‚Ş“z‚¾‚Á‚Â‚Á‚Ä‚ñ‚¾‚ë”n­.txt","r");
	int score1,score2,score3;
	char moji[81];
	
	if(fp == NULL){
		puts("“Ç‚ß‚Ä‚È‚¢O|O|O|O|O|O“Ç‚ß‚Ä‚È‚¢‚Æ‚©O|O|O|O|O|O|O|O|O|O");
		return -1;
	}
	
	fscanf(fp,"%d%d%d%s",&score1,&score2,&score3,&moji);
	
	printf("%d\n%d\n%d\n%s",score1,score2,score3,moji);	
}