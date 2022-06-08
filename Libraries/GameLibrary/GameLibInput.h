//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLibInput.h
//!
//! @brief  DxLib�̓��͊֘A�ւ̒ǉ��@�\�̃w�b�_�t�@�C��
//!
//! @date   2017/7/1
//!
//! @author S.Takaki
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once




// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include <minwindef.h>



// �֐��̐錾 ==============================================================

// �W���C�p�b�h�̓��͏�Ԃ̍X�V����
void UpdateJoypadInputState(void);

// �w�肳�ꂽ�{�^����������Ă��邩�ǂ����𔻒f
BOOL IsButtonDown(int button, int padtype = 0);

// �w�肳�ꂽ�{�^����������Ă��Ȃ����ǂ����𔻒f
BOOL IsButtonUp(int button, int padtype = 0);

// �w�肳�ꂽ�{�^���������ꂽ���ǂ����𔻒f
BOOL IsButtonPressed(int button, int padtype = 0);

// �w�肳�ꂽ�{�^���������ꂽ���ǂ����𔻒f
BOOL IsButtonReleased(int button, int padtype = 0);