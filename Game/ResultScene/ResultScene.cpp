/*
プレイシーン
*/
#include "ResultScene.h"

#include "../GameMain.h"
#include "../GameData.h"

// リザルト文字の座標
#define RESULT_LOGO_POS_X			(SCREEN_CENTER_X - 100)
#define RESULT_LOGO_POS_Y			(SCREEN_CENTER_Y - 100)

// リザルト文字のサイズ
#define RESULT_LOGO_SIZE			50

// 結果文字の座標
#define RESULT_POS_X				(SCREEN_CENTER_X - 100)
#define RESULT_POS_Y				(SCREEN_CENTER_Y + 100)

// 結果文字のサイズ
#define RESULT_SIZE					30
/*--------------------------------------------------
コンストラクタ
--------------------------------------------------*/
ResultScene::ResultScene()
{
}

/*--------------------------------------------------
デストラクタ
--------------------------------------------------*/
ResultScene::~ResultScene()
{
}

/*--------------------------------------------------
初期化
--------------------------------------------------*/
void ResultScene::Initialize()
{
	mResultSe = LoadSoundMem("Resources/Audio/Result.mp3");
	PlaySoundMem(mResultSe, DX_PLAYTYPE_BACK);
}

/*--------------------------------------------------
更新
戻り値	:次のシーン番号
--------------------------------------------------*/
GAME_SCENE ResultScene::Update()
{
	if (IsButtonPressed(PAD_INPUT_1) || IsButtonPressed(PAD_INPUT_1, 1))
	{
		return GAME_SCENE::TITLE;
	}

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
描画
--------------------------------------------------*/
void ResultScene::Draw()
{
	int defaultSize = GetFontSize();

	// リザルト文字の表示

	SetFontSize(RESULT_LOGO_SIZE);
	if (g_gameData.gLength > g_gameData.gLength2)
	{
		DrawFormatString(
			RESULT_LOGO_POS_X,
			RESULT_LOGO_POS_Y,
			GetColor(255, 255, 0),
			"1P WIN"
		);
	}
	if (g_gameData.gLength < g_gameData.gLength2)
	{
		DrawFormatString(
			RESULT_LOGO_POS_X,
			RESULT_LOGO_POS_Y,
			GetColor(255, 255, 0),
			"2P WIN"
		);
	}
	if (g_gameData.gLength == g_gameData.gLength2)
	{
		DrawFormatString(
			RESULT_LOGO_POS_X,
			RESULT_LOGO_POS_Y,
			GetColor(255, 255, 0),
			"DRAW"
		);
	}

	SetFontSize(RESULT_LOGO_SIZE - 30);
	DrawFormatString(
		RESULT_LOGO_POS_X -100,
		RESULT_LOGO_POS_Y + 100,
		GetColor(255, 255, 255),
		"1P Length\n     %d",g_gameData.gLength
	);
	DrawFormatString(
		RESULT_LOGO_POS_X + 120,
		RESULT_LOGO_POS_Y + 100,
		GetColor(255, 255, 255),
		"2P Length\n     %d", g_gameData.gLength2
	);
}

/*--------------------------------------------------
終了処理
--------------------------------------------------*/
void ResultScene::Finalize()
{
}
