#include"Enemy1.h"
#include<math.h>
#include"../../Lib/Common.h"



//#define MY_DEBUG 

static const int ROOT_ID[] = { 1,2,3,4,5 };
static const int ROOT_NUM = 5;



//コンストラクタ
Enemy1::Enemy1()
{
	memset(&m_Pos, 0, sizeof(m_Pos));
	memset(&m_Speed, 0, sizeof(m_Speed));

	m_isActive = false;
	m_hndl = -1;
	m_Radius = RADIUS;
	m_EnemyLife = ENEMYLIFE;



	m_Scale = VGet(10.0f, 10.0f, 10.0f);

	m_enemyKillcount = 0;

	m_count = 0;
	m_Rand = GetRand(2);
}

//デストラクタ
Enemy1::~Enemy1()
{
	Exit();
}

//初期化
void Enemy1::Init()
{
	//memset(&m_Pos, 0, sizeof(m_Pos));
	memset(&m_Speed, 0, sizeof(m_Speed));

	m_isActive = false;
	m_hndl = -1;
	m_Radius = RADIUS;
	m_EnemyLife = ENEMYLIFE;


	m_Pos = VGet(0.0f,0.0f, 0.0f);
	m_Scale = VGet(10.0f, 10.0f, 10.0f);

	m_enemyKillcount = 0;

	m_count = 0;
	m_Rand = GetRand(2);
	
	x = -6.0f;
	y = 0.0f;
}

//ロード
void Enemy1::Load(int hndl)
{
	
}

//終了
void Enemy1::Exit()
{
	
}


//描画
void Enemy1::Draw()
{
	////生存フラグがオフの場合は終了
	//if (!m_isActive)
	//{
	//	return;
	//}
	m_Pos.x = WINDOW_SENTER_X + (int)(x * 50);
	m_Pos.y = WINDOW_SENTER_Y - (int)(y * 30);
	DrawCircle(x, y, 30, GetColor(0, 0, 255));
#ifdef MY_DEBUG
	VECTOR Pos = m_Pos;
	//Pos.y = m_Radius;
	DrawSphere3D(Pos, m_Radius, 16, GetColor(0, 255, 255), GetColor(0, 0, 0), FALSE);
#endif
}

//敵の生成要請
bool Enemy1::Request(const VECTOR& pos, const VECTOR& speed)
{
	//生存フラグがオンの場合は終了、エラーを外部に伝える
	if (m_isActive)
	{
		return false;
	}
	
	m_Pos = pos;
	m_Speed = speed;
	
	m_isActive = true;
	//出現成功を外部に伝える
	return true;
}


//毎フレーム
void Enemy1::Step()
{
	//生存フラグオフの場合は終了
	/*if (!m_isActive)
	{
		return;
	}*/
	/*m_Pos.x += 1;
	m_Pos.y = 5 * cosf(m_Pos.x) - cosf(5 * m_Pos.x);*/
	
	y = (25 * cosf(x) - cosf(25 * x) + 300);
	
	x += 0.03;
}
