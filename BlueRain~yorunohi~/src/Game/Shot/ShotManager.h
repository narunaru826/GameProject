#pragma once
#include"PLShot.h"
#include"EnemyShot.h"
#include"BossShot.h"
#include"../Player/Player.h"
#define PL_SHOT_NUM (600)

#define ENE_SHOT_NUM (138)
#define BOSS_SHOT_NUM (4000)

class ShotManager
{
private:
	//プレイヤーのショット
	ShotPL m_PlayerShot[PL_SHOT_NUM];
	ShotEnemy m_EnemyShot[ENE_SHOT_NUM];
	BossShot m_BossShot[BOSS_SHOT_NUM];


	float m_Rot;
	int m_hndl;
	int count;
	float m_Angle;
	int m_shotWait;
	VECTOR m_pl;

	int m_count;

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
	void Step(Player &player);
	//描画
	void Draw();

	//プレイヤーのショットリクエスト
	void RequestPlayerShot(const VECTOR& Pos, const float& Speed);

	//敵のショットリクエスト
	void RequestEnemyShot(const VECTOR& Pos, const VECTOR& Speed);
	//ボスのショットリクエスト
	void RequestBossShot(const VECTOR& Pos, const VECTOR& Speed);
	//ボスのショットリクエスト
	void RequestBossShot2(const VECTOR& Pos, const VECTOR& Speed);
	//ボスのショットリクエスト
	void RequestBossShot3(const VECTOR& Pos, const VECTOR& Speed);
	
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
	//プレイヤーのショットの情報取得
	BossShot& GetBoss1Shot(int ID)
	{
		return m_BossShot[ID];
	}
};