#include"Play.h"
#include"../../../Lib/Input/Input.h"
#include"../../CollisionManager/Collision.h"
#include"../../../Lib/Fade/Fade.h"
#include "../../Sound/SoundManager.h"
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
int Play::Loop(ChoiceScene choice)
{
	int Ret = 0;
	//ひとまずswitch分を利用
	switch (m_SceneID)
	{
	case PLAY_SCENE_INIT:

		SoundManager::Play(SoundManager::SOUNDID_BGM);
		Init();

		m_SceneID = PLAY_SCENE_LOAD;
		break;
	case PLAY_SCENE_LOAD:
		CFade::RequestFadeIn();
		Load();
		m_SceneID = PLAY_SCENE_LOOP;
		
		break;
	case PLAY_SCENE_LOOP:
		if (CFade::IsEndFadeIn(CFade::GetFadeId())) {
			if (choice.GetStagenum() == 1) {
				Step();
				m_EnemyManager.SetEnemyState(EnemyManager::ENEMY1);
			}
			if (choice.GetStagenum() == 2) {
				Step();
				m_EnemyManager.SetEnemyState(EnemyManager::ENEMY2);
			}
			if (choice.GetStagenum() == 3) {
				Step();
				m_EnemyManager.SetEnemyState(EnemyManager::ENEMY3);
			}
			if (choice.GetStagenum() == 4) {
				Step();
				m_EnemyManager.SetEnemyState(EnemyManager::BOSS);
			}
			if (choice.GetStagenum() == 5) {
				Step();
				m_EnemyManager.SetEnemyState(EnemyManager::ENEMY5);
			}
			if (choice.GetStagenum() == 6) {
				Step();
				m_EnemyManager.SetEnemyState(EnemyManager::ENEMY6);
			}
			if (choice.GetStagenum() == 7) {
				Step();
				m_EnemyManager.SetEnemyState(EnemyManager::BOSS);
			}
			
			if (CollisionManager::CheckHitPlayerToEnemy(m_Player, m_EnemyManager) == true
				|| CollisionManager::CheckHitPlayerToEnemy1Shot(m_Player, m_ShotManager) == true
				|| CollisionManager::CheckHitPlayerToBoss1Shot(m_Player, m_ShotManager)
				|| CollisionManager::CheckHitPlayerShotToBoss1(m_ShotManager, m_EnemyManager))
			{
				CFade::RequestFadeOut();
				m_SceneID = PLAY_SCENE_ENDWAIT;
			}
			if (CheckHitKey(KEY_INPUT_X)) {
				CFade::RequestFadeOut();
				flg = true;
				m_SceneID = PLAY_SCENE_ENDWAIT;
			}
			
		}
		break;
	
	case PLAY_SCENE_ENDWAIT:
		if (CFade::IsEndFadeOut(CFade::GetFadeId())) {
			m_SceneID = PLAY_SCENE_END;
		}
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
	//if (m_SceneID != PLAY_SCENE_LOOP)return;
	switch (m_SceneID) {
	case PLAY_SCENE_INIT:
	case PLAY_SCENE_LOAD:
	case PLAY_SCENE_LOOP:
	case PLAY_SCENE_ENDWAIT:
	case PLAY_SCENE_END:
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
void Play::Init()
{
	m_BackGround.Init();
	m_Player.Init();
	m_ShotManager.Init();
	
	m_EnemyManager.Init();
	
	m_life.Init();
}

//終了処理
void Play::Exit()
{
	m_BackGround.Exit();
	m_Player.Exit();
	m_ShotManager.Exit();
	m_EnemyManager.Exit();
	m_life.Exit();
}

//ロード
void Play::Load()
{
	m_BackGround.Load();
	m_Player.Load();
	m_ShotManager.Load();
	m_EnemyManager.Load();
	m_life.Load();
}



bool Play::Flg()
{
	return flg;
}


//毎フレーム呼ぶ処理
void Play::Step()
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

