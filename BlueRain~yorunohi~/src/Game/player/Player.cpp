#include"Player.h"
#include"../../Lib/Input/Input.h"
//#include"../lib/Mouse.h"
#include"../../Lib/Common.h"

#include<math.h>

//定義関連

static const float ROTATE_SPEED = 0.01f;
static const float MOVE_SPEED = 4.0f;
static const float SLOW_SPEED = 2.0f;

#define SHOTWAIT (3)
#define SHOTSPEED (30)
#define RADIUS (10)
//#define MY_DEBUG
#define PL_LIFE (1000)
#define GRAVITY (0.09f)
//コンストラクタ
Player::Player()
{
	//ひとまず初期化
	memset(&m_Pos, 0, sizeof(VECTOR));
	memset(&m_Rot, 0, sizeof(VECTOR));
	memset(&m_Speed, 0, sizeof(VECTOR));
	m_State = PLAYER_STATE_NORMAL;
	m_hndl = -1;
	m_shotWait = 0;
	m_gravity = 0.0f;
}
//デストラクタ
Player::~Player()
{
	Exit();
}
//初期化
void Player::Init()
{
	Init(VGet(800.0f, 700.0f, 0.0f), VGet(0.0f, 0.0f, 0.0f));
	
	//ひとまず初期化
	
	memset(&m_Speed, 0, sizeof(VECTOR));
	m_State = PLAYER_STATE_NORMAL;
	m_hndl = -1;
	m_shotWait = 0;
	m_gravity = 0.0f;
}
//初期化
void Player::Init(VECTOR Pos, VECTOR Rot)
{
	m_Pos = Pos;
	m_Rot = Rot;
	memset(&m_Speed, 0, sizeof(VECTOR));
	m_State = PLAYER_STATE_NORMAL;

	m_Rot.y = (DX_PI_F / 180) * 180;
}

void Player::Load()
{
	

}

void Player::Step(ShotManager& shotmanager)
{
	//移動処理
	float spd = 0.0f;
	if (IsInputRep(KEY_CHOICE))
	{
		spd = SLOW_SPEED;
	}
	else
	{
		spd = MOVE_SPEED;
	}
	if (IsInputRep(KEY_LEFT))
	{
		m_Pos.x -= spd;
	}
	if (IsInputRep(KEY_RIGHT))
	{
		m_Pos.x += spd;
	}
	if (IsInputRep(KEY_UP))
	{
		m_Pos.y -= spd;
	}
	if (IsInputRep(KEY_DOWN))
	{
		m_Pos.y += spd;
	}
	
	//移動制限
	if (m_Pos.x < 0)
	{
		m_Pos.x = 0;
	}
	if (m_Pos.x > 1600)
	{
		m_Pos.x = 1600;
	}
	if (m_Pos.y < 0)
	{
		m_Pos.y = 0;
	}
	if (m_Pos.y > 900)
	{
		m_Pos.y = 900;
	}
	//弾ちゃん
	m_shotWait--;
	if (m_shotWait < 0)
	{
		shotmanager.RequestPlayerShot(VGet(m_Pos.x + 10, m_Pos.y - 10, 0.0f), SHOTSPEED);
		shotmanager.RequestPlayerShot(VGet(m_Pos.x - 10, m_Pos.y - 10,0.0f), SHOTSPEED);
		shotmanager.RequestPlayerShot(VGet(m_Pos.x + 30, m_Pos.y, 0.0f), SHOTSPEED);
		shotmanager.RequestPlayerShot(VGet(m_Pos.x - 30, m_Pos.y, 0.0f), SHOTSPEED);
		m_shotWait = SHOTWAIT;
	}
	
	

	//m_Pos = VAdd(m_Pos, m_Speed);
	
}

void Player::Update()
{
	
	
}
void Player::Draw()
{
	DrawCircle(m_Pos.x, m_Pos.y, 16, GetColor(255, 255, 0));
}

void Player::Exit()
{
	
}
//当たった
bool Player::Hit()
{
	return true;
}


