#include"EnemyManager.h"
#include"../../Lib/Common.h"
#include<math.h>


EnemyManager::EnemyManager()
{
	m_waitcount = 0;
	m_waitcount2 = 0;
	m_EnemyCount = 0;
	m_StageCount = 240;
	
	
	Rad = 0.0f;
	m_count = 0;
	EnemyNum1 = 0;
	EnemyNum2 = 0;
	EnemyNum3 = 0;
	EnemyNum4 = 0;
	EnemySpeed = 0;

}

//デストラクタ
EnemyManager::~EnemyManager()
{
	Exit();
}

//初期化
void EnemyManager::Init()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy[i].Init();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy2[i].Init();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy3[i].Init();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Boss1[i].Init();
	}
	m_waitcount = 0;
	m_waitcount2 = 0;
	
	m_EnemyCount = 0;
	m_EnemyCount2 = 0;
	m_EnemyCount3 = 0;
	m_EnemyCount4 = 0;
	m_count = 0;
	m_StageCount = 240;
	Rad = 0.0f;
	flg = false;
	EnemyNum1 = 0;
	EnemyNum2 = 0;
	EnemyNum3 = 0;
	EnemyNum4 = 0;
	EnemySpeed = 0;
	Rand = GetRand(2);

	if (Rand == 0)
	{
		EnemySpeed = 0.5;
	}
	if (Rand == 1)
	{
		EnemySpeed = 0.75f;
	}
	if (Rand == 2)
	{
		EnemySpeed = 1.0;
	}
}

//ロード
void EnemyManager::Load()
{
	
	//オリジナルの複製
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy[i].Load();

	}
	//オリジナルの複製
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy2[i].Load();

	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy3[i].Load();

	}
	
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Boss1[i].Load();
	}


}

//終了
void EnemyManager::Exit()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy[i].Exit();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy2[i].Exit();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy3[i].Exit();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Boss1[i].Exit();
	}
}


void EnemyManager::Step(Player &player ,ShotManager &shotManager)
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{

		m_Enemy[i].Step(shotManager,player);
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy2[i].Step(shotManager, player);
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy3[i].Step(shotManager, player);
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Boss1[i].Step(shotManager, player);
	}
}
//描画
void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{

		m_Enemy[i].Draw();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy2[i].Draw();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy3[i].Draw();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Boss1[i].Draw();
	}
}

