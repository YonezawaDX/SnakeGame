/*
�t�[�h�̃N���X
*/
#include "Food.h"
#include "GameObject.h"
#include "../GameMain.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

Food::Food()
	:mFoodFlag{}
	,mpPlayer{}
{
}

Food::~Food()
{
}

void Food::Initialize(GameObject* player, GameObject* b, int posx)
{
	// �v���C���[�̃|�C���^���擾
	mpPlayer = player;
	// �v���C���[�̍��W���擾
	mPlayerPos = mpPlayer->GetPlayerPos();

	// �t�[�h�͂Ȃ��Ƃ���
	mFoodFlag = false;

	// �t�[�h�̈ʒu��������
	mPos.mX = -5;
	mPos.mY = -5;
}

 
void Food::Update()
{
	// �v���C���[�̍��W���擾
	mPlayerPos = mpPlayer->GetPlayerPos();

	if (mFoodFlag == false)
	{
		// �a�𐶐�����
		this->AddFood();
	}


}

// �`��
void Food::Draw()
{
	// �t�[�h�̕`��
	if (mFoodFlag)
	{
		DrawBox(mPos.mX, mPos.mY, mPos.mX + 15, mPos.mY + 15, GetColor(0, 255, 0), true);
	}
}

void Food::Finalize()
{
}

// �t�[�h��u���ꏊ��T��
void Food::AddFood()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// �������擾
	int x = (2+GetRand(35)) * 16;
	int y = (2+GetRand(25)) * 16;

	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		if (mPlayerPos[i].mX == x && mPlayerPos[i].mY == y)
		{
			mFoodFlag = false;
			return;
		}
	}

	// 
	mPos.mX = x;
	mPos.mY = y;

	mFoodFlag = true;

}

// �t�[�h���Ȃ��Ƃ���
void Food::FalseFood()
{
	mFoodFlag = false;
}

Int2 Food::GetPos()
{
	return mPos;
}

