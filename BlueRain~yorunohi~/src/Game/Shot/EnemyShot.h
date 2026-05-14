#pragma once
#include<DxLib.h>

class ShotEnemy
{
private:
	VECTOR m_Pos;		//座標
	VECTOR m_Speed;		//移動速度
	VECTOR m_Rot;
	float m_Radius;		//移動速度
	int m_hndl;			//モデルハンドル
	bool m_isActive;	//生存フラグ

	bool m_waitflg;
	int m_waitTimer;

public:
	//コンストラクタ・デストラクタ
	ShotEnemy();
	~ShotEnemy();

	//初期化
	void Init();

	//データロード
	void Load(int hndl);
	//終了処理
	void Exit();
	//毎フレーム呼ぶ処理
	void Step();
	//描画
	void Draw();


	//リクエスト
	//@Pos		:	初期座標
	//Speed		:	移動速度
	//@return	:	true = リクエスト成功　false = 失敗
	bool RequestShot(const VECTOR& Pos, const VECTOR& Speed);
	//生存判定
	//@return	:	true = 生存　false = 死亡
	bool IsActive()
	{
		return m_isActive;
	}
	//座標取得
	void GetPosition(VECTOR& Pos)
	{
		Pos = m_Pos;
	}

	//半径取得
	float GetRadius(void)
	{
		return m_Radius;
	}
	void Hit();

	int GetHndl()
	{
		return m_hndl;
	}
};