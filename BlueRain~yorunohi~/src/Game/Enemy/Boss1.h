#pragma once
#include<DxLib.h>
#include"../Object/Object.h"
#include"../Enemy/Enemy1.h"
#include"../Shot/ShotManager.h"
#include"../player/Player.h"
#include"../Scene/Choice/ChoiceScene.h"


class Boss1 : public Object
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
	int m_wait;
	int m_bosskillwait;
	bool m_bosskillflg;
public:
	//コンストラクタ・デストラクタ
	Boss1();
	~Boss1();

	//初期化
	void Init();
	//ロード
	void Load();
	//終了
	void Exit();
	//毎フレーム処理
	void Step(ShotManager& shotmanager, Player& player,Enemy1 &enemy1);

	//描画
	void Draw();

	//敵の生成要請
	bool Request(const VECTOR& pos, const VECTOR& speed);



	bool Hit(int Damage);


	bool GetKillflg()
	{
		return m_bosskillflg;
	}



};