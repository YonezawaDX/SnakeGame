/*
�J�E���g�_�E��
*/
#include "Countdown.h"
#include "../GameMain.h"

// �J�E���g�_�E���̕b��
#define COUNTDOWN_TIME		(50 * 60)

// �J�E���g�_�E���̕����T�C�Y
#define COUNTDOWN_SIZE		16

// �J�E���g�_�E���̕����̕\���ʒu
#define COUNTDOWN_POS_X		(SCREEN_RIGHT - 60)
#define COUNTDOWN_POS_Y		(SCREEN_CENTER_Y - 215)

CountDown::CountDown()
	:mTimer{}
{
}

CountDown::~CountDown()
{
}

// ������
void CountDown::Initialize()
{
	mTimer = COUNTDOWN_TIME;
}

// �X�V
void CountDown::Update()
{
	// �J�E���g�_�E��
	mTimer--;
}

// �`��
void CountDown::Draw()
{
	// ���̕����T�C�Y���擾
	int defaultSize = GetFontSize();

	// �����T�C�Y�̐ݒ�
	SetFontSize(COUNTDOWN_SIZE);


	// �J�E���g�_�E���̐�����\��
	DrawFormatString(
		COUNTDOWN_POS_X-50,
		COUNTDOWN_POS_Y,
		GetColor(255, 255, 255),
		"TIME");

	// �J�E���g�_�E���̐�����\��
	DrawFormatString(
		COUNTDOWN_POS_X,
		COUNTDOWN_POS_Y,
		GetColor(255, 255, 255),
		"%d",
		(mTimer / 60)
	);

	// �ŏ��̕����̃T�C�Y�ɖ߂�
	SetFontSize(defaultSize);
}

// �^�C�}�[��n��
int CountDown::GetTimer()
{
	return mTimer;
}