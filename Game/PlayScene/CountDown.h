/*
�J�E���g�_�E��
*/
#pragma once
class CountDown
{
private:
	// �J�E���g�_�E���p�^�C�}�[
	int mTimer;

public:
	CountDown();
	~CountDown();

	// ������
	void Initialize();

	// �X�V
	void Update();

	// �`��
	void Draw();

	// �^�C�}�[���K��
	int GetTimer();
};