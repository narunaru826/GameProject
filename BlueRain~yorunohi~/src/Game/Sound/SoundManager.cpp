#include"SoundManager.h"

int SoundManager::m_hndl[SOUNDID_NUM];

//コンストラクタ
SoundManager::SoundManager()
{
	for (int i = 0; i < SOUNDID_NUM; i++)
	{
		m_hndl[i] = -1;
	}
}

//デストラクタ
SoundManager::~SoundManager()
{
	Exit();
}

//初期化
void SoundManager::Init(void)
{
	for (int i = 0; i < SOUNDID_NUM; i++)
	{
		m_hndl[i] = -1;
	}
}

void SoundManager::Exit(void)
{
	for (int i = 0; i < SOUNDID_NUM; i++)
	{
		if (m_hndl[i] != -1) {
			DeleteSoundMem(m_hndl[i]);
			m_hndl[i] = -1;
		}
	}
}

//全データ読み込み
bool SoundManager::LoadAllData()
{
	bool isRet = true;
	const char FileName[SOUNDID_NUM][128] =
	{
		"data/sound/mainBGM.mp3",
		"data/sound/title.mp3",

		"data/sound/ShotGun.mp3",
		"data/sound/assault.m4a",
		"data/sound/enemy.m4a",

		"data/sound/yakkyou.mp3",


		"data/sound/enemy.m4a",
		"data/sound/se_ex_explore.mp3",

		"data/sound/ShotgunReload.mp3",
		"data/sound/AssaultReload.mp3",
		"data/sound/MinigunReload.mp3"
	};

	for (int i = 0; i < SOUNDID_NUM; i++)
	{
		m_hndl[i] = LoadSoundMem(FileName[i]);
		//一つでも失敗があればフラグオフに
		if (m_hndl[i] == -1)
		{
			isRet = false;
		}
	}
	return isRet;
}
//再生時間取得
int SoundManager::GetSoundTime(tagSoundID ID)
{
	return GetSoundCurrentTime(m_hndl[ID]);
}

//再生総時間取得
int SoundManager::GetSoundAllTime(tagSoundID ID)
{
	return GetSoundTotalTime(m_hndl[ID]);
}

//音楽再生判定
bool SoundManager::IsPlay(tagSoundID ID)
{
	return CheckSoundMem(m_hndl[ID]) == 1 ? true : false;
}

//再生開始時間設定
void SoundManager::SetStartFrame(tagSoundID ID, int ms)
{
	//指定IDの周波数を取得して設定
	int Freq = GetFrequencySoundMem(m_hndl[ID]) * ms / 1000;
	SetCurrentPositionSoundMem(Freq, m_hndl[ID]);
}

//ボリューム
void SoundManager::SetVolume(tagSoundID ID, float vol)
{
	if (vol < 0.f || vol > 1.f)
	{
		return;
	}
	ChangeVolumeSoundMem((int)(255.f * vol), m_hndl[ID]);
}

//音楽再生
int SoundManager::Play(tagSoundID ID, int Type, bool isStart)
{
	return PlaySoundMem(m_hndl[ID], Type, isStart);
}

//音楽停止
int SoundManager::Stop(tagSoundID ID)
{
	return StopSoundMem(m_hndl[ID]);
}

//全音楽停止
void SoundManager::StopAll(void)
{
	for (int i = 0; i, SOUNDID_NUM; i++)
	{
		StopSoundMem(m_hndl[i]);
	}
}