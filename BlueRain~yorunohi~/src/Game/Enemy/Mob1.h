#pragma once
#include<DxLib.h>
#include"../Object/Object.h"
#include"../Shot/ShotManager.h"
#include"../player/Player.h"
class Mob1 : public Object
{
	float x;
	float y;
	int m_shotwait;
	int m_count;
	VECTOR m_speed;

	bool m_waitflg;
	int m_waitTimer;

	int m_RequestCount;

	int m_RequestPostionState;


public:
	//コンストラクタ・デストラクタ
	Mob1();
	~Mob1();

	//初期化
	void Init();
	//ロード
	void Load();
	//終了
	void Exit();
	//毎フレーム処理
	void Step(ShotManager& shotmanager, Player& player);

	//描画
	void Draw();

	//敵の生成要請
	bool Request(const VECTOR& pos, const VECTOR& speed,const float& cx,const float& cy);



	//bool Hit(int Damage, Point& Point);





};