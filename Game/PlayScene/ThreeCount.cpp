/*
�J�E���g�_�E���̍\����
�쐬�� :
�쐬�� : ���V�x��
*/
#include "ThreeCount.h"
#include "../GameMain.h"

// �J�E���g�_�E���̕b��
#define COUNTDOWN_TIME		(3 * 60)

// �J�E���g�_�E���̕����T�C�Y
#define COUNTDOWN_SIZE		100

// �J�E���g�_�E���̕����̕\���ʒu
#define COUNTDOWN_POS_X		(SCREEN_CENTER_X - 25)
#define COUNTDOWN_POS_Y		(SCREEN_CENTER_Y - 50)

ThreeCount::ThreeCount()
{
}
ThreeCount::~ThreeCount()
{
}

/*---------------------------------
�J�E���g�_�E���̏�����
-----------------------------------*/
void ThreeCount::Initialize()
{
	mTimer = COUNTDOWN_TIME;
}

/*-----------------------------------
�J�E���g�_�E���̍X�V
-------------------------------------*/
void ThreeCount::Update(void)
{
	// �J�E���g�_�E��
	mTimer--;
}

/*------------------------------------
�J�E���g�_�E���̕`��
-------------------------------------*/
void ThreeCount::Draw(void)
{
	// ���̕����T�C�Y���擾
	int defaultSize = GetFontSize();

	// �����T�C�Y�̐ݒ�
	SetFontSize(COUNTDOWN_SIZE);

	// �J�E���g�_�E���̐�����\��
	DrawFormatString(
		COUNTDOWN_POS_X,
		COUNTDOWN_POS_Y,
		GetColor(255, 0, 0),
		"%d",
		(mTimer / 60) + 1
	);

	// �ŏ��̕����̃T�C�Y�ɖ߂�
	SetFontSize(defaultSize);
}

int ThreeCount::GetTimer()
{
	return mTimer;
}
