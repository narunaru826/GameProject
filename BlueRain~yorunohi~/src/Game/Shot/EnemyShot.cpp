#include"EnemyShot.h"
#include<math.h>

//定義

#define RADIUS (2)
//#define MY_DEBUG 

//コンストラクタ
ShotEnemy::ShotEnemy()
{
	//初期化
	memset(&m_Pos, 0, sizeof(VECTOR));
	memset(&m_Speed, 0, sizeof(VECTOR));
	m_Rot = VGet(0.0f, 0.0f, 0.0f);
	m_hndl = -1;
	m_Radius = RADIUS;
	m_isActive = false;
}

//デストラクタ
ShotEnemy::~ShotEnemy()
{
	Exit();
}

//初期化
void ShotEnemy::Init()
{
	memset(&m_Pos, 0, sizeof(VECTOR));
	m_Speed = VGet(0.0f,0.0f,0.0f);
	m_Rot = VGet(0.0f, 0.0f, 0.0f);
	m_hndl = -1;
	m_Radius = RADIUS;
	m_isActive = false;
	m_waitflg = false;
	m_waitTimer = 700;
	m_Angle = 0;
	
}

//終了
void ShotEnemy::Exit()
{
	//モデルハンドル解放
	if (m_hndl != -1)
	{
		//MV1DeleteModel(m_hndl);
		m_hndl = -1;
	}
}

//データロード
void ShotEnemy::Load(int hndl)
{
	if (m_hndl == -1)
	{
		//m_hndl = MV1DuplicateModel(hndl);
	}
}

//描画
void ShotEnemy::Draw()
{
	
	if (m_isActive)
	{
		DrawCircle(m_Pos.x, m_Pos.y, 6, GetColor(234, 145, 152));
		//MV1DrawModel(m_hndl);
#ifdef MY_DEBUG
		VECTOR Pos = m_Pos;

		DrawSphere3D(Pos, m_Radius, 16, GetColor(0, 0, 255), GetColor(0, 0, 0), FALSE);
#endif
	}
}

//毎フレーム呼ぶ処理
void ShotEnemy::Step(Player& Player)
{
	if (!m_isActive)
	{
		return;
	}
	

	
	//座標に速度を加算
	float speed = 5.0f;
	
	
	m_Pos = VAdd(m_Pos, m_Speed);
	//一定範囲を超えたら消す
	
	if (m_Pos.y > 900 || m_Pos.y < 0)
	{
		m_isActive = false;
	}
	if (m_Pos.x > 1030 || m_Pos.x < 0)
	{
		m_isActive = false;
	}

	
}

//リクエスト
bool ShotEnemy::RequestShot(const VECTOR& Pos, const VECTOR& Speed )
{
	//すでに発射されている
	if (m_isActive)
	{
		return false;
	}

	m_Pos = Pos;
	m_Speed = Speed;
	
	m_isActive = true;



	return true;
}
void ShotEnemy::Hit()
{
	m_isActive = false;
}

void ShotEnemy::Shot()
{

	
}
