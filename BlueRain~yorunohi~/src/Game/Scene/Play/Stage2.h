#pragma once

#include<DxLib.h>
#include"../../../Game/player/Player.h"
#include"../../../Game/Shot/ShotManager.h"
#include"../../Enemy/Enemy1.h"
#include"../../Enemy/Enemy2.h"
#include"../../Enemy/Enemy3.h"
#include"../../Enemy/Boss1.h"
#include"../../Enemy/EnemyManager.h"
#include"../../BackGround/BackGround.h"
#include"../../Life/Life.h"
class Stage2
{
private:
	enum tagSTAGE2_SCENE {
		STAGE2_SCENE_INIT,
		STAGE2_SCENE_LOAD,
		STAGE2_SCENE_LOOP,
		STAGE2_SCENE_END,
		STAGE2_SCENE_ENDWAIT,


		STAGE2_SCENE_NUM,

	};
	bool flg;
	Player m_Player;
	ShotManager m_ShotManager;
	Enemy1 m_Enemy1;
	Enemy2 m_Enemy2;
	Enemy3 m_Enemy3;
	Boss1 m_Boss1;
	BackGround m_BackGround;
	EnemyManager m_EnemyManager;
	Life m_life;
	tagSTAGE2_SCENE m_SceneID;	//シーン保存
public:
	//コンストラクタ・デストラクタ
	Stage2();
	~Stage2();

	void InitScene();
	//繰り返し行う処理
	int Loop();
	//描画処理
	void Draw();

	bool Flg();

private:
	//初期化
	void Init(void);
	//終了処理
	void Exit();
	//データロード
	void Load();
	//毎フレーム呼ぶ処理
	void Step();


};
