/*
ゲームデータ
*/
#pragma once

struct GameData
{
	// 変数 ===================================
	// プレイモード
	int mState;

	// プレイヤーの長さ
	int gLength;
	int gLength2;

	// 関数 ===================================

	// 初期化
	void Initialize(void);
};

// どこでも使えるようにする
extern GameData g_gameData;
