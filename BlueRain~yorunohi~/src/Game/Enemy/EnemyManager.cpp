#include"EnemyManager.h"
#include"../../Lib/Common.h"
#include<math.h>
#include"../../Lib/MyMath/MyMath.h"
#include<cmath>


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
	for (int i = 0; i < MOB_NUM; i++)
	{
		m_mob1[i].Init();
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
	for (int i = 0; i < MOB_NUM; i++)
	{
		m_mob1[i].Load();
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
	for (int i = 0; i < MOB_NUM; i++)
	{
		m_mob1[i].Exit();
	}
}


void EnemyManager::Step(Player &player ,ShotManager &shotManager)
{
	int enemyNum1 = 0;
	int enemyNum2 = 0;
	switch (m_enemy)
	{
	case ENEMY1:
		for (int i = 0; i < ENEMY_NUM; i++)
		{

			m_Enemy[i].Step(shotManager, player);
		}
		break;
	case ENEMY2:
		for (int i = 0; i < ENEMY_NUM; i++)
		{

			m_Enemy2[i].Step(shotManager, player);
		}
		break;
	case ENEMY3:
		for (int i = 0; i < ENEMY_NUM; i++)
		{

			m_Enemy3[i].Step(shotManager, player);
		}
		break;
	case ENEMY4:
		for (int i = 0; i < MOB_NUM; i++)
		{

			m_mob1[i].Step(shotManager, player);
			if (m_mob1[i].IsActive())
			{
				enemyNum1++;
			}
			m_waitcount--;
			if (m_waitcount <= 0 || enemyNum1 == 0)
			{
				m_count++;
				Mob1Request();
				m_waitcount = 40;
			}
		}
		break;
	case ENEMY5:
		
		break;
	case ENEMY6:

		break;
	case ENEMY7:

		break;
	case ENEMY8:

		break;
	case ENEMY9:

		break;
	case BOSS:
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			m_Boss1[i].Step(shotManager, player);
			if (m_Boss1[i].IsActive())
			{
				enemyNum2++;
			}
		}
		if (enemyNum2 == 0)
		{
			Boss1Request();
		}
		break;
	}
	
	/*for (int i = 0; i < ENEMY_NUM; i++)
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
		if (m_Boss1[i].IsActive())
		{
			enemyNum2++;
		}
	}*/
	
	
	
	
}
//描画
void EnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{

		m_Enemy[i].Draw();
	}
	/*for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy2[i].Draw();
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Enemy3[i].Draw();
	}*/
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_Boss1[i].Draw();
	}
	for (int i = 0; i < MOB_NUM; i++)
	{
		m_mob1[i].Draw();
	}
	DrawFormatString(20, 80, GetColor(255, 0, 0), "敵生成:%d", m_count);
}

void EnemyManager::Mob1Request()
{
	float x = -4.5f;
	float y = 0.0f;
	VECTOR Pos;
	VECTOR Spd = VGet(0.0f,0.0f,0.0f);
	Pos.x = -100;
	Pos.y = 0;
	Pos.z = 0.0f;
	for (int i = 0; i < MOB_NUM; i++)
	{
		if (m_mob1[i].Request(Pos, Spd,x,y))
		{
			break;
		}
	}
}

void EnemyManager::Boss1Request()
{
	VECTOR Pos;
	VECTOR Spd = VGet(0.0f, 0.0f, 0.0f);
	Pos.x = WINDOW_SENTER_X - 300;
	Pos.y = WINDOW_SENTER_Y - 300;
	Pos.z = 0.0f;
	for (int i = 0; i < MOB_NUM; i++)
	{
		if (m_Boss1[i].Request(Pos, Spd))
		{
			break;
		}
	}
}