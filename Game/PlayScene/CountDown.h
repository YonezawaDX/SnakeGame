/*
カウントダウン
*/
#pragma once
class CountDown
{
private:
	// カウントダウン用タイマー
	int mTimer;

public:
	CountDown();
	~CountDown();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	// タイマーを習得
	int GetTimer();
};