#include"Gameover.h"
//#include"CollisionManager.h"
//#include"SoundManager.h"
#include"../../../Lib/Input/Input.h"

//定義関連---------------------------

//-----------------------------------

//コンストラクタ
GameOverScene::GameOverScene()
{
	//ひとまず初期化
	m_SceneID = GAMEOVER_SCENE_INIT;

}


//デストラクタ
GameOverScene::~GameOverScene()
{
	//念のため
	Exit();
}

int GameOverScene::Loop()
{
	int Ret = 0;
	//ひとまずswitch分を利用
	switch (m_SceneID)
	{
	case GAMEOVER_SCENE_INIT:
		Init();
		m_SceneID = GAMEOVER_SCENE_LOAD;
		break;
	case GAMEOVER_SCENE_LOAD:
		Load();
		m_SceneID = GAMEOVER_SCENE_LOOP;
		break;
	case GAMEOVER_SCENE_LOOP:
		Step();
		if (IsInputTrg(KEY_CHOICE))
		{
			m_SceneID = GAMEOVER_SCENE_END;
		}
		break;
	case GAMEOVER_SCENE_END:
		Exit();
		m_SceneID = GAMEOVER_SCENE_INIT;
		m_resultcount = 0;
		Ret = 1;
		break;
	}
	return Ret;
}

//更新処理
void GameOverScene::Draw()
{
	switch (m_SceneID) {
	case GAMEOVER_SCENE_INIT:
	case GAMEOVER_SCENE_LOAD:
	case GAMEOVER_SCENE_LOOP:
	case GAMEOVER_SCENE_END:
		if (m_resultcount == 0) {
			DrawRotaGraph(1280 / 2, 720 / 2, 1.0f, 0.0f, m_hndl, TRUE);
		}

		DrawFormatString(640, 360, GetColor(255, 0, 0), "リザルト");
		break;
	}

}

//初期化
void GameOverScene::Init()
{
	m_hndl = -1;

	m_resultcount = 0;

}

//終了処理
void GameOverScene::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
	}
	m_hndl = -1;

}

//ロード
void GameOverScene::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("data/model/gameover.png");
	}


}

//毎フレーム呼ぶ処理
void GameOverScene::Step()
{


}