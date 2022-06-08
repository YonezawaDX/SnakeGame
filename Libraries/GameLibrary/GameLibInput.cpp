//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLibInput.cpp
//!
//! @brief  DxLibの入力関連への追加機能のソースファイル
//!
//! @date   2017/7/1
//!
//! @author S.Takaki
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include <DxLib.h>



// ファイルスコープ変数の定義 ==============================================
static int s_currentInputState[2];    // 現在の入力デバイスの状態 
static int s_lastInputState[2];       // 前回の入力デバイスの状態



// 関数の定義 ==============================================================

//------------------------------------------------------------------
//! @brief ジョイパッドの入力状態の更新処理
//!
//! @param[in] なし
//!
//! @return なし
//------------------------------------------------------------------
void UpdateJoypadInputState(void)
{
	// 状態の履歴を保存
	s_lastInputState[0] = s_currentInputState[0];
	s_lastInputState[1] = s_currentInputState[1];


	// ゲームパッドの現在の状態を取得
	s_currentInputState[0] = GetJoypadInputState(DX_INPUT_PAD1);
	s_currentInputState[1] = GetJoypadInputState(DX_INPUT_KEY);
}



//------------------------------------------------------------------
//! @brief 指定されたボタンが押されているかどうかを判断
//!
//! @param[in] button 判定したいボタンの入力マスク
//! @param[in] padtype 判定したいパッドの配列番号
//!
//! @retval TRUE  指定されたボタンが押されている場合
//! @retval FALSE それ以外の場合
//------------------------------------------------------------------
BOOL IsButtonDown(int button, int padtype)
{
	if ((s_currentInputState[padtype] & button) == button)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



//------------------------------------------------------------------
//! @brief 指定されたボタンが押されていないかどうかを判断
//!
//! @param[in] button 判定したいボタンの入力マスク
//! @param[in] padtype 判定したいパッドの配列番号
//!
//! @retval TRUE  指定されたボタンが押されていない場合
//! @retval FALSE それ以外の場合
//------------------------------------------------------------------
BOOL IsButtonUp(int button, int padtype)
{
	if ((s_currentInputState[padtype] & button) != button)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



//------------------------------------------------------------------
//! @brief 指定されたボタンが押されたかどうかを判断
//!
//! @param[in] button 判定したいボタンの入力マスク
//! @param[in] padtype 判定したいパッドの配列番号
//!
//! @retval TRUE  指定されたキーが押された場合
//! @retval FALSE それ以外の場合
//------------------------------------------------------------------
BOOL IsButtonPressed(int button, int padtype)
{
	if (((~s_lastInputState[padtype] & s_currentInputState[padtype]) & button) == button)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



//------------------------------------------------------------------
//! @brief 指定されたボタンが離されたかどうかを判断
//!
//! @param[in] button 判定したいボタンの入力マスク
//! @param[in] padtype 判定したいパッドの配列番号
//!
//! @retval TRUE  指定されたキーが離された場合
//! @retval FALSE それ以外の場合
//------------------------------------------------------------------
BOOL IsButtonReleased(int button, int padtype)
{
	if (((s_lastInputState[padtype] & ~s_currentInputState[padtype]) & button) == button)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}