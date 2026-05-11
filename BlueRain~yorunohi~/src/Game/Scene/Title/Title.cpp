#include "Title.h"
#include "../../../Lib/Common.h"
#include "../../../Lib/Fade/Fade.h"
//#include "TitleFade.h"
#include "../../../Lib/Input/Input.h"
//#include "../../System/Sound/SoundManager.h"







//定義関連---------------------------

//-----------------------------------

//コンストラクタ
TitleScene::TitleScene()
{
	//ひとまず初期化
	m_SceneID = TITLE_SCENE_INIT;
}


//デストラクタ
TitleScene::~TitleScene()
{
	//念のため
	Exit();
}

int TitleScene::Loop()
{
	int Ret = 0;
	//ひとまずswitch分を利用
	switch (m_SceneID)
	{
	case TITLE_SCENE_INIT:
		Init();
		m_SceneID = TITLE_SCENE_LOAD;
		break;
	case TITLE_SCENE_LOAD:
		Load();
		m_SceneID = TITLE_SCENE_LOOP;
		break;
	case TITLE_SCENE_LOOP:
		Step();
		if (IsInputTrg(KEY_CHOICE))
		{
			m_SceneID = TITLE_SCENE_END;
		}
		break;
	case TITLE_SCENE_END:
		Exit();
		
		m_SceneID = TITLE_SCENE_INIT;
		Ret = 1;
		break;
	}
	return Ret;
}

//更新処理
void TitleScene::Draw()
{
	switch (m_SceneID) {
	case TITLE_SCENE_INIT:
	case TITLE_SCENE_LOAD:
	case TITLE_SCENE_LOOP:
	case TITLE_SCENE_END:
		DrawRotaGraph(1280 / 2, 720 / 2, 1.0f, 0.0f, m_hndl, TRUE);
		DrawFormatString(40, 30, GetColor(255, 0, 0), "タイトル");
		break;
	}

}

//初期化
void TitleScene::Init()
{
	m_hndl = -1;
}

//終了処理
void TitleScene::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
	}
	m_hndl = -1;
}

//ロード
void TitleScene::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("data/model/title.png");
	}
}

//毎フレーム呼ぶ処理
void TitleScene::Step()
{

}