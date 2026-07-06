#include "SceneManager.h"
//#include "SoundManager.h"
#include "../../../lib/Common.h"
#include"../../../Lib//Fade/Fade.h"
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
	CFade::Init();

}
//毎フレーム処理
int SceneManager::Loop()
{
	int Ret = 0;
	CFade::Step();
	//switch
	switch (m_SceneID)
	{
	case SCENE_TITLE:
		if (TitleScene.Loop() != 0) {
			m_SceneID = SCENE_CHOICE;
		}

		break;

	case SCENE_CHOICE:
		if (m_choice.Loop() != 0) {
			
			m_SceneID = SCENE_STAGE1;
			
			
		}
		break;
	case SCENE_STAGE1:
		//SetMousePoint(SCREEN_HALF_SIZE_X, SCREEN_HALF_SIZE_Y);
		if (Play.Loop(m_choice) != 0)
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
	case SCENE_CHOICE:
		m_choice.Draw();
		break;
	case SCENE_STAGE1:
		Play.Draw();
		break;
	
	case SCENE_RESULT:
		ResultScene.Draw();
		break;
	case SCENE_GAMEOVER:
		GameoverScene.Draw();
		break;
	}
	CFade::Draw();
}