#pragma once
#include"PLShot.h"
#include"EnemyShot.h"
#include"EnemyShot2.h"
#include"BossShot.h"
#include"BossShot2.h"
#include"../Player/Player.h"
#define PL_SHOT_NUM (400)

#define ENE_SHOT_NUM (138)
#define BOSS_SHOT_NUM (500)

class ShotManager
{
private:
	//プレイヤーのショット
	ShotPL m_PlayerShot[PL_SHOT_NUM];
	ShotEnemy m_EnemyShot[ENE_SHOT_NUM];
	ShotEnemy2 m_EnemyShot2[ENE_SHOT_NUM];
	BossShot m_BossShot[BOSS_SHOT_NUM];
	BossShot2 m_BossShot2[BOSS_SHOT_NUM];


	float m_Rot;
	int m_hndl;
	int m_hndl2;
	int m_hndl3;
	int m_hndl4;
	int m_hndl5;

	int count;
	float m_Angle;
	int m_shotWait;
	VECTOR m_pl;

	int m_count;
	int m_count2;

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
	void RequestEnemyShot2(const VECTOR& Pos, const VECTOR& Speed);
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
	ShotEnemy2& GetEnemyShot2(int ID)
	{
		return m_EnemyShot2[ID];
	}
	//プレイヤーのショットの情報取得
	BossShot& GetBoss1Shot(int ID)
	{
		return m_BossShot[ID];
	}
	BossShot2& GetBoss2Shot(int ID)
	{
		return m_BossShot2[ID];
	}
};