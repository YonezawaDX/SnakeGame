/*
カウントダウン
*/
#include "Countdown.h"
#include "../GameMain.h"

// カウントダウンの秒数
#define COUNTDOWN_TIME		(50 * 60)

// カウントダウンの文字サイズ
#define COUNTDOWN_SIZE		16

// カウントダウンの文字の表示位置
#define COUNTDOWN_POS_X		(SCREEN_RIGHT - 60)
#define COUNTDOWN_POS_Y		(SCREEN_CENTER_Y - 215)

CountDown::CountDown()
	:mTimer{}
{
}

CountDown::~CountDown()
{
}

// 初期化
void CountDown::Initialize()
{
	mTimer = COUNTDOWN_TIME;
}

// 更新
void CountDown::Update()
{
	// カウントダウン
	mTimer--;
}

// 描画
void CountDown::Draw()
{
	// 元の文字サイズを取得
	int defaultSize = GetFontSize();

	// 文字サイズの設定
	SetFontSize(COUNTDOWN_SIZE);


	// カウントダウンの数字を表示
	DrawFormatString(
		COUNTDOWN_POS_X-50,
		COUNTDOWN_POS_Y,
		GetColor(255, 255, 255),
		"TIME");

	// カウントダウンの数字を表示
	DrawFormatString(
		COUNTDOWN_POS_X,
		COUNTDOWN_POS_Y,
		GetColor(255, 255, 255),
		"%d",
		(mTimer / 60)
	);

	// 最初の文字のサイズに戻す
	SetFontSize(defaultSize);
}

// タイマーを渡す
int CountDown::GetTimer()
{
	return mTimer;
}