#include"Life.h"

Life::Life()
{
	m_hndl = -1;
	m_Pos = VGet(1100, 450, 0);
}

Life::~Life()
{
	Exit();
}

void Life::Init()
{
	m_hndl = -1;
	m_hndl2 = -1;
	m_Pos = VGet(1100, 450, 0);
	len = 0;
}

void Life::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("Data/life.PNG");
	}
	if (m_hndl2 == -1)
	{
		m_hndl2 = LoadGraph("Data/life.PNG");
	}
}

void Life::Draw(Player &player)
{
	len = 0;
	for (int i = 0; i < player.GetPlayerLife(); i++) {
		DrawRotaGraph((int)m_Pos.x + len, m_Pos.y, 0.05f, 0.0f, m_hndl, TRUE);
		len += 20;
	}
	
}

void Life::Step()
{

}

void Life::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}