#pragma once
#include<DxLib.h>
class BackGround
{
private:
	int m_hndl;

public:
	BackGround();
	~BackGround();

	void Init();
	void Load();
	void Draw();
	void Step();
	void Exit();


};