#pragma once

#include"Boss1.h"
#include"Enemy1.h"
#include"Enemy2.h"
#include"Enemy3.h"
//#include"player.h"
#include"Time.h"


//同時に出せる敵の最大数
static const int ENEMY_NUM = 1;
static const int ENEMYBOSS_NUM = 1500;

class EnemyManager
{
private:
	Boss1 m_Boss1[ENEMY_NUM];
	Enemy1 m_Enemy[ENEMY_NUM];	//敵
	Enemy2 m_Enemy2[ENEMY_NUM];	//敵2
	Enemy3 m_Enemy3[ENEMY_NUM];	//敵2
	
	int m_waitcount;			//敵が出るまでの時間
	int m_waitcount2;			//敵が出るまでの時間
	ShotManager m_ShotManager;
	


	int m_EnemyCount;
	int m_EnemyCount2;
	int m_EnemyCount3;
	int m_EnemyCount4;

	int m_StageCount;
	float Rad;
	int m_count;
	bool flg;
	int EnemyNum1;
	int EnemyNum2;
	int EnemyNum3;
	int EnemyNum4;

	float EnemySpeed;
	int Rand;


public:
	//コンストラクタ・デストラクタ
	EnemyManager();
	~EnemyManager();

	//初期化
	void Init();
	//ロード
	void Load();
	//終了
	void Exit();
	//毎フレーム呼ぶ
	void Step(Player& player ,ShotManager &shotManager);
	//データ反映
	void Update();
	//描画
	void Draw();

	//敵の発射要請
	void Request( );
	//敵の発射要請
	void Request2();
	//敵の発射要請
	void Request3();
	//敵の発射要請
	void Request4();
	//敵の発射要請
	void Request5( );


	inline Enemy1& GetEnemy1(int ID)
	{
		return m_Enemy[ID];
	}
	inline Enemy2& GetEnemy2(int ID)
	{
		return m_Enemy2[ID];
	}
	inline Enemy3& GetEnemy3(int ID)
	{
		return m_Enemy3[ID];
	}
	inline Boss1& GetBoss1(int ID)
	{
		return m_Boss1[ID];
	}
	
	int GetCount()
	{
		return m_count;
	}

};