/*
使ってない
*/

#pragma once
#include "GameObject.h"

// 前方宣言
class Player;

class FoodTail : public GameObject
{
private:
	// フードがあるかないか
	bool mFoodFlag;

	// プレイヤーのポインタ
	GameObject* mpPlayer;

	// プレイヤーのポインタ２
	GameObject* mpPlayer2;

	// 確認用フラグ
	std::deque<bool> mFoodPosFlag;

	// 確認用フラグ2
	std::deque<bool> mFoodPosFlag2;

	// フードの座標を保存
	std::deque<Int2> mFoodPos;

	// フード2の座標を保存
	std::deque<Int2> mFoodPos2;

	// プレイヤーの座標を保存
	std::deque<Int2> mPlayerPos;

	// プレイヤー2の座標を保存
	std::deque<Int2> mPlayerPos2;
public:
	FoodTail();
	~FoodTail();

	// 初期化
	void Initialize(GameObject* a, GameObject* b,int posx) override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 終了処理
	void Finalize() override;

	// フードの置く場所を探索
	void AddFood();

	void AddFood2();

	// フードをないとする
	void FalseFood() override;

	// フードをないとする
	void FalseFood2() override;

	// 尻尾の座標を渡す
	std::deque<Int2> GetTailPos() override;

	// 尻尾の座標を渡す
	std::deque<Int2> GetTailPos2() override;

};
