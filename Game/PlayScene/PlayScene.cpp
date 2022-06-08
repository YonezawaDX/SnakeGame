/*
プレイシーン
*/
#include "PlayScene.h"

#include "../GameMain.h"

#include "GameObject.h"
#include "Player.h"
#include "NPC.h"
#include "Food.h"
#include "CountDown.h"
#include "ThreeCount.h"
#include "../GameData.h"
/*--------------------------------------------------
コンストラクタ
--------------------------------------------------*/
PlayScene::PlayScene()
	:mpPlayer{}
	,mpPlayer2{}
	,mpNpc{}
	,mpFood{}
	,mpCountDown{}
	,mpThreeCount{}
{
}

/*--------------------------------------------------
デストラクタ
--------------------------------------------------*/
PlayScene::~PlayScene()
{
	this->Finalize();
}

/*--------------------------------------------------
初期化
--------------------------------------------------*/
void PlayScene::Initialize()
{
	// newする
	mpPlayer	= new Player();
	mpPlayer2	= new Player();
	mpNpc		= new NPC();
	mpFood		= new Food();
	mpCountDown = new CountDown();
	mpThreeCount = new ThreeCount();


	mpThreeCount->Initialize();

	mpCountDown->Initialize();

	if (g_gameData.mState == ePlayState::PLAY_1P)
	{
		mpPlayer->Initialize(mpNpc, mpFood, SCREEN_CENTER_X - 32);
		mpNpc->Initialize(mpPlayer, mpFood, SCREEN_CENTER_X + 32);

		mpFood->Initialize(mpPlayer, mpNpc, SCREEN_CENTER_X);
	}
	else if (g_gameData.mState == ePlayState::PLAY_2P)
	{

		mpPlayer->Initialize(mpPlayer2, mpFood, SCREEN_CENTER_X - 32);
		mpPlayer2->Initialize(mpPlayer, mpFood, SCREEN_CENTER_X + 32);

		mpFood->Initialize(mpPlayer, mpPlayer2, SCREEN_CENTER_X);
	}
}

/*--------------------------------------------------
更新
戻り値	:次のシーン番号
--------------------------------------------------*/
GAME_SCENE PlayScene::Update()
{

	mpThreeCount->Update();

	if (mpThreeCount->GetTimer() < 0)
	{

		mpPlayer->Update();

		if (g_gameData.mState == ePlayState::PLAY_1P)
		{
			mpNpc->Update();

			mpFood->Update();
		}
		else if (g_gameData.mState == ePlayState::PLAY_2P)
		{
			mpPlayer2->Update();

			mpFood->Update();
		}


		mpCountDown->Update();

		if (mpCountDown->GetTimer() < 0)
		{
			return GAME_SCENE::RESULT;
		}
	}
	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
描画
--------------------------------------------------*/
void PlayScene::Draw()
{

	mpCountDown->Draw();

	if (g_gameData.mState == ePlayState::PLAY_1P)
	{
		mpPlayer->Draw();
		mpNpc->Draw();
	}
	else if (g_gameData.mState == ePlayState::PLAY_2P)
	{
		mpPlayer->Draw();
		mpPlayer2->Draw();
	}

	mpFood->Draw();


	if (mpThreeCount->GetTimer() > 0)
	{
		mpThreeCount->Draw();
	}

}

/*--------------------------------------------------
終了処理
--------------------------------------------------*/
void PlayScene::Finalize()
{
	if (mpPlayer != nullptr)
	{
		delete mpPlayer;
		mpPlayer = nullptr;
	}
	if (mpPlayer2 != nullptr)
	{
		delete mpPlayer2;
		mpPlayer2 = nullptr;
	}
	if (mpNpc != nullptr)
	{
		delete mpNpc;
		mpNpc = nullptr;
	}
	if (mpFood != nullptr)
	{
		delete mpFood;
		mpFood = nullptr;
	}
	if (mpCountDown != nullptr)
	{
		delete mpCountDown;
		mpCountDown = nullptr;
	}
	if (mpThreeCount != nullptr)
	{
		delete mpThreeCount;
		mpThreeCount = nullptr;
	}
}