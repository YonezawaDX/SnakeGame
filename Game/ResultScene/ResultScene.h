/*
プレイシーン
*/
#pragma once

#include "../IScene.h"

class ResultScene : public IScene
{
private:
	// Resultの音を入れる
	int mResultSe;
public:

	// コンストラクタ
	ResultScene();

	// デストラクタ
	~ResultScene();

	// 初期化
	void Initialize() override;

	// 更新
	GAME_SCENE Update() override;

	// 描画
	void Draw() override;

	// 終了処理
	void Finalize() override;


};