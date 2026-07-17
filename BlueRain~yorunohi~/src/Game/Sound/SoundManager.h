#pragma once
#include<DxLib.h>

//サウンド操作クラス
class SoundManager
{
public:
	enum tagSoundID {
		SOUNDID_BGM,
		SOUNDID_TITLE,

		SOUNDID_SE_SHOTGUN,
		SOUNDID_SE_ASSAULT,
		SOUNDID_SE_MINIGUN,

		SOUNDID_SE_YAKKYOU,

		SOUNDID_SE_ENESHOT,
		SOUNDID_SE_EXLORE,

		SOUNDID_SE_SHOTGUNRELOAD,
		SOUNDID_SE_ASSAULTRELOAD,
		SOUNDID_SE_MINIGUNRELOAD,

		SOUNDID_NUM
	};
private:
	static int m_hndl[SOUNDID_NUM];

public:
	SoundManager();
	~SoundManager();

	//初期化
	static void Init();
	//終了
	static void Exit();

	//全データ読み込み
	static bool LoadAllData();

	//取得関係
	//再生時間取得
	static int GetSoundTime(tagSoundID ID);
	//再生総時間取得
	static int GetSoundAllTime(tagSoundID ID);
	//音楽再生判定
	static bool IsPlay(tagSoundID ID);

	//設定関係
	//再生開始時間設定
	static void SetStartFrame(tagSoundID ID, int ms);
	//ボリューム設定
	static void SetVolume(tagSoundID ID, float Vol);

	//音楽再生関係
	//音楽再生
	static int Play(tagSoundID ID, int Type = DX_PLAYTYPE_BACK, bool isStart = true);
	//音楽停止
	static int Stop(tagSoundID ID);
	//音楽全停止
	static void StopAll(void);
};