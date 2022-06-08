/*
�v���C���[�̃N���X
*/
#pragma once
#include "GameObject.h"
#include "../Utility.h"

using namespace std;
class Food;
class FoodTail;
class NPC : public GameObject
{
public:

	// �v���C���[�̏�ԕ���
	enum ePlayerState : int
	{
		NONE,

		UP,
		DOWN,
		LEFT,
		RIGHT
	};

private:
	// �ϐ�------------------------------------------

	// �v���C���[�̑�
	deque<Int2> mPlayerPos;

	// ���v���C���[�̑�
	deque<Int2> mPlayerPos2;

	// ���̃v���C���[�̃|�C���^
	GameObject* mpPlayer;

	// �t�[�h�̃|�C���^
	GameObject* mpFood;

	// �t�[�h�̐K���|�C���^
	GameObject* mpFoodTail;

	// �v���C���[�̈ړ����
	int mPlayerState;

	// �̂̓������C���^�[�o���^�C�}�[�ő���
	int mIntervalTimer;

	// �̂̓�������
	int mSnakeMove;

	// ���v���C���[�ɏՓ˂����Ƃ��̔���(��)
	int mPlayerPosNum;

	// �K���̍��W
	deque<Int2> mPlayerTail;

	// �K���̓����^�C�}�[
	int mTailTimer;

	// ����
	int mTailRand;

	// �K���p���W
	Int2 mTailPos;

	// �K���̃t���O�i����Ȃ��j
	bool mTailFlag;

	// �K���̏o������
	int mAppTimer;

	// �Ă���t�[�h�̍��W��ۑ�
	std::deque<Int2> mFoodPos;

	// �Ă���t�[�h2�̍��W��ۑ�
	std::deque<Int2> mFoodPos2;

	// �ːi�p�̃t���O
	int mRush;

	// �ːi�ł����
	int mRushCount;

	// �ːi���Ă���t���O
	bool mRushFlag;

	// �ːi���Ă��鎞��
	int mRushTime;
public:
	NPC();
	~NPC();

	// ������
	void Initialize(GameObject* pPlayer, GameObject* b, int posX) override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;

	// ��������
	void Move(int a);

	// �v���C���[�̍��W��n��
	std::deque<Int2> GetPlayerPos() override;

	// �Փ˂���������
	bool Collision();

	// ���̃v���C���[�Ƃ̔���
	bool PlayerCollision();

	// �t�[�h��H�ׂ�Ƃ��̔���
	bool EatFlag();

	// �K����H�ׂ��Ƃ��̐ݒ�
	bool EatTail();

	// �K����H�ׂ��Ƃ��̐ݒ�
	bool EatTail2();

	// �v���C���[�̃X�e�[�g��n��
	int GetPlayerState() override;

	// �v���C���[�̐K����
	void PlayerTail();

	// �v���C���[�̐K���̓���
	void PlayerTailMove();

	bool GetTailState() override;

	int GetTimer() override;

	void ChangeTailState() override;

	// �K���̍��W��n��
	std::deque<Int2> GetTailPos() override;

	// �v���C���[���X�e�[�W���o�����ɂȂ����Ƃ��̏���
	void Stage();

	// �ːi����Ƃ��̏���
	void Rush();
};