#pragma once
#include<DxLib.h>
class Object
{
protected:
	VECTOR m_Pos;		//座標
	VECTOR m_Speed;		//移動方向と速度
	VECTOR m_Scale;
	float m_Radius;


	int m_hndl;			//モデルハンドル
	bool m_isActive;	//生存フラグ
	int m_EnemyLife;		//エネミーの体力

	int m_enemyKillcount;
	int m_count;
	int m_Rand;

	enum tagPlayerState {
		ENEMY_STATE_NORMAL,//待機、移動状態
		ENEMY_STATE_JUMP,//ジャンプ状態

		ENEMY_STATE_NUM,//状態の総数
	};
	typedef struct
	{
		float frame;		//再生中のフレーム
		float endflame;		//再生中のアニメの最終フレーム
		float speed;		//アニメの再生速度
		int hndl;			//アニメーション用のハンドル

		int ID;				//再生中のID
		int state;			//ループORストップ


	}ANIME_DATA;

	
public:
	Object();
	~Object();

	virtual void Init();
	virtual void Load();
	virtual void Step();
	virtual void Draw();
	virtual void Exit();

	//敵の座標取得
	void GetPos(VECTOR& Pos)
	{
		Pos = m_Pos;
	}

	//敵の生存判定
	bool IsActive()
	{
		return m_isActive;
	}
	//敵の生存判定
	void SetIsActive(bool flg)
	{
		m_isActive = flg;
	}
	//半径取得
	float GetRadius(void)
	{
		return m_Radius;
	}
	


	int GetEnemyLife()
	{
		return m_EnemyLife;
	}
	void SetEnemyLife(int life)
	{
		m_EnemyLife = life;
	}
	int GetHndl()
	{
		return m_hndl;
	}


	

};