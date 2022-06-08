/*
プレイヤーのクラス
*/
#pragma once
#include "GameObject.h"
#include "../Utility.h"

using namespace std;
class Food;
class FoodTail;
class NPC : public GameObject
{
public:

	// プレイヤーの状態分け
	enum ePlayerState : int
	{
		NONE,

		UP,
		DOWN,
		LEFT,
		RIGHT
	};

private:
	// 変数------------------------------------------

	// プレイヤーの体
	deque<Int2> mPlayerPos;

	// 他プレイヤーの体
	deque<Int2> mPlayerPos2;

	// 他のプレイヤーのポインタ
	GameObject* mpPlayer;

	// フードのポインタ
	GameObject* mpFood;

	// フードの尻尾ポインタ
	GameObject* mpFoodTail;

	// プレイヤーの移動状態
	int mPlayerState;

	// 体の動きをインターバルタイマーで操作
	int mIntervalTimer;

	// 体の動き判定
	int mSnakeMove;

	// 他プレイヤーに衝突したときの判定(数)
	int mPlayerPosNum;

	// 尻尾の座標
	deque<Int2> mPlayerTail;

	// 尻尾の動きタイマー
	int mTailTimer;

	// 乱数
	int mTailRand;

	// 尻尾用座標
	Int2 mTailPos;

	// 尻尾のフラグ（ありなし）
	bool mTailFlag;

	// 尻尾の出現時間
	int mAppTimer;

	// ているフードの座標を保存
	std::deque<Int2> mFoodPos;

	// ているフード2の座標を保存
	std::deque<Int2> mFoodPos2;

	// 突進用のフラグ
	int mRush;

	// 突進できる回数
	int mRushCount;

	// 突進しているフラグ
	bool mRushFlag;

	// 突進している時間
	int mRushTime;
public:
	NPC();
	~NPC();

	// 初期化
	void Initialize(GameObject* pPlayer, GameObject* b, int posX) override;

	// 更新
	void Update() override;

	// 描画
	void Draw() override;

	// 終了処理
	void Finalize() override;

	// 動く処理
	void Move(int a);

	// プレイヤーの座標を渡す
	std::deque<Int2> GetPlayerPos() override;

	// 衝突したら一つ消す
	bool Collision();

	// 他のプレイヤーとの判定
	bool PlayerCollision();

	// フードを食べるときの判定
	bool EatFlag();

	// 尻尾を食べたときの設定
	bool EatTail();

	// 尻尾を食べたときの設定
	bool EatTail2();

	// プレイヤーのステートを渡す
	int GetPlayerState() override;

	// プレイヤーの尻尾切
	void PlayerTail();

	// プレイヤーの尻尾の動き
	void PlayerTailMove();

	bool GetTailState() override;

	int GetTimer() override;

	void ChangeTailState() override;

	// 尻尾の座標を渡す
	std::deque<Int2> GetTailPos() override;

	// プレイヤーがステージを出そうになったときの処理
	void Stage();

	// 突進するときの処理
	void Rush();
};