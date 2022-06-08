/*
�v���C�V�[��
*/
#pragma once

#include "../IScene.h"
class GameObject;
class Player;
class Food;
class CountDown;
class NPC;
class ThreeCount;
class PlayScene : public IScene
{
private:
	// �v���C���[�̃|�C���^
	GameObject* mpPlayer;
	GameObject* mpPlayer2;

	// NPC�̃|�C���^
	GameObject* mpNpc;
	// �t�[�h�̃|�C���^
	GameObject* mpFood;

	// �J�E���g�_�E���|�C���^
	CountDown* mpCountDown;
	ThreeCount* mpThreeCount;

public:

	// �R���X�g���N�^
	PlayScene();

	// �f�X�g���N�^
	~PlayScene();

	// ������
	void Initialize() override;

	// �X�V
	GAME_SCENE Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;

};