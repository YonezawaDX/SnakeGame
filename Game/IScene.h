/*
�V�[���C���^�[�t�F�[�X
*/
#pragma once

#include "GameMain.h"


class IScene
{
public:
	enum ePlayState : int
	{
		PLAY_1P,
		PLAY_2P
	};
public:

	virtual ~IScene() = default;

	// ������
	virtual void Initialize() = 0;

	// �X�V
	virtual GAME_SCENE Update() = 0;

	// �`��
	virtual void Draw() = 0;

	// �I������
	virtual void Finalize() = 0;

};