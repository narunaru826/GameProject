#include "ChoiceScene.h"
#include "../../../Lib/Common.h"
#include "../../../Lib/Fade/Fade.h"
//#include "TitleFade.h"
#include"../../../Lib/Fade/Fade.h"
#include "../../../Lib/Input/Input.h"
#include "../../Sound/SoundManager.h"







//定義関連---------------------------

//-----------------------------------

//コンストラクタ
ChoiceScene::ChoiceScene()
{
	//ひとまず初期化
	m_SceneID = CHOICE_SCENE_INIT;
}


//デストラクタ
ChoiceScene::~ChoiceScene()
{
	//念のため
	Exit();
}

int ChoiceScene::Loop()
{
	int Ret = 0;
	//ひとまずswitch分を利用
	switch (m_SceneID)
	{
	case CHOICE_SCENE_INIT:
		Init();
		m_SceneID = CHOICE_SCENE_LOAD;
		break;

	case CHOICE_SCENE_LOAD:
		CFade::RequestFadeIn();
		Load();
		m_SceneID = CHOICE_SCENE_LOOP;
		break;

	case CHOICE_SCENE_LOOP:
		if (CFade::IsEndFadeIn(CFade::GetFadeId())) {
			Step();
			if (m_Stagenum >= 1 && m_Stagenum <= 7)
			{
				CFade::RequestFadeOut();
				m_SceneID = CHOICE_SCENE_ENDWAIT;
			}
		}
		break;

	case CHOICE_SCENE_ENDWAIT:
		if (CFade::IsEndFadeOut(CFade::GetFadeId())) {
			m_SceneID = CHOICE_SCENE_END;
		}
		break;
	case CHOICE_SCENE_END:
		Exit();
		
		//SoundManager::StopAll();

			m_SceneID = CHOICE_SCENE_INIT;
			Ret = 1;
			break;
		
	}
	return Ret;
}

//更新処理
void ChoiceScene::Draw()
{
	switch (m_SceneID) {
	case CHOICE_SCENE_INIT:
	case CHOICE_SCENE_LOAD:
	case CHOICE_SCENE_LOOP:
	case CHOICE_SCENE_END:
	case CHOICE_SCENE_ENDWAIT:
		DrawRotaGraph(1600 / 2, 900 / 2, 1.0f, 0.0f, m_hndl, TRUE);
		DrawFormatString(40, 30, GetColor(255, 0, 0), "選択");
		break;
	}

}

//初期化
void ChoiceScene::Init()
{
	m_hndl = -1;
	
	m_Stagenum = CHOICE_WAIT;
}

//終了処理
void ChoiceScene::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
	}
	m_hndl = -1;
}

//ロード
void ChoiceScene::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("Data/Choise.jpg");
	}
}

//毎フレーム呼ぶ処理
void ChoiceScene::Step()
{
	if (CheckHitKey(KEY_INPUT_1))
	{
		m_Stagenum = CHOICE_1;
	}
	if (CheckHitKey(KEY_INPUT_2))
	{
		m_Stagenum = CHOICE_2;
	}
	if (CheckHitKey(KEY_INPUT_3))
	{
		m_Stagenum = CHOICE_3;
	}
	if (CheckHitKey(KEY_INPUT_4))
	{
		m_Stagenum = CHOICE_4;
	}
	if (CheckHitKey(KEY_INPUT_5))
	{
		m_Stagenum = CHOICE_5;
	}
	if (CheckHitKey(KEY_INPUT_6))
	{
		m_Stagenum = CHOICE_6;
	}
	if (CheckHitKey(KEY_INPUT_7))
	{
		m_Stagenum = CHOICE_7;
	}
}