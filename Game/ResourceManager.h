/*
���\�[�X�̊Ǘ��N���X
*/
#pragma once

#include <string>

//
//


// �e�N�X�`���̎��
enum class eTEXTURE : int
{
	MAP_TITLE,
	CHARA,
	TRIDENT_LOGO,
	BOX,

	MAX,
};

class ResourceManager
{
public:

	// �ǂ�����ł��A�N�Z�X�ł���悤�ɂ��邽�߂̏���
	static ResourceManager* GetInstance()
	{
		static ResourceManager instance;

		return &instance;
	}

private:

	// �e�N�X�`���̔z��
	int mTextures[static_cast<int>(eTEXTURE::MAX)];

public:

	// �R���X�g���N�^
	ResourceManager();

	// �f�X�g���N�^
	~ResourceManager();

	// �e�N�X�`���̓ǂݍ���
	int LoadTexture(eTEXTURE textureId, std::string path);

	// �e�N�X�`���̎擾
	int GetTexture(eTEXTURE textureId);

	// �摜�̍폜
	void DeleteTexture(eTEXTURE textureId);

	// �S�摜�̍폜
	void DeleteTextureAll();
};