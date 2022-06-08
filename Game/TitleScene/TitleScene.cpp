/*
タイトルシーン
*/
#include "TitleScene.h"
#include "../PlayScene/NPC.h"
#include "../PlayScene/Food.h"

#include "../GameMain.h"
#include "../GameData.h"

// タイトル座標
#define TITLE_POS_X			(SCREEN_CENTER_X - 100)
#define TITLE_POS_Y			(SCREEN_CENTER_Y - 80)

// タイトルロゴサイズ
#define TITLE_LOGO_SIZE			60

// キー入力の文字位置
#define PUSHKEY_POS_X		(SCREEN_CENTER_X - 60)
#define PUSHKEY_POS_Y		(SCREEN_CENTER_Y + 150)

// キー入力の文字点滅間隔
#define PUSHKEY_INTERVAL	30
/*--------------------------------------------------
コンストラクタ
--------------------------------------------------*/
TitleScene::TitleScene()
	:mIsDrawString{}
	,mTimer{}
	,mpNpc{}
	,mpNpc2{}
	,mpFood{}
	,mTitleSe{}
{

}
/*--------------------------------------------------
デストラクタ
--------------------------------------------------*/
TitleScene::~TitleScene()
{
	this->Finalize();
}

/*--------------------------------------------------
初期化
--------------------------------------------------*/
void TitleScene::Initialize()
{

	mpNpc = new NPC();
	mpNpc2 = new NPC();
	mpFood = new Food();

	mpNpc->Initialize(mpNpc2, mpFood, SCREEN_CENTER_X + 32);
	mpNpc2->Initialize(mpNpc, mpFood, SCREEN_CENTER_X - 3200);

	mpFood->Initialize(mpNpc, mpNpc2, SCREEN_CENTER_X);

	mIsDrawString = false;

	mTimer = 0;

	g_gameData.Initialize();

	// 音をロードする
	mTitleSe = LoadSoundMem("Resources/Audio/Title.mp3");
	PlaySoundMem(mTitleSe, DX_PLAYTYPE_LOOP);
}

/*--------------------------------------------------
更新
戻り値	:次のシーン番号
--------------------------------------------------*/
GAME_SCENE TitleScene::Update()
{
	mpNpc->Update();

	mpFood->Update();

	// タイマーを進める
	++mTimer %= PUSHKEY_INTERVAL;

	// 文字の表示フラグを切り替える
	if (mTimer == 0)
	{
		mIsDrawString = !mIsDrawString;
	}

	// プレイ状態を変更する
	if (IsButtonPressed(PAD_INPUT_UP) || IsButtonPressed(PAD_INPUT_UP, 1) ||
		IsButtonPressed(PAD_INPUT_DOWN) || IsButtonPressed(PAD_INPUT_DOWN, 1))
	{
		if (g_gameData.mState == ePlayState::PLAY_1P)
		{
			g_gameData.mState = ePlayState::PLAY_2P;
		}
		else if (g_gameData.mState == ePlayState::PLAY_2P)
		{
			g_gameData.mState = ePlayState::PLAY_1P;
		}
	}


	// プレイシーンへ
	if (IsButtonPressed(PAD_INPUT_1) || IsButtonPressed(PAD_INPUT_1,1))
	{
		return GAME_SCENE::PLAY;
	}

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
描画
--------------------------------------------------*/
void TitleScene::Draw()
{
	mpNpc->Draw();
	mpFood->Draw();

	// タイトルロゴの表示
	int defaultSize = GetFontSize();

	SetFontSize(TITLE_LOGO_SIZE);

	DrawFormatString(
		TITLE_POS_X,
		TITLE_POS_Y - 10,
		GetColor(255, 255, 0),
		"SNACK\nSNAKE"
	);

	SetFontSize(TITLE_LOGO_SIZE - 40);

	DrawFormatString(
		TITLE_POS_X + 60,
		TITLE_POS_Y + 150,
		GetColor(255, 255, 255),
		"1P Play\n2P Play"
	);

	// タイトルから渡す各シーン変更済みステートを渡す

	if (g_gameData.mState == ePlayState::PLAY_1P)
	{
		DrawTriangle(TITLE_POS_X + 35, TITLE_POS_Y + 150,
			TITLE_POS_X + 35, TITLE_POS_Y + 165,
			TITLE_POS_X + 50, TITLE_POS_Y + 158, GetColor(255, 0, 0), true);
	}
	else if (g_gameData.mState == ePlayState::PLAY_2P)
	{
		DrawTriangle(TITLE_POS_X + 35, TITLE_POS_Y + 170,
			TITLE_POS_X + 35, TITLE_POS_Y + 185,
			TITLE_POS_X + 50, TITLE_POS_Y + 178, GetColor(255, 0, 0), true);
	}

	SetFontSize(defaultSize);

	// キー入力を促す文字の表示
	if (mIsDrawString == true)
	{
		DrawFormatString(
			PUSHKEY_POS_X,
			PUSHKEY_POS_Y,
			GetColor(255, 255, 0),
			"Push 1 Key"
		);
	}
}

/*--------------------------------------------------
終了処理
--------------------------------------------------*/
void TitleScene::Finalize()
{
	if (mpNpc != nullptr)
	{
		delete mpNpc;
		mpNpc = nullptr;
	}
	if (mpNpc2 != nullptr)
	{
		delete mpNpc2;
		mpNpc2 = nullptr;
	}
	if (mpFood != nullptr)
	{
		delete mpFood;
		mpFood = nullptr;
	}

	StopSoundMem(mTitleSe);
}

