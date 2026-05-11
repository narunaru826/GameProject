#include <memory>
#include <DxLib.h>



#include"../Game/Scene/SceneManager/SceneManager.h"
#include"../Lib/Common.h"
#include"../Lib/Input/Input.h"
//#include"../lib/Mouse.h"


#define FLAG_NUM (2)
void DrawPixelMath(float x, float y, int color)
{
	float drawX = x + WINDOW_SIZE_X / 2.0f;
	float drawY =  + WINDOW_SIZE_Y / 2.0f;
	DrawPixel(static_cast<int>(drawX), static_cast<int>(drawY), color);
}
// プログラムは WinMain から始まります
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// メモリリーク発見用
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// スクリーン設定
	ChangeWindowMode(TRUE);			// フルスクリーンorウィンドウモード
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);	// ウィンドウのサイズ

#ifndef _DEBUG
	// リリース版はログを出さない
	SetOutApplicationLogValidFlag(false);
#endif

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	//一番最初に１回だけやる処理
	SetDrawScreen(DX_SCREEN_BACK);
	SetWriteZBuffer3D(true);
	InitInput();
	//変数


	SceneManager SceneManager;

	//カメラ関連

	//ゲームのインスタンスを生成
	SceneManager.Init();






	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//エスケープキーが押されたら終了
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
		ClearDrawScreen();	// 画面クリア
		AddFontResourceEx("font/x14y24pxHeadUpDaisy.ttf", FR_PRIVATE, NULL);
		ChangeFont("x14y24pxHeadUpDaisy");
		//SetFontSize(35.0f);
		SceneManager.Loop();
		ChangeLightTypeDir(VGet(0.0f, 4000.0f, 400.0f));
		//SetLightDirection(VGet(0.0f, 1000.0f, 0.0f));


		//CMouse::SetMouseCursorFlag(false);

		/*for (float x = -300; x <= 300; x += 0.1f)
		{
			float y = (x * x) / 100.0f;
			DrawPixelMath(x, y, GetColor(255, 255, 255));
		}

		DrawCircleAA(0 + WINDOW_SIZE_X / 2.0f, 0 + WINDOW_SIZE_Y / 2.0f, 5.0f, 16, GetColor(255, 0, 0));*/

		//ここにゲームの本体を書く
		// モデル表示
		UpdateInput();


		SceneManager.Draw();

		//SetMousePoint(SCREEN_HALF_SIZE_X, SCREEN_HALF_SIZE_Y);

		ScreenFlip();		// 描画切り替え

	}


	RemoveFontResourceEx("font/x14y24pxHeadUpDaisy.ttf", FR_PRIVATE, NULL);





	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

