#include"ShotManager.h"
#include<math.h>
//定義関連
static const char PLSHOT_MODEL_PATH[] = { "data/model/Weapon/Bullet.x" };

static const char TURRETSHOT_MODEL_PATH[] = { "data/model/Weapon/Bullet.x" };
static const char ENESHOTGUID_MODEL_PATH[] = { "data/model/SphereChan/SphereChan.x" };


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
		PlayerShot[i].Init();

	}

	
	m_hndl = -1;
	

	m_Rot = 0.0f;
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
void ShotManager::Step()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{

		PlayerShot[i].Step();

	}

	m_Rot += 0.01;
	
}

//更新処理
void ShotManager::Draw()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{

		PlayerShot[i].Draw();

	}

	
}





//プレイヤーのショットリクエスト
void ShotManager::RequestPlayerShot(const VECTOR& Pos, const float& Speed)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{

		if (PlayerShot[i].RequestShot(Pos, Speed))
		{

			break;
		}
	}

}

