/*
  プログラム名：六甲山地の美味しい水
  制作日時：2008年5月1日～2008年5月1日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：テストプログラム
*/
#include <stdio.h>
int main(){
	int takoyaki=0;
	umiusi:
	
	printf("なんか入力しろヴォケ\n");
	scanf("%d",&takoyaki);
	switch(takoyaki){
		case 1:
			printf("六甲山脈？　なにそれ美味しいの？\n");
			break;
		case 2:
			printf("六甲って亀の品種じゃなかったの？\n");
			break;
		case 3:
			printf("キッコー○ンの醤油のほうが絶対に美味しいと保証する\n");
			break;
		case 4:
			printf("ろっこーさんみゃくっていったらしょーゆだよねー♪\n");
			break;
		case 5:
			printf("この野郎！！！\n豆のくせに賞味期限切れだと！！！\nこうなったら高等裁判所に訴えてやる！！！！！\n");
			break;
		case 6:
			printf("六甲山脈の美味しい豆はいかがですかー？\n");
			break;
		case 7:
			printf("醤油が冷めたじゃないか！\n弁償しろよ♪\n");
			break;
		case 8:
			printf("いま、六甲山脈で取れた水で毬藻を育てています。\n美味しいさくらんぼがなるのを期待していますよ、あは！\n");
			break;
		case 9:
			printf("なっとーってみそあじだったんだね！！！\nはじめてしったよ(軽蔑\n");
			break;
		case 10:
			printf("六甲山脈の美味しい水\n");
			break;
		case 11:
			printf("アンコウの味噌味\n");
			break;
		case 12:
			printf("\a\aこの野郎！！！\n騙したな！！\n");
			break;
		case 13:
			printf("とーふ、とーふ、たっっっっっっっぷぅぅぅぅぅるぃぃぃとーーーーっっっぅぅぅふ\n");
			break;
		case 14:
			printf("⑧「だから、氷納豆って何だよ」\nＧ＆Ｔ「いいえ、それは醤油です」\n");
			break;
		case 15:
			printf("六甲山脈なんてきょうびはやらねーんだよ、ヴォケが！\n通の俺から(ry\n");
			break;
		case 16:
			printf("コミカルな六甲の豆がいまなら九割引で(ry\n");
			break;
		case 17:
			printf("石焼き芋で有名な六甲山脈へようこそ\n");
			break;
		case 18:
			printf("僕らの悪夢はこれからだ♪\n");
			break;
		default:
			printf("多すぎるぞ！\nん？、0以下なのに多すぎると言われた？！\n\a\a\a屁理屈言うな！！！！！\n");
			break;
		
		}
	goto umiusi;
}