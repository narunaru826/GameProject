#include "Result.h"
#include "../../../Lib/Common.h"
#include "../../../Lib/Fade/Fade.h"
#include "../../../Lib/Input/Input.h"
//#include "../../../Lib/Admin/Data.h"
//#include "../../System/Sound/SoundManager.h"


//コンストラクタ
ResultScene::ResultScene()
{
	//ひとまず初期化
	m_SceneID = RESULT_SCENE_INIT;

}


//デストラクタ
ResultScene::~ResultScene()
{
	//念のため
	Exit();
}

int ResultScene::Loop()
{
	int Ret = 0;
	//ひとまずswitch分を利用
	switch (m_SceneID)
	{
	case RESULT_SCENE_INIT:
		Init();
		m_SceneID = RESULT_SCENE_LOAD;
		break;
	case RESULT_SCENE_LOAD:
		Load();
		m_SceneID = RESULT_SCENE_LOOP;
		break;
	case RESULT_SCENE_LOOP:
		Step();
		if (CheckHitKey(KEY_INPUT_C))
		{
			m_SceneID = RESULT_SCENE_END;
		}
		break;
	case RESULT_SCENE_END:
		Exit();
		m_SceneID = RESULT_SCENE_INIT;
		m_resultcount = 0;
		Ret = 1;
		break;
	}
	return Ret;
}

//更新処理
void ResultScene::Draw()
{
	switch (m_SceneID) {
	case RESULT_SCENE_INIT:
	case RESULT_SCENE_LOAD:
	case RESULT_SCENE_LOOP:
	case RESULT_SCENE_END:
		if (m_resultcount == 0) {
			DrawRotaGraph(1280 / 2, 720 / 2, 1.0f, 0.0f, m_hndl, TRUE);
		}
		if (m_resultcount == 1)
		{
			DrawRotaGraph(1280 / 2, 720 / 2, 1.0f, 0.0f, m_gameoverhndl, TRUE);
		}
		DrawFormatString(640, 360, GetColor(255, 0, 0), "リザルト");
		break;
	}

}

//初期化
void ResultScene::Init()
{
	m_hndl = -1;
	m_gameoverhndl = -1;
	m_resultcount = 0;

}

//終了処理
void ResultScene::Exit()
{
	if (m_hndl != -1)
	{
		DeleteGraph(m_hndl);
	}
	m_hndl = -1;
	if (m_gameoverhndl != -1)
	{
		DeleteGraph(m_gameoverhndl);
	}
	m_gameoverhndl = -1;
}

//ロード
void ResultScene::Load()
{
	if (m_hndl == -1)
	{
		m_hndl = LoadGraph("data/model/result.png");
	}

	if (m_gameoverhndl == -1)
	{
		m_gameoverhndl = LoadGraph("data/model/gameover.png");
	}
}

//毎フレーム呼ぶ処理
void ResultScene::Step()
{


}