#pragma once
#include<DxLib.h>
#include"../../../Game/player/Player.h"
#include"../../../Game/Shot/ShotManager.h"
#include"../../Enemy/Enemy1.h"
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
	Player m_Player;
	ShotManager m_ShotManager;
	Enemy1 m_Enemy1;
	tagPLAY_SCENE m_SceneID;	//シーン保存
public:
	//コンストラクタ・デストラクタ
	Play();
	~Play();

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
