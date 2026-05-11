#pragma once
#include<DxLib.h>
#include"../Object/Object.h"
class Enemy1 : public Object
{
	float x;
	float y;
public:
	//コンストラクタ・デストラクタ
	Enemy1();
	~Enemy1();

	//初期化
	void Init();
	//ロード
	void Load(int hndl);
	//終了
	void Exit();
	//毎フレーム処理
	void Step();
	
	//描画
	void Draw();

	//敵の生成要請
	bool Request(const VECTOR& pos, const VECTOR& speed);



	//bool Hit(int Damage, Point& Point);

	


	
};