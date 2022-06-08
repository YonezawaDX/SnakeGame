/*
プレイシーン
*/
#pragma once

#include "../IScene.h"
class GameObject;
class Player;
class Food;
class CountDown;
class NPC;
class ThreeCount;
class PlayScene : public IScene
{
private:
	// プレイヤーのポインタ
	GameObject* mpPlayer;
	GameObject* mpPlayer2;

	// NPCのポインタ
	GameObject* mpNpc;
	// フードのポインタ
	GameObject* mpFood;

	// カウントダウンポインタ
	CountDown* mpCountDown;
	ThreeCount* mpThreeCount;

public:

	// コンストラクタ
	PlayScene();

	// デストラクタ
	~PlayScene();

	// 初期化
	void Initialize() override;

	// 更新
	GAME_SCENE Update() override;

	// 描画
	void Draw() override;

	// 終了処理
	void Finalize() override;

};