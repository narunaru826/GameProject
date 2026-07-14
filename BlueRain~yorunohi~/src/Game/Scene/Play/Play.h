#pragma once
#include<DxLib.h>
#include"../../../Game/player/Player.h"
#include"../../../Game/Shot/ShotManager.h"
#include"../../Enemy/Enemy1.h"
#include"../../Enemy/Enemy2.h"
#include"../../Enemy/Enemy3.h"
#include"../../Enemy/Boss1.h"
#include"../../Object/Object.h"
#include"../../Enemy/EnemyManager.h"
#include"../../BackGround/BackGround.h"
#include"../../Life/Life.h"
#include"../Choice/ChoiceScene.h"
class Play
{
private:
	enum tagPLAY_SCENE {
		PLAY_SCENE_INIT,
		PLAY_SCENE_LOAD,
		PLAY_SCENE_LOOP,
		PLAY_SCENE_END,
		PLAY_SCENE_ENDWAIT,
		

		PLAY_SCENE_NUM,

	};
	bool flg;
	Object m_obj;
	Player m_Player;
	ShotManager m_ShotManager;
	Enemy1 m_Enemy1;
	Enemy2 m_Enemy2;
	Enemy3 m_Enemy3;
	Boss1 m_Boss1;
	BackGround m_BackGround;
	EnemyManager m_EnemyManager;
	Life m_life;
	tagPLAY_SCENE m_SceneID;	//シーン保存
public:
	//コンストラクタ・デストラクタ
	Play();
	~Play();

	void InitScene();
	//繰り返し行う処理
	int Loop(ChoiceScene choice);
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
	void Step2();
	void Step3();
	void Step4();
	void Step5();
	void Step6();
	void Step7();


};
