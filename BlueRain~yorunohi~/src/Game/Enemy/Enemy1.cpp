#include"Enemy1.h"
#include<math.h>
#include"../../Lib/Common.h"
#include"../../Lib/MyMath/MyMath.h"
#include<cmath>

//#define MY_DEBUG 



#define SHOTWAIT (0)
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
	m_shotwait = 0;

	m_count = 0;
	m_speed = VGet(0.0f,0.0f,0.0f);

	m_waitflg = false;
	m_waitTimer = 10;
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

	m_isActive = true;
	m_hndl = -1;
	m_Radius = RADIUS;
	m_EnemyLife = ENEMYLIFE;


	m_Pos = VGet(0.0f,0.0f, 0.0f);
	m_Scale = VGet(10.0f, 10.0f, 10.0f);

	m_enemyKillcount = 0;

	m_count = 0;
	m_Rand = GetRand(2);
	
	x = -1.7f;
	y = 0.0f;

	m_shotwait = 0;

	m_count = 0;

	m_speed = VGet(0.0f, 0.0f, 0.0f);

	m_waitflg = false;
	m_waitTimer = 10;

	m_Pos.x = WINDOW_SENTER_X + 300;
	m_Pos.y = WINDOW_SENTER_Y - 300;

	m_RequestCount = 220;

	m_RequestPostionState = 0;


}

//ロード
void Enemy1::Load()
{
	
}

//終了
void Enemy1::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}


//描画
void Enemy1::Draw()
{
	////生存フラグがオフの場合は終了
	//if (!m_isActive)
	//{
	//	return;
	//}
	if (m_isActive) {
		//DrawCircle(m_Pos.x, m_Pos.y, 30, GetColor(0, 0, 255));
	}
	//DrawFormatString(20, 20, GetColor(255, 0, 0), "弾が発射された数:%d", m_count);
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
void Enemy1::Step(ShotManager &shotmanager, Player& player)
{
	//生存フラグオフの場合は終了
	if (!m_isActive)
	{
		m_RequestCount--;
		if (m_RequestCount < 0) {
			m_Pos.x = WINDOW_SENTER_X;
			m_Pos.y = WINDOW_SENTER_Y;
			x = -1.7f;
			Request(m_Pos, m_Speed);

			m_RequestCount = 220;
		}
	}
	/*m_Pos.x += 1;
	m_Pos.y = 5 * cosf(m_Pos.x) - cosf(5 * m_Pos.x);*/
	//プレイヤー=======================================
	//関数一覧
	//y = WaveMove(x);
	
	y = HeartFunc(x);
	
	x += 0.025;
	
	switch (m_RequestPostionState)
	{
	case 0:
		m_Pos.x = ConvertX(x,50);
		m_Pos.y = ConvertY(y, 50) - 300;
		if (!m_isActive)
		{
			m_RequestPostionState = 1;
		}
		break;

	case 1:
		m_Pos.x = ConvertX(x,50) + 300;
		m_Pos.y = ConvertY(y,50) - 300;
		if (!m_isActive)
		{
			m_RequestPostionState = 2;
		}
		break;
	case 2:
		m_Pos.x = ConvertX(x,50) - 300;
		m_Pos.y = ConvertY(y,50) - 300;
		if (!m_isActive)
		{
			m_RequestPostionState = 0;
		}
		break;
	}
	
	//===================================================
	//弾の処理
	if (m_isActive) {
		m_shotwait--;
		if (m_shotwait < 0) {
			m_count++;
			shotmanager.RequestEnemyShot(m_Pos, m_speed);
			m_shotwait = SHOTWAIT;

		}
	}
	
	//移動制限
	if (m_Pos.x < -100 || m_Pos.x > 1030 ||
		m_Pos.y < 0 || m_Pos.y > 900)
	{
		m_isActive = false;
	}
	
}
