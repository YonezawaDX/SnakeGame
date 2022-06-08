/*
カウントダウン構造体
*/
#pragma once
class ThreeCount
{
private:
	// 変数=====================================

	// カウントダウン用タイマー
	int mTimer;
public:
	// 関数=====================================
	ThreeCount();
	~ThreeCount();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	// タイマーを習得
	int GetTimer();

};