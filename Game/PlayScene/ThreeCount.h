/*
�J�E���g�_�E���\����
*/
#pragma once
class ThreeCount
{
private:
	// �ϐ�=====================================

	// �J�E���g�_�E���p�^�C�}�[
	int mTimer;
public:
	// �֐�=====================================
	ThreeCount();
	~ThreeCount();

	// ������
	void Initialize();

	// �X�V
	void Update();

	// �`��
	void Draw();

	// �^�C�}�[���K��
	int GetTimer();

};