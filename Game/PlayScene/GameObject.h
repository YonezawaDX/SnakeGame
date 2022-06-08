/*
ゲームオブジェクトのクラス
継承先->Player
	  ->Food
*/
#pragma once
#include "../Utility.h"
#include <vector>
#include <deque>

class Player;
class Food;
class GameObject
{
protected:
	// マップの座標
	Int2 mPos;

	Int2 mPos2;
public:
	GameObject();
	virtual~GameObject();

	// 初期化
	virtual void Initialize(GameObject* pPlayer,GameObject* pFood ,int posx) = 0;

	// 更新
	virtual void Update() = 0;

	// 描画
	virtual void Draw() = 0;

	// 終了処理
	virtual void Finalize() = 0;

	virtual std::deque<Int2> GetPlayerPos();


	virtual Int2 GetPos();

	// フードをないとする
	virtual void FalseFood();

	virtual Int2 GetPos2();

	// フードをないとする
	virtual void FalseFood2();

	// プレイヤーの操作状況を渡す
	virtual int GetPlayerState();

	// 尻尾の座標を渡す
	virtual std::deque<Int2> GetTailPos();

	// 尻尾の座標を渡す
	virtual std::deque<Int2> GetTailPos2();

	virtual bool GetTailState();

	virtual void ChangeTailState();

	virtual int GetTimer();
};

