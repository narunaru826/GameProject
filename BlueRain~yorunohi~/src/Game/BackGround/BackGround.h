#pragma once
#include<DxLib.h>
class BackGround
{
private:
	int m_hndl;
	int m_hndl2;
	VECTOR m_Pos;

public:
	BackGround();
	~BackGround();

	void Init();
	void Load();
	void Draw();
	void Step();
	void Exit();


};