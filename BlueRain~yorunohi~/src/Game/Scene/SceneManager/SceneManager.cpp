#include "SceneManager.h"
//#include "SoundManager.h"
#include "../../../lib/Common.h"

//定義関連-----------------------

//-------------------------------

//コンストラクタ
SceneManager::SceneManager()
{
	m_SceneID = SCENE_TITLE;

	//SoundManager::Init();
	//SoundManager::LoadAllData();
}

//デストラクタ
SceneManager::~SceneManager()
{
	//SoundManager::Exit();
}
void SceneManager::Init()
{

	Play.InitScene();


}
//毎フレーム処理
int SceneManager::Loop()
{
	int Ret = 0;
	//switch
	switch (m_SceneID)
	{
	case SCENE_TITLE:
		if (TitleScene.Loop() != 0) {
			m_SceneID = SCENE_WAVE1;
		}

		break;

	case SCENE_COMMENT:
		/*if (CommentScene.Loop() != 0) {
			m_SceneID = SCENE_WAVE1;
		}*/
		break;
	case SCENE_WAVE1:
		//SetMousePoint(SCREEN_HALF_SIZE_X, SCREEN_HALF_SIZE_Y);
		if (Play.Loop() != 0)
		{
			if (Play.Flg()) {
				m_SceneID = SCENE_RESULT;
			}
			else
			{
				m_SceneID = SCENE_GAMEOVER;
			}
		}


		break;
	case SCENE_WAVE2:


		break;
	case SCENE_WAVE3:
		m_SceneID = SCENE_WAVE4;
		break;
	case SCENE_WAVE4:
		m_SceneID = SCENE_RESULT;

		break;
	case SCENE_RESULT:
		//SoundManager::Stop(SoundManager::SOUNDID_BGM);
		if (ResultScene.Loop() != 0) {
			m_SceneID = SCENE_TITLE;
		}
		break;
	case SCENE_GAMEOVER:
		//SoundManager::Stop(SoundManager::SOUNDID_BGM);
		if (GameoverScene.Loop() != 0) {
			m_SceneID = SCENE_TITLE;
		}
		break;
	}
	return Ret;
}

//更新
void SceneManager::Draw()
{
	switch (m_SceneID)
	{
	case SCENE_TITLE:
		TitleScene.Draw();
		break;
	case SCENE_COMMENT:
		//CommentScene.Draw();
		break;
	case SCENE_WAVE1:
		Play.Draw();
		break;
	case SCENE_WAVE2:

		break;
	case SCENE_RESULT:
		ResultScene.Draw();
		break;
	case SCENE_GAMEOVER:
		GameoverScene.Draw();
		break;
	}
}