#pragma once
#include"PLShot.h"
#include"EnemyShot.h"

#define PL_SHOT_NUM (1000)

#define ENE_SHOT_NUM (1000)

class ShotManager
{
private:
	//プレイヤーのショット
	ShotPL m_PlayerShot[PL_SHOT_NUM];
	ShotEnemy m_EnemyShot[ENE_SHOT_NUM];


	float m_Rot;
	int m_hndl;
	int count;
	

public:
	//コンストラクタ・デストラクタ
	ShotManager();
	~ShotManager();

	//初期化
	void Init();
	//データロード
	void Load();
	//終了処理
	void Exit();
	//繰り返し行う処理
	void Step();
	//描画
	void Draw();

	//プレイヤーのショットリクエスト
	void RequestPlayerShot(const VECTOR& Pos, const float& Speed);

	//プレイヤーのショットリクエスト
	void RequestEnemyShot(const VECTOR& Pos, const VECTOR& Speed);
	
	
	//プレイヤーのショットの情報取得
	ShotPL& GetPlayerShot(int ID)
	{
		return m_PlayerShot[ID];
	}

	//プレイヤーのショットの情報取得
	ShotEnemy& GetEnemyShot(int ID)
	{
		return m_EnemyShot[ID];
	}

};