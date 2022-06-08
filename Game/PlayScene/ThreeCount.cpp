/*
カウントダウンの構造体
作成日 :
作成者 : 米澤駿介
*/
#include "ThreeCount.h"
#include "../GameMain.h"

// カウントダウンの秒数
#define COUNTDOWN_TIME		(3 * 60)

// カウントダウンの文字サイズ
#define COUNTDOWN_SIZE		100

// カウントダウンの文字の表示位置
#define COUNTDOWN_POS_X		(SCREEN_CENTER_X - 25)
#define COUNTDOWN_POS_Y		(SCREEN_CENTER_Y - 50)

ThreeCount::ThreeCount()
{
}
ThreeCount::~ThreeCount()
{
}

/*---------------------------------
カウントダウンの初期化
-----------------------------------*/
void ThreeCount::Initialize()
{
	mTimer = COUNTDOWN_TIME;
}

/*-----------------------------------
カウントダウンの更新
-------------------------------------*/
void ThreeCount::Update(void)
{
	// カウントダウン
	mTimer--;
}

/*------------------------------------
カウントダウンの描画
-------------------------------------*/
void ThreeCount::Draw(void)
{
	// 元の文字サイズを取得
	int defaultSize = GetFontSize();

	// 文字サイズの設定
	SetFontSize(COUNTDOWN_SIZE);

	// カウントダウンの数字を表示
	DrawFormatString(
		COUNTDOWN_POS_X,
		COUNTDOWN_POS_Y,
		GetColor(255, 0, 0),
		"%d",
		(mTimer / 60) + 1
	);

	// 最初の文字のサイズに戻す
	SetFontSize(defaultSize);
}

int ThreeCount::GetTimer()
{
	return mTimer;
}
