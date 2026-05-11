#pragma once


class ResultScene
{
private:
	enum tagRESULT_SCENE {
		RESULT_SCENE_INIT,
		RESULT_SCENE_LOAD,
		RESULT_SCENE_LOOP,
		RESULT_SCENE_END,

		RESULT_SCENE_NUM,

	};

	int m_hndl;
	int m_gameoverhndl;
	int m_resultcount;
	tagRESULT_SCENE m_SceneID;	//シーン保存

public:
	//コンストラクタ・デストラクタ
	ResultScene();
	~ResultScene();

	//繰り返し行う処理
	int Loop();
	//描画処理
	void Draw();
	void SetResultCount(int result)
	{
		m_resultcount = result;
	}

private:
	//初期化
	void Init(void);
	//終了処理
	void Exit();
	//データロード
	void Load();
	//毎フレーム呼ぶ処理
	void Step();




};
