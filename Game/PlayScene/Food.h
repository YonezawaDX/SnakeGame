/*
�t�[�h�̃N���X
*/
#pragma once
#include "GameObject.h"

// �O���錾
class Player;
	
class Food : public GameObject
{
private:
	// �t�[�h�����邩�Ȃ���
	bool mFoodFlag;

	// �t�[�h�̐����m�F�p
	Int2 mFoodPosFlag;

	// �v���C���[�̃|�C���^
	GameObject* mpPlayer;

	// �m�F�p�t���O
	std::deque<bool> mPlayerPosFlag;

	// �v���C���[�̍��W��ۑ�
	std::deque<Int2> mPlayerPos;
public:
	Food();
	~Food();

	// ������
	void Initialize(GameObject* a, GameObject* b, int posx) override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;

	// �t�[�h�̒u���ꏊ��T��
	void AddFood();

	// �t�[�h���Ȃ��Ƃ���
	void FalseFood() override;

	// �t�[�h�̍��W��n��
	Int2 GetPos() override;
};
