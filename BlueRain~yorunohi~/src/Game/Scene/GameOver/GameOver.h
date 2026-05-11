#pragma once
#include<DxLib.h>
class GameOverScene
{
private:
	enum tagGAMEOVER_SCENE {
		GAMEOVER_SCENE_INIT,
		GAMEOVER_SCENE_LOAD,
		GAMEOVER_SCENE_LOOP,
		GAMEOVER_SCENE_END,

		GAMEOVER_SCENE_NUM,

	};

	int m_hndl;

	int m_resultcount;
	tagGAMEOVER_SCENE m_SceneID;	//シーン保存

public:
	//コンストラクタ・デストラクタ
	GameOverScene();
	~GameOverScene();

	//繰り返し行う処理
	int Loop();
	//描画処理
	void Draw();
	void SetResultCount(int result)
	{
		m_resultcount = result;
	}

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
