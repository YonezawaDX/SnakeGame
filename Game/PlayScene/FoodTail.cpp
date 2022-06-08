/*
�t�[�h�̃N���X
*/
#include "FoodTail.h"
#include "GameObject.h"
#include "../GameMain.h"
#include "Player.h"


FoodTail::FoodTail()
	:mFoodFlag{}
	,mpPlayer{}
	,mpPlayer2{}
	,mFoodPosFlag{}
	,mFoodPosFlag2{}
	,mFoodPos{}
	,mFoodPos2{}
	,mPlayerPos{}
	,mPlayerPos2{}
{
}

FoodTail::~FoodTail()
{
}

void FoodTail::Initialize(GameObject* player, GameObject* player2, int posx)
{
	// �v���C���[�̃|�C���^���擾
	mpPlayer = player;

	mpPlayer2 = player2;

	// �t�[�h�͂Ȃ��Ƃ���
	mFoodFlag = false;

	// mFood
	mFoodPosFlag.resize(64);
	mFoodPosFlag2.resize(64);

	mFoodPos.resize(64);
	mFoodPos.resize(64);


	// �t�[�h�͂Ȃ��Ƃ���
	for (unsigned int i = 0; i < mFoodPosFlag.size(); i++)
	{
		mFoodPosFlag[i] = false;
	}

	// �t�[�h�͂Ȃ��Ƃ���
	for (unsigned int i = 0; i < mFoodPosFlag.size(); i++)
	{
		mFoodPosFlag2[i] = false;
	}
}


void FoodTail::Update()
{
	// �v���C���[�̍��W���擾
	mPlayerPos = mpPlayer->GetTailPos();

	mPlayerPos2 = mpPlayer2->GetTailPos();

	// �a�𐶐�����
	this->AddFood();
	// �a�𐶐�
	this->AddFood2();
	// �����v�f�ԍ��̂��̂�false�������ꍇ����
	for (unsigned int i = 0; i < mFoodPos.size(); i++)
	{

	}
} 

// �`��
void FoodTail::Draw()
{

	// �t�[�h�͂Ȃ��Ƃ���
	for (unsigned int j = 0; j < mFoodPosFlag.size(); j++)
	{
		if (mFoodPos.empty() || mFoodPos2.empty())
		{
			break;
		}
		// �t�[�h�̕`��
		if (mFoodPosFlag[j] == true)
		{
			DrawBox(mFoodPos[j].mX, mFoodPos[j].mY, mFoodPos[j].mX + 15, mFoodPos[j].mY + 15, GetColor(0, 255, 0), true);;
		}
		// �t�[�h�̕`��
		if (mFoodPosFlag2[j] == true)
		{
			DrawBox(mFoodPos2[j].mX, mFoodPos2[j].mY, mFoodPos2[j].mX + 15, mFoodPos2[j].mY + 15, GetColor(0, 255, 0), true);
		}
	}
}

void FoodTail::Finalize()
{
}

// �t�[�h��u���ꏊ��T��
void FoodTail::AddFood()
{
	// mPlayerPos�ɉ����Ȃ������珈����Ԃ�
	if (mPlayerPos.empty() || mFoodPos.empty())
	{
		return;
	}


	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		if (mFoodPosFlag[i] == false)
		{
			// �������擾
			mFoodPos[i].mX = mPlayerPos[0].mX;
			mFoodPos[i].mY = mPlayerPos[0].mY;

			mFoodPosFlag[i] = true;
			return;
		}
	}

}

void FoodTail::AddFood2()
{
	// mPlayerPos�ɉ����Ȃ������珈����Ԃ�
	if (mPlayerPos2.empty() || mFoodPos2.empty())
	{
		return;
	}

	for (unsigned int i = 0; i < mPlayerPos2.size(); i++)
	{
		if (mFoodPosFlag2[i] == false)
		{
			// �������擾
			mFoodPos2[i].mX = mPlayerPos2[0].mX;
			mFoodPos2[i].mY = mPlayerPos2[0].mY;

			mFoodPosFlag2[i] = true;
			return;
		}
	}
}

// �t�[�h���Ȃ��Ƃ���
void FoodTail::FalseFood()
{
	for (unsigned int k = 0; k < mFoodPosFlag.size(); k++)
	{
		if (mFoodPosFlag[k] == false)
		{
			continue;
		}

		mFoodPosFlag[k] = true;
		return;
	}

}

std::deque<Int2> FoodTail::GetTailPos()
{
	return mFoodPos;
}

void FoodTail::FalseFood2()
{
	for (unsigned int k = 0; k < mFoodPosFlag2.size(); k++)
	{
		if (mFoodPosFlag2[k] == false)
		{
			continue;
		}

		mFoodPosFlag2[k] = true;
		return;
	}
}


std::deque<Int2> FoodTail::GetTailPos2()
{
	return mFoodPos2;
}



