#include"ShotManager.h"
#include<math.h>

//定義関連
static const char PLSHOT_MODEL_PATH[] = { "data/model/Weapon/Bullet.x" };

static const char TURRETSHOT_MODEL_PATH[] = { "data/model/Weapon/Bullet.x" };
static const char ENESHOTGUID_MODEL_PATH[] = { "data/model/SphereChan/SphereChan.x" };
#define SHOTWAIT (3)
#define SHOTSPEED (30)

//コンストラクタ
ShotManager::ShotManager()
{
	m_Rot = 0.0f;
	m_hndl = -1;
	
}

//デストラクタ
ShotManager::~ShotManager()
{

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
	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{
		m_BossShot[i].Init();

	}
	m_hndl = -1;
	
	count = 700;
	m_Rot = 0.0f;
	m_Angle = 0.0f;
	m_shotWait = 0;

	m_count = 0;
}

//ロード
void ShotManager::Load()
{
	//オリジナルモデル読み込み
	/*if (m_hndl == -1) {
		m_hndl = MV1LoadModel(PLSHOT_MODEL_PATH);
	}
	*/

	//モデル複製
	/*for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		PlayerShot[i].Load(m_hndl);

	}*/

	
	
	

}

//終了
void ShotManager::Exit()
{
	/*for (int i = 0; i < PL_SHOT_NUM; i++)
	{

		PlayerShot[i].Exit();

	}*/

	
}

//毎フレーム呼ぶ処理
void ShotManager::Step(Player &player)
{
	
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

	
	for (int i = 0; i < ENE_SHOT_NUM; i++)
	{
		if (m_EnemyShot[i].IsActive())
		{
			allfalse = false;
			
		}
		if (m_count > 137)
		{
			m_EnemyShot[i].Step(player);
		}
	}
		
	if (allfalse)
	{
		m_count = 0;
	}
	m_Rot += 0.01;
	

	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		m_BossShot[i].Step();

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

		m_EnemyShot[i].Draw();

	}

	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		m_BossShot[i].Draw();

	}
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

	
	Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 8;
	Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 8;
	rad += 60;
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


	Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 8;
	Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 8;
	rad += 60;
	radi += 50;
	count++;

	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 8;
		Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 8;
		rad += 60;
		radi += 50;
		count++;

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
void ShotManager::RequestBossShot3(const VECTOR& Pos, const VECTOR& Speed)
{

	static float rad = 0.0f;
	static float radi = 0.0f;

	VECTOR CPos = Pos;
	static int count = 0;
	float angle = 0.0f;
	int rand = GetRand(4);
	VECTOR Spd;


	Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 8;
	Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 8;
	rad += 60;
	radi += 50;
	count++;

	for (int i = 0; i < BOSS_SHOT_NUM; i++)
	{

		Spd.x = cosf(rad * DX_PI_F / 180 + radi) * 8;
		Spd.y = sinf(rad * DX_PI_F / 180 + radi) * 8;
		rad += 60;
		radi += 50;
		count++;

		if (m_BossShot[i].RequestShot(CPos, Spd))
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

