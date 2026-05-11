#pragma once
#include"PLShot.h"

#define PL_SHOT_NUM (1000)
#define TURRET_SHOT_NUM (1000)
#define ENE_SHOTGUID_NUM (300)

class ShotManager
{
private:
	//プレイヤーのショット
	ShotPL PlayerShot[PL_SHOT_NUM];
	


	float m_Rot;
	int m_hndl;
	

public:
	//コンストラクタ・デストラクタ
	ShotManager();
	~ShotManager();

	//初期化
	void Init();
	//データロード
	void Load();
	//終了処理
	void Exit();
	//繰り返し行う処理
	void Step();
	//描画
	void Draw();

	//プレイヤーのショットリクエスト
	void RequestPlayerShot(const VECTOR& Pos, const float& Speed);


	
	//プレイヤーのショットの情報取得
	ShotPL& GetPlayerShot(int ID)
	{
		return PlayerShot[ID];
	}

	

};