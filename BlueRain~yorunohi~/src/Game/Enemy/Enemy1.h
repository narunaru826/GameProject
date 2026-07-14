#pragma once
#include<DxLib.h>
#include"../Object/Object.h"
#include"../Shot/ShotManager.h"
#include"../player/Player.h"
class Enemy1 : public Object
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
	Enemy1();
	~Enemy1();
	enum TagEnemy1Move
	{
		CENTER,
		RIGHT,
		LEFT
	};
	TagEnemy1Move enemy1move;
	//初期化
	void Init();
	//ロード
	void Load();
	//終了
	void Exit();
	//毎フレーム処理
	void Step(ShotManager &shotmanager ,Player &player);
	
	//描画
	void Draw();

	//敵の生成要請
	bool Request(const VECTOR& pos, const VECTOR& speed);


	int GetRequestCount()
	{
		return m_RequestCount;
	}

	int GetRequestPostionState()
	{
		return m_RequestPostionState;
	}

	TagEnemy1Move GetEnemy1Move()
	{
		return enemy1move;
	}
	//bool Hit(int Damage, Point& Point);

	


	
};