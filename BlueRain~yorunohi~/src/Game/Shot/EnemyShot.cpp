#include"EnemyShot.h"

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
	m_waitTimer = 60;
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
		DrawCircle(m_Pos.x, m_Pos.y, 6, GetColor(255, 0, 0));
		//MV1DrawModel(m_hndl);
#ifdef MY_DEBUG
		VECTOR Pos = m_Pos;

		DrawSphere3D(Pos, m_Radius, 16, GetColor(0, 0, 255), GetColor(0, 0, 0), FALSE);
#endif
	}
}

//毎フレーム呼ぶ処理
void ShotEnemy::Step()
{
	if (!m_isActive)
	{
		return;
	}
	//MATRIX	mat1, mat2;
	//mat1 = MGetTranslate(m_Speed);
	//mat2 = MGetRotY(m_Rot);
	//mat1 = MMult(mat1, mat2);
	//m_Speed = VGet(mat1.m[3][0], mat1.m[3][1], mat1.m[3][2]);

	////座標に速度を加算
	m_Pos = VAdd(m_Pos,m_Speed);
	if (!m_waitflg)
	{
		m_waitTimer--;
		if (m_waitTimer < 0)
		{
			m_Speed.y = 7;
			m_Speed.x = -3;
		}
	}
	//一定範囲を超えたら消す
	float Length = 0.0f;
	if (m_Pos.y < -Length)
	{
		m_isActive = false;
	}

	//座標更新
	//MV1SetPosition(m_hndl, m_Pos);
}

//リクエスト
bool ShotEnemy::RequestShot(const VECTOR& Pos, const VECTOR& Speed)
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