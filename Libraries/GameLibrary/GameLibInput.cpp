//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLibInput.cpp
//!
//! @brief  DxLib�̓��͊֘A�ւ̒ǉ��@�\�̃\�[�X�t�@�C��
//!
//! @date   2017/7/1
//!
//! @author S.Takaki
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include <DxLib.h>



// �t�@�C���X�R�[�v�ϐ��̒�` ==============================================
static int s_currentInputState[2];    // ���݂̓��̓f�o�C�X�̏�� 
static int s_lastInputState[2];       // �O��̓��̓f�o�C�X�̏��



// �֐��̒�` ==============================================================

//------------------------------------------------------------------
//! @brief �W���C�p�b�h�̓��͏�Ԃ̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//------------------------------------------------------------------
void UpdateJoypadInputState(void)
{
	// ��Ԃ̗�����ۑ�
	s_lastInputState[0] = s_currentInputState[0];
	s_lastInputState[1] = s_currentInputState[1];


	// �Q�[���p�b�h�̌��݂̏�Ԃ��擾
	s_currentInputState[0] = GetJoypadInputState(DX_INPUT_PAD1);
	s_currentInputState[1] = GetJoypadInputState(DX_INPUT_KEY);
}



//------------------------------------------------------------------
//! @brief �w�肳�ꂽ�{�^����������Ă��邩�ǂ����𔻒f
//!
//! @param[in] button ���肵�����{�^���̓��̓}�X�N
//! @param[in] padtype ���肵�����p�b�h�̔z��ԍ�
//!
//! @retval TRUE  �w�肳�ꂽ�{�^����������Ă���ꍇ
//! @retval FALSE ����ȊO�̏ꍇ
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
//! @brief �w�肳�ꂽ�{�^����������Ă��Ȃ����ǂ����𔻒f
//!
//! @param[in] button ���肵�����{�^���̓��̓}�X�N
//! @param[in] padtype ���肵�����p�b�h�̔z��ԍ�
//!
//! @retval TRUE  �w�肳�ꂽ�{�^����������Ă��Ȃ��ꍇ
//! @retval FALSE ����ȊO�̏ꍇ
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
//! @brief �w�肳�ꂽ�{�^���������ꂽ���ǂ����𔻒f
//!
//! @param[in] button ���肵�����{�^���̓��̓}�X�N
//! @param[in] padtype ���肵�����p�b�h�̔z��ԍ�
//!
//! @retval TRUE  �w�肳�ꂽ�L�[�������ꂽ�ꍇ
//! @retval FALSE ����ȊO�̏ꍇ
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
//! @brief �w�肳�ꂽ�{�^���������ꂽ���ǂ����𔻒f
//!
//! @param[in] button ���肵�����{�^���̓��̓}�X�N
//! @param[in] padtype ���肵�����p�b�h�̔z��ԍ�
//!
//! @retval TRUE  �w�肳�ꂽ�L�[�������ꂽ�ꍇ
//! @retval FALSE ����ȊO�̏ꍇ
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