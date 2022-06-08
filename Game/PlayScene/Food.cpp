/*
フードのクラス
*/
#include "Food.h"
#include "GameObject.h"
#include "../GameMain.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

Food::Food()
	:mFoodFlag{}
	,mpPlayer{}
{
}

Food::~Food()
{
}

void Food::Initialize(GameObject* player, GameObject* b, int posx)
{
	// プレイヤーのポインタを取得
	mpPlayer = player;
	// プレイヤーの座標を取得
	mPlayerPos = mpPlayer->GetPlayerPos();

	// フードはないとする
	mFoodFlag = false;

	// フードの位置を初期化
	mPos.mX = -5;
	mPos.mY = -5;
}

 
void Food::Update()
{
	// プレイヤーの座標を取得
	mPlayerPos = mpPlayer->GetPlayerPos();

	if (mFoodFlag == false)
	{
		// 餌を生成する
		this->AddFood();
	}


}

// 描画
void Food::Draw()
{
	// フードの描画
	if (mFoodFlag)
	{
		DrawBox(mPos.mX, mPos.mY, mPos.mX + 15, mPos.mY + 15, GetColor(0, 255, 0), true);
	}
}

void Food::Finalize()
{
}

// フードを置く場所を探索
void Food::AddFood()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// 乱数を取得
	int x = (2+GetRand(35)) * 16;
	int y = (2+GetRand(25)) * 16;

	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		if (mPlayerPos[i].mX == x && mPlayerPos[i].mY == y)
		{
			mFoodFlag = false;
			return;
		}
	}

	// 
	mPos.mX = x;
	mPos.mY = y;

	mFoodFlag = true;

}

// フードをないとする
void Food::FalseFood()
{
	mFoodFlag = false;
}

Int2 Food::GetPos()
{
	return mPos;
}

