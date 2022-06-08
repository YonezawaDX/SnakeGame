/*
タイトルシーン
*/
#pragma once

#include "../IScene.h"

class NPC;
class Food;
class TitleScene : public IScene
{
public:


private:
	bool mIsDrawString;

	int mTimer;

	NPC* mpNpc;

	NPC* mpNpc2;
	
	Food* mpFood;

	int mTitleSe;
public:
	// コンストラクタ
	TitleScene();

	// デストラクタ
	~TitleScene();

	// 初期化
	void Initialize() override;

	// 更新
	GAME_SCENE Update() override;

	// 描画
	void Draw() override;

	// 終了処理
	void Finalize() override;


};