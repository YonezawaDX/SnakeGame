//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLibInput.h
//!
//! @brief  DxLibの入力関連への追加機能のヘッダファイル
//!
//! @date   2017/7/1
//!
//! @author S.Takaki
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once




// ヘッダファイルの読み込み ================================================
#include <minwindef.h>



// 関数の宣言 ==============================================================

// ジョイパッドの入力状態の更新処理
void UpdateJoypadInputState(void);

// 指定されたボタンが押されているかどうかを判断
BOOL IsButtonDown(int button, int padtype = 0);

// 指定されたボタンが押されていないかどうかを判断
BOOL IsButtonUp(int button, int padtype = 0);

// 指定されたボタンが押されたかどうかを判断
BOOL IsButtonPressed(int button, int padtype = 0);

// 指定されたボタンが離されたかどうかを判断
BOOL IsButtonReleased(int button, int padtype = 0);