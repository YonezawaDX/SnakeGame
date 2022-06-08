/*
�Q�[���I�u�W�F�N�g�̃N���X
�p����->Player
	  ->Food
*/
#pragma once
#include "../Utility.h"
#include <vector>
#include <deque>

class Player;
class Food;
class GameObject
{
protected:
	// �}�b�v�̍��W
	Int2 mPos;

	Int2 mPos2;
public:
	GameObject();
	virtual~GameObject();

	// ������
	virtual void Initialize(GameObject* pPlayer,GameObject* pFood ,int posx) = 0;

	// �X�V
	virtual void Update() = 0;

	// �`��
	virtual void Draw() = 0;

	// �I������
	virtual void Finalize() = 0;

	virtual std::deque<Int2> GetPlayerPos();


	virtual Int2 GetPos();

	// �t�[�h���Ȃ��Ƃ���
	virtual void FalseFood();

	virtual Int2 GetPos2();

	// �t�[�h���Ȃ��Ƃ���
	virtual void FalseFood2();

	// �v���C���[�̑���󋵂�n��
	virtual int GetPlayerState();

	// �K���̍��W��n��
	virtual std::deque<Int2> GetTailPos();

	// �K���̍��W��n��
	virtual std::deque<Int2> GetTailPos2();

	virtual bool GetTailState();

	virtual void ChangeTailState();

	virtual int GetTimer();
};

