#pragma once

//各キーの割り当て
#define KEY_UP		(0b1)		//上ボタン
#define KEY_DOWN	(0b10)		//下ボタン
#define KEY_RIGHT	(0b100)		//右ボタン
#define KEY_LEFT	(0b1000)	//左ボタン
#define KEY_SHOT	(0b10000)	//弾発射ボタン1
#define KEY_SHOT2	(0b100000)	//弾発射ボタン1
#define KEY_CHOICE	(0b1000000)	//低速移動
#define KEY_ROTR	(0b10000000)	//弾発射ボタン1
#define KEY_ROTL	(0b100000000)	//弾発射ボタン1
#define KEY_CHOICE2	(0b1000000000)	//弾発射ボタン1
#define KEY_JUMP	(0b10000000000)	//弾発射ボタン1
#define KEY_BACK	(0b100000000000)	//弾発射ボタン1
#define KEY_BOOST	(0b1000000000000)	//弾発射ボタン1

//キー入力初期化
void InitInput();

//キー入力情報更新
void UpdateInput();

//キー入力判定
bool IsInputRep(unsigned int key);

//キー入力判定(トリガー判定)
bool IsInputTrg(unsigned int key);
