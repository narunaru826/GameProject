#pragma once
#include <DxLib.h>
#include"../Shot/ShotManager.h"
//#include"ShotManager.h"
//#include"EnemyManager.h"
//#include"CameraManager.h"
#define SPEED (2)


class Player
{
public:


private:
	enum tagPlayerState {
		PLAYER_STATE_NORMAL,//待機、移動状態
		PLAYER_STATE_JUMP,//ジャンプ状態

		PLAYER_STATE_NUM,//状態の総数
	};
	

	
	VECTOR m_Pos;

	VECTOR m_MousePos;
	VECTOR m_Rot;
	VECTOR m_Speed;
	tagPlayerState m_State;
	int m_hndl;
	int m_shotWait;

	
	bool m_isActive;
	int m_PlayerLife;
	float m_gravity;
	bool flgchan;
	float camRotX;


	VECTOR Ene;
public:
	Player();
	~Player();

	void Init();
	void Init(VECTOR Pos, VECTOR Rot);

	void Load();

	void Step(ShotManager &shotmanager);
	void Update();

	void Draw();

	void Exit();

	//取得、設定関連
	inline VECTOR GetPosition()
	{
		return m_Pos;
	}
	VECTOR GetCenter();
	VECTOR GetTop();
	inline float GetRotateY()
	{
		return m_Rot.y;
	}
	inline float GetRotateX()
	{
		return camRotX;
	}
	void SetRot(VECTOR rot)
	{
		m_Rot = rot;
	}
	
	bool Hit();

	int GetPLHndl()
	{
		return m_hndl;
	}

	VECTOR GetSpd()
	{
		return m_Speed;
	}

	bool GetFlgchan()
	{
		return flgchan;
	}

	void SetFlgchan(bool flg)
	{
		flgchan = flg;
	}
	
};

