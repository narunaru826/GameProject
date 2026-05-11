#pragma once
#include"../Title/Title.h"
#include"../Play/Play.h"
#include"../Result/Result.h"
//#include"CommentScene.h"
#include"../GameOver/GameOver.h"
#include"time.h"

class SceneManager
{
private:
	enum tagSCENE {
		SCENE_TITLE,
		SCENE_COMMENT,
		SCENE_WAVE1,
		SCENE_WAVE2,
		SCENE_WAVE3,
		SCENE_WAVE4,
		SCENE_GAMEOVER,
		SCENE_RESULT,

		SCENE_NUM
	};
	TitleScene TitleScene;
	Play Play;

	ResultScene ResultScene;
	//CommentScene CommentScene;
	GameOverScene GameoverScene;
	//Time time;
	tagSCENE m_SceneID;	//	シーン保存

public:
	//コンストラクタ・デストラクタ
	SceneManager();
	~SceneManager();

	void Init();
	//繰り返し行う処理
	int Loop();
	//描画処理
	void Draw();


};