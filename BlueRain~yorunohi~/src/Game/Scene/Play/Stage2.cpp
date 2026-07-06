#include"Stage2.h"
#include"../../../Lib/Input/Input.h"
#include"../../CollisionManager/Collision.h"
#include"../../../Lib/Fade/Fade.h"
//定義関連---------------------------
#define D2R(deg) ((deg)*DX_PI_F/180.0f)
//-----------------------------------

//コンストラクタ
Stage2::Stage2()
{
	//ひとまず初期化
	m_SceneID = STAGE2_SCENE_INIT;



}


//デストラクタ
Stage2::~Stage2()
{
	//念のため
	Exit();
}
void Stage2::InitScene()
{


}
int Stage2::Loop()
{
	int Ret = 0;
	//ひとまずswitch分を利用
	switch (m_SceneID)
	{
	case STAGE2_SCENE_INIT:


		Init();

		m_SceneID = STAGE2_SCENE_LOAD;
		break;
	case STAGE2_SCENE_LOAD:
		CFade::RequestFadeIn();
		Load();
		m_SceneID = STAGE2_SCENE_LOOP;

		break;
	case STAGE2_SCENE_LOOP:
		if (CFade::IsEndFadeIn(CFade::GetFadeId())) {
			Step();

			if (CollisionManager::CheckHitPlayerToEnemy(m_Player, m_EnemyManager) == true
				|| CollisionManager::CheckHitPlayerToEnemy1Shot(m_Player, m_ShotManager) == true
				|| CollisionManager::CheckHitPlayerToBoss1Shot(m_Player, m_ShotManager)
				|| CollisionManager::CheckHitPlayerShotToBoss1(m_ShotManager, m_EnemyManager))
			{
				CFade::RequestFadeOut();
				m_SceneID = STAGE2_SCENE_ENDWAIT;
			}
			if (CheckHitKey(KEY_INPUT_X)) {
				CFade::RequestFadeOut();
				flg = true;
				m_SceneID = STAGE2_SCENE_ENDWAIT;
			}

		}
		break;

	case STAGE2_SCENE_ENDWAIT:
		if (CFade::IsEndFadeOut(CFade::GetFadeId())) {
			m_SceneID = STAGE2_SCENE_END;
		}
		break;
	case STAGE2_SCENE_END:
		Exit();


		m_SceneID = STAGE2_SCENE_INIT;
		Ret = 1;
		break;

	}



	return Ret;
}

//更新処理
void Stage2::Draw()
{
	//if (m_SceneID != PLAY_SCENE_LOOP)return;
	switch (m_SceneID) {
	case STAGE2_SCENE_INIT:
	case STAGE2_SCENE_LOAD:
	case STAGE2_SCENE_LOOP:
	case STAGE2_SCENE_ENDWAIT:
	case STAGE2_SCENE_END:
		m_BackGround.Draw();
		m_Player.Draw();
		m_ShotManager.Draw();
		/*m_Enemy1.Draw();
		m_Enemy2.Draw();
		m_Enemy3.Draw();*/
		m_EnemyManager.Draw();

		m_life.Draw(m_Player);
		DrawFormatString(640, 360, GetColor(255, 0, 0), "プレイ");
		break;
	}
}

//初期化
void Stage2::Init()
{
	m_BackGround.Init();
	m_Player.Init();
	m_ShotManager.Init();

	m_EnemyManager.Init();

	m_life.Init();
}

//終了処理
void Stage2::Exit()
{
	m_BackGround.Exit();
	m_Player.Exit();
	m_EnemyManager.Exit();
	m_life.Exit();
}

//ロード
void Stage2::Load()
{
	m_BackGround.Load();
	m_Player.Load();
	m_EnemyManager.Load();
	m_life.Load();
}

//毎フレーム呼ぶ処理
void Stage2::Step()
{
	m_BackGround.Step();
	m_Player.Step(/*m_ShotManager*/);
	m_ShotManager.Step(m_Player);

	/*m_Enemy1.Step(m_ShotManager, m_Player);
	m_Enemy2.Step(m_ShotManager, m_Player);
	m_Enemy3.Step(m_ShotManager,m_Player);*/
	m_EnemyManager.Step(m_Player, m_ShotManager);
	m_life.Step();
}

bool Stage2::Flg()
{
	return flg;
}
