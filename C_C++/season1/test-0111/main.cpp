/*
  プログラム名：test-0111
  制作者：Ｇ＆Ｔ
  制作日時：2009年8月12日～2009年8月12日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：メッセージボックスプログラム
*/

#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR pCmdLine, int showCmd)
{
	MessageBox( NULL, _T("世界中に狂気と混乱を"), _T("神のお告げ"), MB_OK );
	return 0;
}

