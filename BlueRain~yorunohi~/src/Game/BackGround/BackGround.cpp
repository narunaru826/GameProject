#include"BackGround.h"
#include"../../Lib/Common.h"
BackGround::BackGround()
{
	m_hndl = -1;
}

BackGround::~BackGround()
{
	Exit();
}

void BackGround::Init()
{
	m_hndl = -1;
	m_hndl2 = -1;
	m_Pos.x = WINDOW_SIZE_X * 0.28;
	m_Pos.y = WINDOW_SIZE_Y * 0.5;
	m_Pos.z = 0.0f;
}

void BackGround::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("Data/BG.png");
	}
	if (m_hndl2 == -1)
	{
		m_hndl2 = LoadGraph("Data/scoreBG.png");
	}
}

void BackGround::Draw()
{
	DrawRotaGraph(m_Pos.x, m_Pos.y, 1.0f, 0.0f, m_hndl, TRUE);

	DrawRotaGraph((int)m_Pos.x, (int)(m_Pos.y - 900), 1.0f, 0.0f, m_hndl, TRUE);
	DrawRotaGraph(WINDOW_SENTER_X + 447, WINDOW_SENTER_Y, 1.0f, 0.0f, m_hndl2, TRUE);

	
}

void BackGround::Step()
{
	m_Pos.y += 1.0f;

	if (m_Pos.y >= 900 * 0.5 + 900)
	{
		m_Pos.y -= 900;
	}
}

void BackGround::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
	if (m_hndl2 != -1)
	{
		DeleteGraph(m_hndl2);
		m_hndl2 = -1;
	}
}