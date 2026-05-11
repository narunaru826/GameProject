#include<DxLib.h>
#include <memory>

// プログラムは WinMain から始まります
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// メモリリーク発見用
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// スクリーン設定
	ChangeWindowMode(TRUE);			// フルスクリーンorウィンドウモード
	SetGraphMode(1600, 900, 32);	// ウィンドウのサイズ

#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag(false);
#endif

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	//一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);
	SetWriteZBuffer3D(true);
	
	//変数


	

	//カメラ関連

	//ゲームのインスタンスを生成
	






	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//エスケープキーが押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
		ClearDrawScreen();	// 画面クリア
		//AddFontResourceEx("font/x14y24pxHeadUpDaisy.ttf", FR_PRIVATE, NULL);
		//ChangeFont("x14y24pxHeadUpDaisy");
		//SetFontSize(35.0f);
		
		ChangeLightTypeDir(VGet(0.0f, 4000.0f, 400.0f));
		//SetLightDirection(VGet(0.0f, 1000.0f, 0.0f));


		





		//ここにゲームの本体を書く
		// モデル表示
		


		

		

		ScreenFlip();		// 描画切り替え

	}


	//RemoveFontResourceEx("font/x14y24pxHeadUpDaisy.ttf", FR_PRIVATE, NULL);





	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

