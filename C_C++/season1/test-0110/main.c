#define GandT 1000
void main(void)
{
	int i/*ループ①*/,b/*ループ②*/,sosuu[GandT]/*素数判定用配列*/;
	for(i = 0;i < GandT;++i)sosuu[i] = 0;//全部初期化
	for(i = 1;i <= GandT ;++i)/*1～GandTまでの者を全て調べる*/{
		for(b = 2;b <= GandT;++b)/*同じく1～GandTまで*/{
			if(i > b){//iがbより大きかったらわざわざ計算する必要ないよね
				if(i % b == 0)goto teso;/*その数がその数以外の数で割れたら素数じゃないのでgotoで左遷*/else if(i == b)goto z;//つまり、右の条件に当てはまらなかったら素数だから素数だということを知らせておくべき
			}else if(i == b)goto z; //自分でも良く分からん
		}
	goto teso;//素数じゃ無いから
	z://素数認定待ち
	sosuu[i - 1] = 1;//素数認定 
	teso://素数じゃない奴の墓場
	}
	for(i = 2;i <= GandT;++i)if(sosuu[i - 1] == 1)printf("%d\n",i);//層巣を描画
}