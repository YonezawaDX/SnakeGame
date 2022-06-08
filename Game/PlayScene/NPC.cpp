#include "NPC.h"
#include "../GameMain.h"
#include <cstdlib>
#include <ctime>
#include "../GameData.h"

NPC::NPC()
	:mPlayerPos{}
	, mPlayerState{}
	, mIntervalTimer{}
	, mSnakeMove{}
	, mPlayerPosNum{}
	, mPlayerTail{}
	, mTailTimer{}
	, mTailRand{}
	, mTailPos{}
	, mTailFlag{ false }
	, mAppTimer{}
	, mFoodPos{}
	, mFoodPos2{}
	, mRush{}
	, mRushCount{}
	, mRushFlag{}
	, mRushTime{}
{
}

NPC::~NPC()
{
}

void NPC::Initialize(GameObject* pPlayer, GameObject* pFood, int posX)
{
	// プレイヤーのポインタを入れる
	mpPlayer = pPlayer;

	// フードのポインタを入れる
	mpFood = pFood;


	// プレイヤーの入力を変換用の変数
	mSnakeMove = posX;


	// プレイヤーの体の大きさを指定(-1で考える)
	mPlayerPos.resize(4);

	// 初期座標を指定
	mPlayerPos[0].mX = posX;
	mPlayerPos[0].mY = SCREEN_CENTER_Y;

	mPlayerPos[1].mX = posX;
	mPlayerPos[1].mY = SCREEN_CENTER_Y;

	mPlayerPos[2].mX = posX;
	mPlayerPos[2].mY = SCREEN_CENTER_Y + 16;

	mPlayerPos[3].mX = posX;
	mPlayerPos[3].mY = SCREEN_CENTER_Y + 32;

	// 下に行くとする
	mPlayerState = ePlayerState::UP;

	// 突進の速度
	mRush = 8;

	// 突進できる回数
	mRushCount = 5;
}


void NPC::Update()
{

	// 尻尾の動き
	if (mTailFlag && mAppTimer <= 150)
	{
		this->PlayerTailMove();
	}

	++mIntervalTimer %= mRush;

	if (mIntervalTimer != 0)
	{
		return;
	}
	// 操作処理
	this->Move(mSnakeMove);


	// 壁にぶつかったときの処理
	this->Stage();

	int moveX = 0;
	int moveY = 0;


	mPos.mX = mPlayerPos[mPlayerPos.size() - 1].mX;
	mPos.mY = mPlayerPos[mPlayerPos.size() - 1].mY;



	// 移動処理
	if (mPlayerState == ePlayerState::UP)
	{
		moveY--;
	}
	if (mPlayerState == ePlayerState::DOWN)
	{
		moveY++;
	}
	if (mPlayerState == ePlayerState::LEFT)
	{
		moveX--;
	}
	if (mPlayerState == ePlayerState::RIGHT)
	{
		moveX++;
	}

	int x = mPos.mX + moveX;
	int y = mPos.mY + moveY;


	mPlayerPos[0].mX += moveX * 16;
	mPlayerPos[0].mY += moveY * 16;



	// 先頭に要素を追加
	mPlayerPos.push_front(mPlayerPos[0]);

	// 最後を消す
	mPlayerPos.pop_back();


	// 衝突や餌のときの処理---------------------------------------

	// 衝突したら一つ消す
	if (this->Collision())
	{
		// 最後を消す
		mPlayerPos.pop_back();
		mPlayerPos.pop_back();

	}

	// 餌を食べたときの処理
	if (this->EatFlag())
	{
		mpFood->FalseFood();
		// 体をのばす
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);

	}

	// 餌を食べたときの処理
	if (this->EatTail() && mAppTimer > 30)
	{
		mTailFlag = false;
		// 体をのばす
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);

	}

	// 餌を食べたときの処理
	if (this->EatTail2() && mpPlayer->GetTimer() > 30)
	{
		// falseにする
		mpPlayer->ChangeTailState();
		// 体をのばす
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);

	}





	// 尻尾の出現タイマーを戻す
	if (mAppTimer > 150)
	{
		mAppTimer = 0;
		mTailFlag = false;
	}

	// 他の頭に当てられたときの処理
	if (this->PlayerCollision() && mTailFlag == false)
	{
		// プレイヤーの尻尾を生成
		this->PlayerTail();

		// プレイヤーの衝突した下を消去
		mPlayerPos.erase(mPlayerPos.begin() + mPlayerPosNum + 1, mPlayerPos.end());
	}

	if (mTailFlag == false)
	{
		if (mPlayerTail.empty())
		{
			return;
		}
		mPlayerTail.clear();
	}

	if (mpPlayer->GetTailState() == false)
	{
		if (mFoodPos2.empty())
		{
			return;
		}
		mFoodPos2.clear();
	}

	// SNAKEの大きさを取得
	//if (mSnakeMove == SCREEN_CENTER_X + 32)
	//{
	//	g_size.mPlayerSize = mPlayerPos.size();
	//}
	//if (mSnakeMove == SCREEN_CENTER_X - 32)
	//{
	//	g_size.mPlayerSize2 = mPlayerPos.size();
	//}
}

void NPC::Draw()
{
	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		DrawBox(mPlayerPos[i].mX, mPlayerPos[i].mY, mPlayerPos[i].mX + 15, mPlayerPos[i].mY + 15, GetColor(150, 150, 150), true);
	}

	for (unsigned int i = 0; i < mPlayerTail.size(); i++)
	{
		if (mTailFlag)
		{
			DrawBox(mPlayerTail[i].mX, mPlayerTail[i].mY, mPlayerTail[i].mX + 15, mPlayerTail[i].mY + 15, GetColor(0, 255, 0), true);
		}
	}
}

void NPC::Finalize()
{
}

// 操作処理
void NPC::Move(int a)
{
	if (mPlayerPos.empty() || mPlayerPos2.empty())
	{
		return;
	}
	// プレイヤーが範囲内にいたら
	if (mPlayerPos2[0].mX + 160 >= mPlayerPos[0].mX && mPlayerPos2[0].mX - 160 <= mPlayerPos[0].mX&&
		mPlayerPos2[0].mY + 160 >= mPlayerPos[0].mY && mPlayerPos2[0].mY - 160 <= mPlayerPos[0].mY)
	{
		if (mPlayerPos2.size() >= 6)
		{
			// 操作処理
			if (mPlayerPos2[5].mY < mPlayerPos[0].mY && mPlayerState != ePlayerState::DOWN)
			{
				mPlayerState = ePlayerState::UP;
			}
			if (mPlayerPos2[5].mY > mPlayerPos[0].mY && mPlayerState != ePlayerState::UP)
			{
				mPlayerState = ePlayerState::DOWN;
			}
			else if (mPlayerPos2[5].mX < mPlayerPos[0].mX && mPlayerState != ePlayerState::RIGHT)
			{
				mPlayerState = ePlayerState::LEFT;
			}
			else if (mPlayerPos2[5].mX < mPlayerPos[0].mX && mPlayerState != ePlayerState::LEFT)
			{
				mPlayerState = ePlayerState::RIGHT;
			}
		}
	}
	// プレイヤーが範囲外にいたら餌を追いかける
	else
	{
		// 操作処理
		if (mpFood->GetPos().mY < mPlayerPos[0].mY && mPlayerState != ePlayerState::DOWN)
		{
			mPlayerState = ePlayerState::UP;
		}
		if (mpFood->GetPos().mY > mPlayerPos[0].mY && mPlayerState != ePlayerState::UP)
		{
			mPlayerState = ePlayerState::DOWN;
		}
		if (mpFood->GetPos().mX < mPlayerPos[0].mX && mPlayerState != ePlayerState::RIGHT)
		{
			mPlayerState = ePlayerState::LEFT;
		}
		if (mpFood->GetPos().mX > mPlayerPos[0].mX && mPlayerState != ePlayerState::LEFT)
		{
			mPlayerState = ePlayerState::RIGHT;
		}
	}
	g_gameData.gLength2 = mPlayerPos.size() - 1;
}

std::deque<Int2> NPC::GetPlayerPos()
{
	return std::deque<Int2>(mPlayerPos);
}

// 衝突したら一つ消す
bool NPC::Collision()
{
	// 衝突したら消す
	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		if (i == 0 || i == 1)
		{
			continue;
		}


		if (mPlayerPos[0].mX == mPlayerPos[i].mX && mPlayerPos[0].mY == mPlayerPos[i].mY ||
			mPlayerPos[1].mX == mPlayerPos[i].mX && mPlayerPos[1].mY == mPlayerPos[i].mY)
		{

			return true;
		}
	}

	return false;
}

// 他のプレイヤーとの判定
bool NPC::PlayerCollision()
{
	mPlayerPos2 = mpPlayer->GetPlayerPos();

	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		if (i == 0 || i == 1)
		{
			continue;
		}


		if (// 敵が上を向いているとき
			mpPlayer->GetPlayerState() == ePlayerState::UP &&
			mPlayerPos2[0].mX == mPlayerPos[i].mX && mPlayerPos2[0].mY - 16 == mPlayerPos[i].mY ||
			// 敵が下を向いているとき
			mpPlayer->GetPlayerState() == ePlayerState::DOWN &&
			mPlayerPos2[0].mX == mPlayerPos[i].mX && mPlayerPos2[0].mY + 16 == mPlayerPos[i].mY ||
			// 敵が左を向いているとき
			mpPlayer->GetPlayerState() == ePlayerState::LEFT &&
			mPlayerPos2[0].mX - 16 == mPlayerPos[i].mX && mPlayerPos2[0].mY == mPlayerPos[i].mY ||
			// 敵が右を向いているとき
			mpPlayer->GetPlayerState() == ePlayerState::RIGHT &&
			mPlayerPos2[0].mX + 16 == mPlayerPos[i].mX && mPlayerPos2[0].mY == mPlayerPos[i].mY
			)
		{
			// どこで削除させたか保存する
			mPlayerPosNum = i;

			return true;
		}
	}

	return false;

}

// フードを食べたときの判定
bool NPC::EatFlag()
{
	if (mPlayerPos[0].mX == mpFood->GetPos().mX && mPlayerPos[0].mY == mpFood->GetPos().mY)
	{
		return true;
	}

	return false;
}

// 尻尾を食べたときの設定
bool NPC::EatTail()
{
	for (unsigned int i = 0; i < mPlayerTail.size(); i++)
	{
		if (mPlayerPos[0].mX == mPlayerTail[i].mX && mPlayerPos[0].mY == mPlayerTail[i].mY)
		{
			return true;
		}
	}

	return false;
}

bool NPC::EatTail2()
{
	mFoodPos2 = mpPlayer->GetTailPos();

	for (unsigned int i = 0; i < mFoodPos2.size(); i++)
	{
		if (mPlayerPos[0].mX == mFoodPos2[i].mX && mPlayerPos[0].mY == mFoodPos2[i].mY)
		{
			return true;
		}
	}

	return false;
}

// プレイヤーの操作状況を渡す
int NPC::GetPlayerState()
{
	return mPlayerState;
}

// プレイヤーの尻尾切
void NPC::PlayerTail()
{
	// プレイヤーと当たっていなかったら処理しない
	if (this->PlayerCollision() == false)
	{
		return;
	}

	// 尻尾の大きさを決定
	mPlayerTail.resize(mPlayerPos.size() - mPlayerPosNum);

	for (unsigned int i = 1; i <= mPlayerTail.size(); i++)
	{
		mPlayerTail[i - 1].mX = mPlayerPos[mPlayerPos.size() - i].mX;
		mPlayerTail[i - 1].mY = mPlayerPos[mPlayerPos.size() - i].mY;
	}

	// フラグをしっぽがあると確認
	mTailFlag = true;

}

void NPC::PlayerTailMove()
{
	++mTailTimer %= 5;
	if (mTailTimer != 0)
	{
		return;
	}

	mTailRand = rand() % 5;

	int moveX = 0;
	int moveY = 0;

	mTailPos.mX = mPlayerTail[mPlayerTail.size() - 1].mX;
	mTailPos.mY = mPlayerTail[mPlayerTail.size() - 1].mY;



	// 移動処理
	if (mTailRand == ePlayerState::UP)
	{
		moveY--;
	}
	if (mTailRand == ePlayerState::DOWN)
	{
		moveY++;
	}
	if (mTailRand == ePlayerState::LEFT)
	{
		moveX--;
	}
	if (mTailRand == ePlayerState::RIGHT)
	{
		moveX++;
	}

	// 上に向かっているときの処理
	if (mPlayerTail[0].mY - 16 < SCREEN_TOP && mTailRand == ePlayerState::UP)
	{
		mTailRand = ePlayerState::RIGHT;
	}

	// 下に向かっているときの処理
	if (mPlayerTail[0].mY + 32 > SCREEN_BOTTOM && mTailRand == ePlayerState::DOWN)
	{
		mTailRand = ePlayerState::LEFT;
	}

	// 左に向かっているときの処理
	if (mPlayerTail[0].mX - 16 < SCREEN_LEFT && mTailRand == ePlayerState::LEFT)
	{
		mTailRand = ePlayerState::UP;
	}

	// 右に向かっているときの処理
	if (mPlayerTail[0].mX + 32 > SCREEN_RIGHT && mTailRand == ePlayerState::RIGHT)
	{
		mTailRand = ePlayerState::DOWN;
	}



	int x = mTailPos.mX + moveX;
	int y = mTailPos.mY + moveY;


	mPlayerTail[0].mX += moveX * 16;
	mPlayerTail[0].mY += moveY * 16;



	// 先頭に要素を追加
	mPlayerTail.push_front(mPlayerTail[0]);

	// 最後を消す
	mPlayerTail.pop_back();

	mAppTimer++;
}

bool NPC::GetTailState()
{
	return mTailFlag;
}

int NPC::GetTimer()
{
	return mAppTimer;
}

void NPC::ChangeTailState()
{
	mTailFlag = false;
}

// 尻尾の座標を渡す
std::deque<Int2> NPC::GetTailPos()
{
	return mPlayerTail;
}

void NPC::Stage()
{
	// 上に向かっているときの処理
	if (mPlayerPos[0].mY - 16 < SCREEN_TOP && mPlayerState == ePlayerState::UP)
	{
		mPlayerState = ePlayerState::RIGHT;
	}

	// 下に向かっているときの処理
	if (mPlayerPos[0].mY + 32 > SCREEN_BOTTOM && mPlayerState == ePlayerState::DOWN)
	{
		mPlayerState = ePlayerState::LEFT;
	}

	// 左に向かっているときの処理
	if (mPlayerPos[0].mX - 16 < SCREEN_LEFT && mPlayerState == ePlayerState::LEFT)
	{
		mPlayerState = ePlayerState::UP;
	}

	// 右に向かっているときの処理
	if (mPlayerPos[0].mX + 32 > SCREEN_RIGHT && mPlayerState == ePlayerState::RIGHT)
	{
		mPlayerState = ePlayerState::DOWN;
	}

	// 正面衝突した場合

}

// 突進するときの処理
void NPC::Rush()
{
	mRushCount--;
	mRush = 2;
	mRushFlag = true;
}

