#include"Object.h"
#include"../../Lib/Common.h"

Object::Object()
{
	memset(&m_Pos, 0, sizeof(m_Pos));
	memset(&m_Speed, 0, sizeof(m_Speed));

	m_isActive = false;
	m_hndl = -1;
	m_Radius = RADIUS;
	//m_EnemyLife = ENEMYLIFE;



	m_Scale = VGet(10.0f, 10.0f, 10.0f);

	m_enemyKillcount = 0;

	m_count = 0;
	m_Rand = GetRand(2);
}

Object::~Object()
{
	Exit();
}

void Object::Init()
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
void Object::Load()
{

}

void Object::Step()
{

}

void Object::Draw()
{
	
}

void Object::Exit()
{
	
}

