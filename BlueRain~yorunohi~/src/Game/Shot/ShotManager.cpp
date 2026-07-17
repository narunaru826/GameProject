#include"ShotManager.h"
#include<math.h>


#define SHOTWAIT (3)
#define SHOTSPEED (30)

//コンストラクタ
ShotManager::ShotManager()
{
	m_Rot = 0.0f;
	m_hndl = -1;
	m_hndl2 = -1;
	m_hndl3 = -1;
	m_hndl4 = -1;
	m_hndl5 = -1;
	
}

//デストラクタ
ShotManager::~ShotManager()
{
	Exit();
}
//初期化
void ShotManager::Init()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		m_PlayerShot[i].Init();

	}
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		m_EnemyShot[i].Init();

	}
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		m_EnemyShot2[i].Init();

	}
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{
		m_BossShot[i].Init();

	}
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{
		m_BossShot2[i].Init();

	}
	m_hndl = -1;
	m_hndl2 = -1;
	m_hndl3 = -1;
	m_hndl4 = -1;
	m_hndl5 = -1;
	
	count = 700;
	m_Rot = 0.0f;
	m_Angle = 0.0f;
	m_shotWait = 0;

	m_count = 0;
	m_count2 = 0;
}

//ロード
void ShotManager::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("Data/shotboss4.png");
	}
	if (m_hndl2 == -1)
	{
		m_hndl2 = LoadGraph("Data/shotboss.png");
	}
	if (m_hndl3 == -1)
	{
		m_hndl3 = LoadGraph("Data/shotboss3.png");
	}
	if (m_hndl4 == -1)
	{
		m_hndl4 = LoadGraph("Data/BYKN0939.png");
	}
	if (m_hndl5 == -1)
	{
		m_hndl5 = LoadGraph("Data/shot1.png");
	}
	//オリジナルモデル読み込み
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		m_PlayerShot[i].Load(m_hndl5);
	}
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{
		m_BossShot[i].Load(m_hndl);
	}
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{
		m_BossShot2[i].Load(m_hndl2);
	}
	
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		m_EnemyShot[i].Load(m_hndl4);
	}
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		m_EnemyShot2[i].Load(m_hndl4);
	}
	//DeleteGraph(m_hndl);
}

//終了
void ShotManager::Exit()
{
	/*for (int i = 0; i < PL_SHOT_NUM; i++)
	{

		m_PlayerShot[i].Exit();

	}*/
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{
		m_BossShot[i].Exit();
	}
	/*for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{
		m_BossShot2[i].Exit();
	}

	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		m_EnemyShot[i].Exit();
	}
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		m_EnemyShot2[i].Exit();
	}*/
	
}

//毎フレーム呼ぶ処理
void ShotManager::Step(Player &player)
{
	if (player.GetInviCount() > 0)
	{
		for (int i = 0; i < ENE_SHOT_NUM; i++)
		{
			m_EnemyShot[i].SetIsActive(false);
		}
		for (int i = 0; i < ENE_SHOT_NUM; i++)
		{
			m_EnemyShot2[i].SetIsActive(false);
		}
		for (int i = 0; i < BOSS_SHOT_NUM; i++)
		{
			m_BossShot[i].SetIsActive(false);
		}
		for (int i = 0; i < BOSS_SHOT_NUM; i++)
		{
			m_BossShot2[i].SetIsActive(false);
		}
	}
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{

		m_PlayerShot[i].Step();
		
	}
	m_pl = player.GetPosition();
	m_shotWait--;
	if (m_shotWait < 0) {
		RequestPlayerShot(VGet(player.GetPosition().x + 10, player.GetPosition().y - 30, 0), SHOTSPEED);

		RequestPlayerShot(VGet(player.GetPosition().x - 10, player.GetPosition().y - 30, 0), SHOTSPEED);
		RequestPlayerShot(VGet(player.GetPosition().x + 30, player.GetPosition().y, 0), SHOTSPEED);
		RequestPlayerShot(VGet(player.GetPosition().x - 30, player.GetPosition().y, 0), SHOTSPEED);
		m_shotWait = SHOTWAIT;
	}
	bool allfalse = true;
	bool allfalse2 = true;

	
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		if (m_EnemyShot[i].IsActive())
		{
			allfalse = false;
			
		}
		if (m_count >= 138)
		{
			m_EnemyShot[i].Step(player);
		}
	}
	if (allfalse)
	{
		m_count = 0;
	}

	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		if (m_EnemyShot2[i].IsActive())
		{
			allfalse2 = false;

		}
		if (m_count2 >= 138)
		{
			m_EnemyShot2[i].Step(player);
		}
	}
	
	if (allfalse2)
	{
		m_count2 = 0;
	}
	m_Rot += 0.01;
	

	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		m_BossShot[i].Step();

	}
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		m_BossShot2[i].Step();

	}
}

//更新処理
void ShotManager::Draw()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{

		m_PlayerShot[i].Draw();

	}
	
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		if (m_EnemyShot[i].IsActive()) {
			m_EnemyShot[i].Draw();
		}

	}
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		if (m_EnemyShot2[i].IsActive()) {
			m_EnemyShot2[i].Draw();
		}

	}
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		m_BossShot[i].Draw();

	}
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		m_BossShot2[i].Draw();

	}
	DrawFormatString(20, 20, GetColor(255, 0, 0), "弾が発射された数:%d", m_count);
}





//プレイヤーのショットリクエスト
void ShotManager::RequestPlayerShot(const VECTOR& Pos, const float& Speed)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{

		if (m_PlayerShot[i].RequestShot(Pos, Speed))
		{

			break;
		}
	}

}

//プレイヤーのショットリクエスト
void ShotManager::RequestEnemyShot(const VECTOR& Pos, const VECTOR& Speed)
{
	
	VECTOR CPos = Pos;
	static int count = 700;
	float angle = 0.0f;
	int rand = GetRand(4);
	
	

	VECTOR Spd;
	VECTOR v;
	float len = 0.0f;;
	v = VSub(m_pl, Pos);

	len = v.x * v.x + v.y * v.y + v.z * v.z;
	len = sqrtf(len);

	v.x = v.x / len;
	v.y = v.y / len;
	v.z = v.z / len;

	Spd.x = v.x * 6;
	Spd.y = v.y * 6;
	Spd.z = v.z * 6;
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		
		
		if (m_EnemyShot[i].RequestShot(CPos, Spd))
		{
			m_count++;
			break;
		}
	}
	
}
//プレイヤーのショットリクエスト
void ShotManager::RequestEnemyShot2(const VECTOR& Pos, const VECTOR& Speed)
{

	VECTOR CPos = Pos;
	static int count = 700;
	float angle = 0.0f;
	int rand = GetRand(4);



	VECTOR Spd;
	VECTOR v;
	float len = 0.0f;;
	v = VSub(m_pl, Pos);

	len = v.x * v.x + v.y * v.y + v.z * v.z;
	len = sqrtf(len);

	v.x = v.x / len;
	v.y = v.y / len;
	v.z = v.z / len;

	Spd.x = v.x * 6;
	Spd.y = v.y * 6;
	Spd.z = v.z * 6;
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{


		if (m_EnemyShot2[i].RequestShot(CPos, Spd))
		{
			m_count2++;
			break;
		}
	}

}

//ボスのショットリクエスト1
void ShotManager::RequestBossShot(const VECTOR& Pos, const VECTOR& Speed)
{

	static float rad = 0.0f;
	static float radi = 0.0f;

	VECTOR CPos = Pos;
	static int count = 0;
	float angle = 0.0f;
	int rand = GetRand(4);
	VECTOR Spd;

	
	Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 6;
	Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 6;
	rad += 90;
	radi += 50;
	count++;
	
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{
		
		

		if (m_BossShot[i].RequestShot(CPos, Spd))
		{
			//m_count++;

			/*if (m_count >= 36)
			{
				break;
			}*/
			if (count >= 6)
			{
				count = 0;
				break;
			}
			break;
		}
	}

}

//ボスのショットリクエスト1
void ShotManager::RequestBossShot2(const VECTOR& Pos, const VECTOR& Speed)
{

	static float rad = 0.0f;
	static float radi = 0.0f;

	VECTOR CPos = Pos;
	static int count = 0;
	float angle = 0.0f;
	int rand = GetRand(4);
	VECTOR Spd;


	Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 5;
	Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 5;
	rad += 60;
	radi += 50;
	count++;

	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 5;
		Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 5;
		rad += 60;
		radi += 50;
		count++;

		if (m_BossShot2[i].RequestShot(CPos, Spd))
		{
			//m_count++;

			/*if (m_count >= 36)
			{
				break;
			}*/
			if (count >= 6)
			{
				count = 0;
				break;
			}
			break;
		}
	}

}

//ボスのショットリクエスト1
void ShotManager::RequestBossShot3(const VECTOR& Pos, const VECTOR& Speed)
{

	static float rad = 0.0f;
	static float radi = 0.0f;

	VECTOR CPos = Pos;
	static int count = 0;
	float angle = 0.0f;
	int rand = GetRand(4);
	VECTOR Spd;


	Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 7;
	Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 7;
	rad += 60;
	radi += 50;
	count++;

	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 6;
		Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 6;
		rad += 60;
		radi += 50;
		count++;

		if (m_BossShot2[i].RequestShot(CPos, Spd))
		{
			//m_count++;

			/*if (m_count >= 36)
			{
				break;
			}*/
			if (count >= 2)
			{
				count = 0;
				break;
			}
			break;
		}
	}

}

