#pragma once


class ChoiceScene
{
private:
	enum tagCHOICE_SCENE {
		CHOICE_SCENE_INIT,
		CHOICE_SCENE_LOAD,
		CHOICE_SCENE_LOOP,
		CHOICE_SCENE_END,
		CHOICE_SCENE_ENDWAIT,

		CHOICE_SCENE_NUM,

	};

	int m_hndl;
	tagCHOICE_SCENE m_SceneID;	//シーン保存

	

public:
	enum tagCHOICE_NUM {
		CHOICE_WAIT,
		CHOICE_1,
		CHOICE_2,
		CHOICE_3,
		CHOICE_4,
		CHOICE_5,
		CHOICE_6,
		CHOICE_7,

		CHOICE_NUM,

	};
	tagCHOICE_NUM m_Stagenum;
	//コンストラクタ・デストラクタ
	ChoiceScene();
	~ChoiceScene();

	//繰り返し行う処理
	int Loop();
	//描画処理
	void Draw();
	inline int GetStagenum()
	{
		return m_Stagenum;
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