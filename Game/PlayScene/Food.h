/*
フードのクラス
*/
#pragma once
#include "GameObject.h"

// 前方宣言
class Player;
	
class Food : public GameObject
{
private:
	// フードがあるかないか
	bool mFoodFlag;

	// フードの生成確認用
	Int2 mFoodPosFlag;

	// プレイヤーのポインタ
	GameObject* mpPlayer;

	// 確認用フラグ
	std::deque<bool> mPlayerPosFlag;

	// プレイヤーの座標を保存
	std::deque<Int2> mPlayerPos;
public:
	Food();
	~Food();

	// 初期化
	void Initialize(GameObject* a, GameObject* b, int posx) override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 終了処理
	void Finalize() override;

	// フードの置く場所を探索
	void AddFood();

	// フードをないとする
	void FalseFood() override;

	// フードの座標を渡す
	Int2 GetPos() override;
};
