#include "Input.h"
#include<DxLib.h>

//キーボード入力用構造体
typedef struct {
	unsigned int m_nowKey;		//今回のボタン情報
	unsigned int m_PrevKey;		//1フレーム前のボタン情報
}INPUT_DATA;

//キー入力用にグローバル変数を作成
static INPUT_DATA g_inputData;

int MouseX, MouseY;

//キー入力初期化
void InitInput()
{
	g_inputData.m_nowKey = g_inputData.m_PrevKey = 0;
}

//キー入力情報更新
void UpdateInput()
{
	//前回の入力情報を最新に更新
	g_inputData.m_PrevKey = g_inputData.m_nowKey;
	//今回の入力情報を一旦0にする
	g_inputData.m_nowKey = 0;

	//上キー情報取得
	if (CheckHitKey(KEY_INPUT_W)) {
		g_inputData.m_nowKey |= KEY_UP;
	}
	//下キー情報取得
	if (CheckHitKey(KEY_INPUT_S)) {
		g_inputData.m_nowKey |= KEY_DOWN;
	}
	//右キー情報取得
	if (CheckHitKey(KEY_INPUT_D)) {
		g_inputData.m_nowKey |= KEY_RIGHT;
	}
	//左キー情報取得
	if (CheckHitKey(KEY_INPUT_A)) {
		g_inputData.m_nowKey |= KEY_LEFT;
	}
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		g_inputData.m_nowKey |= KEY_CHOICE;
	}
	if (CheckHitKey(KEY_INPUT_TAB)) {
		g_inputData.m_nowKey |= KEY_CHOICE2;
	}
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		g_inputData.m_nowKey |= KEY_JUMP;
	}
	if (CheckHitKey(KEY_INPUT_BACK)) {
		g_inputData.m_nowKey |= KEY_BACK;
	}
	if (CheckHitKey(KEY_INPUT_LSHIFT)) {
		g_inputData.m_nowKey |= KEY_BOOST;
	}
	int Mouse = GetMouseInput();
	//ショット情報取得
	if (Mouse & MOUSE_INPUT_LEFT) {
		g_inputData.m_nowKey |= KEY_SHOT;
		g_inputData.m_nowKey |= KEY_CHOICE;
	}
	if (Mouse & MOUSE_INPUT_RIGHT) {
		g_inputData.m_nowKey |= KEY_SHOT2;
	}
	////ボム情報取得
	//if (CheckHitKey(KEY_INPUT_SPACE)) {
	//	g_inputData.m_nowKey |= KEY_BOMB;
	//}
	GetMousePoint(&MouseX, &MouseY);
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) g_inputData.m_nowKey |= KEY_DOWN;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) g_inputData.m_nowKey |= KEY_UP;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) g_inputData.m_nowKey |= KEY_LEFT;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) g_inputData.m_nowKey |= KEY_RIGHT;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5) g_inputData.m_nowKey |= KEY_SHOT;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6) g_inputData.m_nowKey |= KEY_SHOT2;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3) g_inputData.m_nowKey |= KEY_ROTR;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_2) g_inputData.m_nowKey |= KEY_ROTL;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1) g_inputData.m_nowKey |= KEY_CHOICE;
	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4) g_inputData.m_nowKey |= KEY_CHOICE2;

}

//キー入力判定
bool IsInputRep(unsigned int key)
{
	if ((g_inputData.m_nowKey & key) != 0) return true;
	else return false;
}

//キー入力判定(トリガー判定)
bool IsInputTrg(unsigned int key)
{
	if ((g_inputData.m_nowKey & key) && ((g_inputData.m_PrevKey & key) == 0)) {
		return true;
	}
	else return false;
}