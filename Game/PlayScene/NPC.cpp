#include "NPC.h"
#include "../GameMain.h"
#include <cstdlib>
#include <ctime>
#include "../GameData.h"

NPC::NPC()
	:mPlayerPos{}
	, mPlayerState{}
	, mIntervalTimer{}
	, mSnakeMove{}
	, mPlayerPosNum{}
	, mPlayerTail{}
	, mTailTimer{}
	, mTailRand{}
	, mTailPos{}
	, mTailFlag{ false }
	, mAppTimer{}
	, mFoodPos{}
	, mFoodPos2{}
	, mRush{}
	, mRushCount{}
	, mRushFlag{}
	, mRushTime{}
{
}

NPC::~NPC()
{
}

void NPC::Initialize(GameObject* pPlayer, GameObject* pFood, int posX)
{
	// �v���C���[�̃|�C���^������
	mpPlayer = pPlayer;

	// �t�[�h�̃|�C���^������
	mpFood = pFood;


	// �v���C���[�̓��͂�ϊ��p�̕ϐ�
	mSnakeMove = posX;


	// �v���C���[�̑̂̑傫�����w��(-1�ōl����)
	mPlayerPos.resize(4);

	// �������W���w��
	mPlayerPos[0].mX = posX;
	mPlayerPos[0].mY = SCREEN_CENTER_Y;

	mPlayerPos[1].mX = posX;
	mPlayerPos[1].mY = SCREEN_CENTER_Y;

	mPlayerPos[2].mX = posX;
	mPlayerPos[2].mY = SCREEN_CENTER_Y + 16;

	mPlayerPos[3].mX = posX;
	mPlayerPos[3].mY = SCREEN_CENTER_Y + 32;

	// ���ɍs���Ƃ���
	mPlayerState = ePlayerState::UP;

	// �ːi�̑��x
	mRush = 8;

	// �ːi�ł����
	mRushCount = 5;
}


void NPC::Update()
{

	// �K���̓���
	if (mTailFlag && mAppTimer <= 150)
	{
		this->PlayerTailMove();
	}

	++mIntervalTimer %= mRush;

	if (mIntervalTimer != 0)
	{
		return;
	}
	// ���쏈��
	this->Move(mSnakeMove);


	// �ǂɂԂ������Ƃ��̏���
	this->Stage();

	int moveX = 0;
	int moveY = 0;


	mPos.mX = mPlayerPos[mPlayerPos.size() - 1].mX;
	mPos.mY = mPlayerPos[mPlayerPos.size() - 1].mY;



	// �ړ�����
	if (mPlayerState == ePlayerState::UP)
	{
		moveY--;
	}
	if (mPlayerState == ePlayerState::DOWN)
	{
		moveY++;
	}
	if (mPlayerState == ePlayerState::LEFT)
	{
		moveX--;
	}
	if (mPlayerState == ePlayerState::RIGHT)
	{
		moveX++;
	}

	int x = mPos.mX + moveX;
	int y = mPos.mY + moveY;


	mPlayerPos[0].mX += moveX * 16;
	mPlayerPos[0].mY += moveY * 16;



	// �擪�ɗv�f��ǉ�
	mPlayerPos.push_front(mPlayerPos[0]);

	// �Ō������
	mPlayerPos.pop_back();


	// �Փ˂�a�̂Ƃ��̏���---------------------------------------

	// �Փ˂���������
	if (this->Collision())
	{
		// �Ō������
		mPlayerPos.pop_back();
		mPlayerPos.pop_back();

	}

	// �a��H�ׂ��Ƃ��̏���
	if (this->EatFlag())
	{
		mpFood->FalseFood();
		// �̂��̂΂�
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);

	}

	// �a��H�ׂ��Ƃ��̏���
	if (this->EatTail() && mAppTimer > 30)
	{
		mTailFlag = false;
		// �̂��̂΂�
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);

	}

	// �a��H�ׂ��Ƃ��̏���
	if (this->EatTail2() && mpPlayer->GetTimer() > 30)
	{
		// false�ɂ���
		mpPlayer->ChangeTailState();
		// �̂��̂΂�
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);
		mPlayerPos.push_back(mPlayerPos[mPlayerPos.size() - 1]);

	}





	// �K���̏o���^�C�}�[��߂�
	if (mAppTimer > 150)
	{
		mAppTimer = 0;
		mTailFlag = false;
	}

	// ���̓��ɓ��Ă�ꂽ�Ƃ��̏���
	if (this->PlayerCollision() && mTailFlag == false)
	{
		// �v���C���[�̐K���𐶐�
		this->PlayerTail();

		// �v���C���[�̏Փ˂�����������
		mPlayerPos.erase(mPlayerPos.begin() + mPlayerPosNum + 1, mPlayerPos.end());
	}

	if (mTailFlag == false)
	{
		if (mPlayerTail.empty())
		{
			return;
		}
		mPlayerTail.clear();
	}

	if (mpPlayer->GetTailState() == false)
	{
		if (mFoodPos2.empty())
		{
			return;
		}
		mFoodPos2.clear();
	}

	// SNAKE�̑傫�����擾
	//if (mSnakeMove == SCREEN_CENTER_X + 32)
	//{
	//	g_size.mPlayerSize = mPlayerPos.size();
	//}
	//if (mSnakeMove == SCREEN_CENTER_X - 32)
	//{
	//	g_size.mPlayerSize2 = mPlayerPos.size();
	//}
}

void NPC::Draw()
{
	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		DrawBox(mPlayerPos[i].mX, mPlayerPos[i].mY, mPlayerPos[i].mX + 15, mPlayerPos[i].mY + 15, GetColor(150, 150, 150), true);
	}

	for (unsigned int i = 0; i < mPlayerTail.size(); i++)
	{
		if (mTailFlag)
		{
			DrawBox(mPlayerTail[i].mX, mPlayerTail[i].mY, mPlayerTail[i].mX + 15, mPlayerTail[i].mY + 15, GetColor(0, 255, 0), true);
		}
	}
}

void NPC::Finalize()
{
}

// ���쏈��
void NPC::Move(int a)
{
	if (mPlayerPos.empty() || mPlayerPos2.empty())
	{
		return;
	}
	// �v���C���[���͈͓��ɂ�����
	if (mPlayerPos2[0].mX + 160 >= mPlayerPos[0].mX && mPlayerPos2[0].mX - 160 <= mPlayerPos[0].mX&&
		mPlayerPos2[0].mY + 160 >= mPlayerPos[0].mY && mPlayerPos2[0].mY - 160 <= mPlayerPos[0].mY)
	{
		if (mPlayerPos2.size() >= 6)
		{
			// ���쏈��
			if (mPlayerPos2[5].mY < mPlayerPos[0].mY && mPlayerState != ePlayerState::DOWN)
			{
				mPlayerState = ePlayerState::UP;
			}
			if (mPlayerPos2[5].mY > mPlayerPos[0].mY && mPlayerState != ePlayerState::UP)
			{
				mPlayerState = ePlayerState::DOWN;
			}
			else if (mPlayerPos2[5].mX < mPlayerPos[0].mX && mPlayerState != ePlayerState::RIGHT)
			{
				mPlayerState = ePlayerState::LEFT;
			}
			else if (mPlayerPos2[5].mX < mPlayerPos[0].mX && mPlayerState != ePlayerState::LEFT)
			{
				mPlayerState = ePlayerState::RIGHT;
			}
		}
	}
	// �v���C���[���͈͊O�ɂ�����a��ǂ�������
	else
	{
		// ���쏈��
		if (mpFood->GetPos().mY < mPlayerPos[0].mY && mPlayerState != ePlayerState::DOWN)
		{
			mPlayerState = ePlayerState::UP;
		}
		if (mpFood->GetPos().mY > mPlayerPos[0].mY && mPlayerState != ePlayerState::UP)
		{
			mPlayerState = ePlayerState::DOWN;
		}
		if (mpFood->GetPos().mX < mPlayerPos[0].mX && mPlayerState != ePlayerState::RIGHT)
		{
			mPlayerState = ePlayerState::LEFT;
		}
		if (mpFood->GetPos().mX > mPlayerPos[0].mX && mPlayerState != ePlayerState::LEFT)
		{
			mPlayerState = ePlayerState::RIGHT;
		}
	}
	g_gameData.gLength2 = mPlayerPos.size() - 1;
}

std::deque<Int2> NPC::GetPlayerPos()
{
	return std::deque<Int2>(mPlayerPos);
}

// �Փ˂���������
bool NPC::Collision()
{
	// �Փ˂��������
	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		if (i == 0 || i == 1)
		{
			continue;
		}


		if (mPlayerPos[0].mX == mPlayerPos[i].mX && mPlayerPos[0].mY == mPlayerPos[i].mY ||
			mPlayerPos[1].mX == mPlayerPos[i].mX && mPlayerPos[1].mY == mPlayerPos[i].mY)
		{

			return true;
		}
	}

	return false;
}

// ���̃v���C���[�Ƃ̔���
bool NPC::PlayerCollision()
{
	mPlayerPos2 = mpPlayer->GetPlayerPos();

	for (unsigned int i = 0; i < mPlayerPos.size(); i++)
	{
		if (i == 0 || i == 1)
		{
			continue;
		}


		if (// �G����������Ă���Ƃ�
			mpPlayer->GetPlayerState() == ePlayerState::UP &&
			mPlayerPos2[0].mX == mPlayerPos[i].mX && mPlayerPos2[0].mY - 16 == mPlayerPos[i].mY ||
			// �G�����������Ă���Ƃ�
			mpPlayer->GetPlayerState() == ePlayerState::DOWN &&
			mPlayerPos2[0].mX == mPlayerPos[i].mX && mPlayerPos2[0].mY + 16 == mPlayerPos[i].mY ||
			// �G�����������Ă���Ƃ�
			mpPlayer->GetPlayerState() == ePlayerState::LEFT &&
			mPlayerPos2[0].mX - 16 == mPlayerPos[i].mX && mPlayerPos2[0].mY == mPlayerPos[i].mY ||
			// �G���E�������Ă���Ƃ�
			mpPlayer->GetPlayerState() == ePlayerState::RIGHT &&
			mPlayerPos2[0].mX + 16 == mPlayerPos[i].mX && mPlayerPos2[0].mY == mPlayerPos[i].mY
			)
		{
			// �ǂ��ō폜���������ۑ�����
			mPlayerPosNum = i;

			return true;
		}
	}

	return false;

}

// �t�[�h��H�ׂ��Ƃ��̔���
bool NPC::EatFlag()
{
	if (mPlayerPos[0].mX == mpFood->GetPos().mX && mPlayerPos[0].mY == mpFood->GetPos().mY)
	{
		return true;
	}

	return false;
}

// �K����H�ׂ��Ƃ��̐ݒ�
bool NPC::EatTail()
{
	for (unsigned int i = 0; i < mPlayerTail.size(); i++)
	{
		if (mPlayerPos[0].mX == mPlayerTail[i].mX && mPlayerPos[0].mY == mPlayerTail[i].mY)
		{
			return true;
		}
	}

	return false;
}

bool NPC::EatTail2()
{
	mFoodPos2 = mpPlayer->GetTailPos();

	for (unsigned int i = 0; i < mFoodPos2.size(); i++)
	{
		if (mPlayerPos[0].mX == mFoodPos2[i].mX && mPlayerPos[0].mY == mFoodPos2[i].mY)
		{
			return true;
		}
	}

	return false;
}

// �v���C���[�̑���󋵂�n��
int NPC::GetPlayerState()
{
	return mPlayerState;
}

// �v���C���[�̐K����
void NPC::PlayerTail()
{
	// �v���C���[�Ɠ������Ă��Ȃ������珈�����Ȃ�
	if (this->PlayerCollision() == false)
	{
		return;
	}

	// �K���̑傫��������
	mPlayerTail.resize(mPlayerPos.size() - mPlayerPosNum);

	for (unsigned int i = 1; i <= mPlayerTail.size(); i++)
	{
		mPlayerTail[i - 1].mX = mPlayerPos[mPlayerPos.size() - i].mX;
		mPlayerTail[i - 1].mY = mPlayerPos[mPlayerPos.size() - i].mY;
	}

	// �t���O�������ۂ�����Ɗm�F
	mTailFlag = true;

}

void NPC::PlayerTailMove()
{
	++mTailTimer %= 5;
	if (mTailTimer != 0)
	{
		return;
	}

	mTailRand = rand() % 5;

	int moveX = 0;
	int moveY = 0;

	mTailPos.mX = mPlayerTail[mPlayerTail.size() - 1].mX;
	mTailPos.mY = mPlayerTail[mPlayerTail.size() - 1].mY;



	// �ړ�����
	if (mTailRand == ePlayerState::UP)
	{
		moveY--;
	}
	if (mTailRand == ePlayerState::DOWN)
	{
		moveY++;
	}
	if (mTailRand == ePlayerState::LEFT)
	{
		moveX--;
	}
	if (mTailRand == ePlayerState::RIGHT)
	{
		moveX++;
	}

	// ��Ɍ������Ă���Ƃ��̏���
	if (mPlayerTail[0].mY - 16 < SCREEN_TOP && mTailRand == ePlayerState::UP)
	{
		mTailRand = ePlayerState::RIGHT;
	}

	// ���Ɍ������Ă���Ƃ��̏���
	if (mPlayerTail[0].mY + 32 > SCREEN_BOTTOM && mTailRand == ePlayerState::DOWN)
	{
		mTailRand = ePlayerState::LEFT;
	}

	// ���Ɍ������Ă���Ƃ��̏���
	if (mPlayerTail[0].mX - 16 < SCREEN_LEFT && mTailRand == ePlayerState::LEFT)
	{
		mTailRand = ePlayerState::UP;
	}

	// �E�Ɍ������Ă���Ƃ��̏���
	if (mPlayerTail[0].mX + 32 > SCREEN_RIGHT && mTailRand == ePlayerState::RIGHT)
	{
		mTailRand = ePlayerState::DOWN;
	}



	int x = mTailPos.mX + moveX;
	int y = mTailPos.mY + moveY;


	mPlayerTail[0].mX += moveX * 16;
	mPlayerTail[0].mY += moveY * 16;



	// �擪�ɗv�f��ǉ�
	mPlayerTail.push_front(mPlayerTail[0]);

	// �Ō������
	mPlayerTail.pop_back();

	mAppTimer++;
}

bool NPC::GetTailState()
{
	return mTailFlag;
}

int NPC::GetTimer()
{
	return mAppTimer;
}

void NPC::ChangeTailState()
{
	mTailFlag = false;
}

// �K���̍��W��n��
std::deque<Int2> NPC::GetTailPos()
{
	return mPlayerTail;
}

void NPC::Stage()
{
	// ��Ɍ������Ă���Ƃ��̏���
	if (mPlayerPos[0].mY - 16 < SCREEN_TOP && mPlayerState == ePlayerState::UP)
	{
		mPlayerState = ePlayerState::RIGHT;
	}

	// ���Ɍ������Ă���Ƃ��̏���
	if (mPlayerPos[0].mY + 32 > SCREEN_BOTTOM && mPlayerState == ePlayerState::DOWN)
	{
		mPlayerState = ePlayerState::LEFT;
	}

	// ���Ɍ������Ă���Ƃ��̏���
	if (mPlayerPos[0].mX - 16 < SCREEN_LEFT && mPlayerState == ePlayerState::LEFT)
	{
		mPlayerState = ePlayerState::UP;
	}

	// �E�Ɍ������Ă���Ƃ��̏���
	if (mPlayerPos[0].mX + 32 > SCREEN_RIGHT && mPlayerState == ePlayerState::RIGHT)
	{
		mPlayerState = ePlayerState::DOWN;
	}

	// ���ʏՓ˂����ꍇ

}

// �ːi����Ƃ��̏���
void NPC::Rush()
{
	mRushCount--;
	mRush = 2;
	mRushFlag = true;
}

