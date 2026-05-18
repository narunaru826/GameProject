#include"Play.h"
#include"../../../Lib/Input/Input.h"
//定義関連---------------------------
#define D2R(deg) ((deg)*DX_PI_F/180.0f)
//-----------------------------------

//コンストラクタ
Play::Play()
{
	//ひとまず初期化
	m_SceneID = PLAY_SCENE_INIT;
	


}


//デストラクタ
Play::~Play()
{
	//念のため
	Exit();
}
void Play::InitScene()
{
	

}
int Play::Loop()
{
	int Ret = 0;
	//ひとまずswitch分を利用
	switch (m_SceneID)
	{
	case PLAY_SCENE_INIT:

		
		Init();

		m_SceneID = PLAY_SCENE_LOAD;
		break;
	case PLAY_SCENE_LOAD:
		
		Load();
		
		m_SceneID = PLAY_SCENE_LOOP;
		break;
	case PLAY_SCENE_LOOP:

		Step();

		
		if (CheckHitKey(KEY_INPUT_X)) {
			flg = true;
			m_SceneID = PLAY_SCENE_ENDWAIT;
		}
		/*if (IsInputTrg(KEY_INPUT_C)) {
			flg = false;
			m_SceneID = PLAY_SCENE_ENDWAIT;
		}*/

	
		
		/*if (time.IsTimeUp())
		{
			flg = true;
			endcount = 30;
			m_SceneID = PLAY_SCENE_ENDWAIT;
		}*/
		break;
	case PLAY_SCENE_ENDWAIT:
		Step();
		
		
		m_SceneID = PLAY_SCENE_END;
		
		break;
	case PLAY_SCENE_END:
		Exit();
		m_SceneID = PLAY_SCENE_INIT;

		Ret = 1;




		break;

	}



	return Ret;
}

//更新処理
void Play::Draw()
{
	if (m_SceneID != PLAY_SCENE_LOOP)return;

	m_BackGround.Draw();
	m_Player.Draw();
	m_ShotManager.Draw();
	m_Enemy1.Draw();
	DrawFormatString(640, 360, GetColor(255, 0, 0), "プレイ");
}

//初期化
void Play::Init()
{
	m_BackGround.Init();
	m_Player.Init();
	m_ShotManager.Init();
	m_Enemy1.Init();
}

//終了処理
void Play::Exit()
{
	m_BackGround.Exit();
}

//ロード
void Play::Load()
{
	m_BackGround.Load();
}

//毎フレーム呼ぶ処理
void Play::Step()
{
	m_BackGround.Step();
	m_Player.Step(m_ShotManager);
	m_ShotManager.Step();
	m_Enemy1.Step(m_ShotManager,m_Player);
}

bool Play::Flg()
{
	return flg;
}
