/*
�v���C�V�[��
*/
#include "ResultScene.h"

#include "../GameMain.h"
#include "../GameData.h"

// ���U���g�����̍��W
#define RESULT_LOGO_POS_X			(SCREEN_CENTER_X - 100)
#define RESULT_LOGO_POS_Y			(SCREEN_CENTER_Y - 100)

// ���U���g�����̃T�C�Y
#define RESULT_LOGO_SIZE			50

// ���ʕ����̍��W
#define RESULT_POS_X				(SCREEN_CENTER_X - 100)
#define RESULT_POS_Y				(SCREEN_CENTER_Y + 100)

// ���ʕ����̃T�C�Y
#define RESULT_SIZE					30
/*--------------------------------------------------
�R���X�g���N�^
--------------------------------------------------*/
ResultScene::ResultScene()
{
}

/*--------------------------------------------------
�f�X�g���N�^
--------------------------------------------------*/
ResultScene::~ResultScene()
{
}

/*--------------------------------------------------
������
--------------------------------------------------*/
void ResultScene::Initialize()
{
	mResultSe = LoadSoundMem("Resources/Audio/Result.mp3");
	PlaySoundMem(mResultSe, DX_PLAYTYPE_BACK);
}

/*--------------------------------------------------
�X�V
�߂�l	:���̃V�[���ԍ�
--------------------------------------------------*/
GAME_SCENE ResultScene::Update()
{
	if (IsButtonPressed(PAD_INPUT_1) || IsButtonPressed(PAD_INPUT_1, 1))
	{
		return GAME_SCENE::TITLE;
	}

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
�`��
--------------------------------------------------*/
void ResultScene::Draw()
{
	int defaultSize = GetFontSize();

	// ���U���g�����̕\��

	SetFontSize(RESULT_LOGO_SIZE);
	if (g_gameData.gLength > g_gameData.gLength2)
	{
		DrawFormatString(
			RESULT_LOGO_POS_X,
			RESULT_LOGO_POS_Y,
			GetColor(255, 255, 0),
			"1P WIN"
		);
	}
	if (g_gameData.gLength < g_gameData.gLength2)
	{
		DrawFormatString(
			RESULT_LOGO_POS_X,
			RESULT_LOGO_POS_Y,
			GetColor(255, 255, 0),
			"2P WIN"
		);
	}
	if (g_gameData.gLength == g_gameData.gLength2)
	{
		DrawFormatString(
			RESULT_LOGO_POS_X,
			RESULT_LOGO_POS_Y,
			GetColor(255, 255, 0),
			"DRAW"
		);
	}

	SetFontSize(RESULT_LOGO_SIZE - 30);
	DrawFormatString(
		RESULT_LOGO_POS_X -100,
		RESULT_LOGO_POS_Y + 100,
		GetColor(255, 255, 255),
		"1P Length\n     %d",g_gameData.gLength
	);
	DrawFormatString(
		RESULT_LOGO_POS_X + 120,
		RESULT_LOGO_POS_Y + 100,
		GetColor(255, 255, 255),
		"2P Length\n     %d", g_gameData.gLength2
	);
}

/*--------------------------------------------------
�I������
--------------------------------------------------*/
void ResultScene::Finalize()
{
}
