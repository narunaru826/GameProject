#pragma once
#include<DxLib.h>
#include"../Player/Player.h"
class Life
{
private:
	int m_hndl;
	VECTOR m_Pos;
	float len;
public:
	Life();
	~Life();

	void Init();

	void Load();

	void Draw(Player &player);

	void Step();

	void Exit();
};