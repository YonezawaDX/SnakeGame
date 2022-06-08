/*
�^�C�g���V�[��
*/
#pragma once

#include "../IScene.h"

class NPC;
class Food;
class TitleScene : public IScene
{
public:


private:
	bool mIsDrawString;

	int mTimer;

	NPC* mpNpc;

	NPC* mpNpc2;
	
	Food* mpFood;

	int mTitleSe;
public:
	// �R���X�g���N�^
	TitleScene();

	// �f�X�g���N�^
	~TitleScene();

	// ������
	void Initialize() override;

	// �X�V
	GAME_SCENE Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;


};