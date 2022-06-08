/*
�^�C�g���V�[��
*/
#include "TitleScene.h"
#include "../PlayScene/NPC.h"
#include "../PlayScene/Food.h"

#include "../GameMain.h"
#include "../GameData.h"

// �^�C�g�����W
#define TITLE_POS_X			(SCREEN_CENTER_X - 100)
#define TITLE_POS_Y			(SCREEN_CENTER_Y - 80)

// �^�C�g�����S�T�C�Y
#define TITLE_LOGO_SIZE			60

// �L�[���͂̕����ʒu
#define PUSHKEY_POS_X		(SCREEN_CENTER_X - 60)
#define PUSHKEY_POS_Y		(SCREEN_CENTER_Y + 150)

// �L�[���͂̕����_�ŊԊu
#define PUSHKEY_INTERVAL	30
/*--------------------------------------------------
�R���X�g���N�^
--------------------------------------------------*/
TitleScene::TitleScene()
	:mIsDrawString{}
	,mTimer{}
	,mpNpc{}
	,mpNpc2{}
	,mpFood{}
	,mTitleSe{}
{

}
/*--------------------------------------------------
�f�X�g���N�^
--------------------------------------------------*/
TitleScene::~TitleScene()
{
	this->Finalize();
}

/*--------------------------------------------------
������
--------------------------------------------------*/
void TitleScene::Initialize()
{

	mpNpc = new NPC();
	mpNpc2 = new NPC();
	mpFood = new Food();

	mpNpc->Initialize(mpNpc2, mpFood, SCREEN_CENTER_X + 32);
	mpNpc2->Initialize(mpNpc, mpFood, SCREEN_CENTER_X - 3200);

	mpFood->Initialize(mpNpc, mpNpc2, SCREEN_CENTER_X);

	mIsDrawString = false;

	mTimer = 0;

	g_gameData.Initialize();

	// �������[�h����
	mTitleSe = LoadSoundMem("Resources/Audio/Title.mp3");
	PlaySoundMem(mTitleSe, DX_PLAYTYPE_LOOP);
}

/*--------------------------------------------------
�X�V
�߂�l	:���̃V�[���ԍ�
--------------------------------------------------*/
GAME_SCENE TitleScene::Update()
{
	mpNpc->Update();

	mpFood->Update();

	// �^�C�}�[��i�߂�
	++mTimer %= PUSHKEY_INTERVAL;

	// �����̕\���t���O��؂�ւ���
	if (mTimer == 0)
	{
		mIsDrawString = !mIsDrawString;
	}

	// �v���C��Ԃ�ύX����
	if (IsButtonPressed(PAD_INPUT_UP) || IsButtonPressed(PAD_INPUT_UP, 1) ||
		IsButtonPressed(PAD_INPUT_DOWN) || IsButtonPressed(PAD_INPUT_DOWN, 1))
	{
		if (g_gameData.mState == ePlayState::PLAY_1P)
		{
			g_gameData.mState = ePlayState::PLAY_2P;
		}
		else if (g_gameData.mState == ePlayState::PLAY_2P)
		{
			g_gameData.mState = ePlayState::PLAY_1P;
		}
	}


	// �v���C�V�[����
	if (IsButtonPressed(PAD_INPUT_1) || IsButtonPressed(PAD_INPUT_1,1))
	{
		return GAME_SCENE::PLAY;
	}

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
�`��
--------------------------------------------------*/
void TitleScene::Draw()
{
	mpNpc->Draw();
	mpFood->Draw();

	// �^�C�g�����S�̕\��
	int defaultSize = GetFontSize();

	SetFontSize(TITLE_LOGO_SIZE);

	DrawFormatString(
		TITLE_POS_X,
		TITLE_POS_Y - 10,
		GetColor(255, 255, 0),
		"SNACK\nSNAKE"
	);

	SetFontSize(TITLE_LOGO_SIZE - 40);

	DrawFormatString(
		TITLE_POS_X + 60,
		TITLE_POS_Y + 150,
		GetColor(255, 255, 255),
		"1P Play\n2P Play"
	);

	// �^�C�g������n���e�V�[���ύX�ς݃X�e�[�g��n��

	if (g_gameData.mState == ePlayState::PLAY_1P)
	{
		DrawTriangle(TITLE_POS_X + 35, TITLE_POS_Y + 150,
			TITLE_POS_X + 35, TITLE_POS_Y + 165,
			TITLE_POS_X + 50, TITLE_POS_Y + 158, GetColor(255, 0, 0), true);
	}
	else if (g_gameData.mState == ePlayState::PLAY_2P)
	{
		DrawTriangle(TITLE_POS_X + 35, TITLE_POS_Y + 170,
			TITLE_POS_X + 35, TITLE_POS_Y + 185,
			TITLE_POS_X + 50, TITLE_POS_Y + 178, GetColor(255, 0, 0), true);
	}

	SetFontSize(defaultSize);

	// �L�[���͂𑣂������̕\��
	if (mIsDrawString == true)
	{
		DrawFormatString(
			PUSHKEY_POS_X,
			PUSHKEY_POS_Y,
			GetColor(255, 255, 0),
			"Push 1 Key"
		);
	}
}

/*--------------------------------------------------
�I������
--------------------------------------------------*/
void TitleScene::Finalize()
{
	if (mpNpc != nullptr)
	{
		delete mpNpc;
		mpNpc = nullptr;
	}
	if (mpNpc2 != nullptr)
	{
		delete mpNpc2;
		mpNpc2 = nullptr;
	}
	if (mpFood != nullptr)
	{
		delete mpFood;
		mpFood = nullptr;
	}

	StopSoundMem(mTitleSe);
}

