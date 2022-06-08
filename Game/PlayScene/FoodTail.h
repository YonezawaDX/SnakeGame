/*
�g���ĂȂ�
*/

#pragma once
#include "GameObject.h"

// �O���錾
class Player;

class FoodTail : public GameObject
{
private:
	// �t�[�h�����邩�Ȃ���
	bool mFoodFlag;

	// �v���C���[�̃|�C���^
	GameObject* mpPlayer;

	// �v���C���[�̃|�C���^�Q
	GameObject* mpPlayer2;

	// �m�F�p�t���O
	std::deque<bool> mFoodPosFlag;

	// �m�F�p�t���O2
	std::deque<bool> mFoodPosFlag2;

	// �t�[�h�̍��W��ۑ�
	std::deque<Int2> mFoodPos;

	// �t�[�h2�̍��W��ۑ�
	std::deque<Int2> mFoodPos2;

	// �v���C���[�̍��W��ۑ�
	std::deque<Int2> mPlayerPos;

	// �v���C���[2�̍��W��ۑ�
	std::deque<Int2> mPlayerPos2;
public:
	FoodTail();
	~FoodTail();

	// ������
	void Initialize(GameObject* a, GameObject* b,int posx) override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;

	// �t�[�h�̒u���ꏊ��T��
	void AddFood();

	void AddFood2();

	// �t�[�h���Ȃ��Ƃ���
	void FalseFood() override;

	// �t�[�h���Ȃ��Ƃ���
	void FalseFood2() override;

	// �K���̍��W��n��
	std::deque<Int2> GetTailPos() override;

	// �K���̍��W��n��
	std::deque<Int2> GetTailPos2() override;

};
