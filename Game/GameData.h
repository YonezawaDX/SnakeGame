/*
�Q�[���f�[�^
*/
#pragma once

struct GameData
{
	// �ϐ� ===================================
	// �v���C���[�h
	int mState;

	// �v���C���[�̒���
	int gLength;
	int gLength2;

	// �֐� ===================================

	// ������
	void Initialize(void);
};

// �ǂ��ł��g����悤�ɂ���
extern GameData g_gameData;
