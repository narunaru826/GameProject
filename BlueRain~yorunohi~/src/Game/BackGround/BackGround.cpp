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
}

void BackGround::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("Data/ScoreBG.png");
	}
}

void BackGround::Draw()
{
	DrawRotaGraph(WINDOW_SENTER_X + 600, WINDOW_SENTER_Y, 1.0f, 0.0f, m_hndl, TRUE);
}

void BackGround::Step()
{

}

void BackGround::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
		m_hndl = -1;
	}
}