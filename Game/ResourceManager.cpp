#include "ResourceManager.h"
/*----------------------------------------------
�R���X�g���N�^
-------------------------------------------------*/
ResourceManager::ResourceManager()
	:mTextures{}
{
}

/*-----------------------------------------------
�f�X�g���N�^
-----------------------------------------------*/
ResourceManager::~ResourceManager()
{
}

/*----------------------------------------------
�e�N�X�`���̓ǂݍ���
����	: TEXTURE id (�摜�ԍ�) , std::string pash (�摜�p�X)
-------------------------------------------------*/
int ResourceManager::LoadTexture(eTEXTURE textureId, std::string path)
{
	// �񋓌^�𐮐��^�ɃL���X�g
	int id = static_cast<int>(textureId);

	// �摜���ǂݍ��܂�Ă����珈�����Ȃ�
	if (mTextures[id] > 0)
	{
		return mTextures[id];
	}

	// �p�X������̐���
	std::string texturePath = "Resources/Textures/" + path;
	//!! ������A��

	// �摜�ǂݍ���
	int handle = LoadGraph(texturePath.c_str());
	//!! string�^��char�^�ɕϊ����Ă���

	// �摜�ǂݍ��݂ɐ������Ă�����n���h����ۑ�
	mTextures[id] = handle;

	// �n���h���ԍ���ԋp
	return mTextures[id];
}

/*----------------------------------------------------
�e�N�X�`���̎擾
����	�@: TEXTURE id (�摜�ԍ�)
---------------------------------------------------*/
int ResourceManager::GetTexture(eTEXTURE textureId)
{
	// �񋓌^�𐮐��ɃL���X�g
	int id = static_cast<int>(textureId);

	return mTextures[id];
}

/*-------------------------------------------------
�摜�̍폜
����	 : TEXTURE id (�摜�ԍ�)
---------------------------------------------------*/
void ResourceManager::DeleteTexture(eTEXTURE textureId)
{
	// �񋓌^�𐮐��^�ɃL���X�g
	int id = static_cast<int>(textureId);

	// �n���h�������݂��Ȃ���Ώ������Ȃ�
	if (mTextures[id]<= 0)
	{
		return;
	}

	// �摜�̍폜
	DeleteGraph(mTextures[id]);

	// �摜�n���h����0�Ń��Z�b�g
	mTextures[id] = 0;
}

/*-----------------------------------------------
�S�摜�̍폜
-----------------------------------------------*/
void ResourceManager::DeleteTextureAll()
{
	// �񋓌^�̍ő吔�𐮐��^�ɃL���X�g
	int max = static_cast<int>(eTEXTURE::MAX);

	// �S�摜�̍폜
	for (int i = 0; i < max; i++)
	{
		// �����^��񋓌^�ɃL���X�g
		eTEXTURE id = static_cast<eTEXTURE>(i);

		// �摜�̍폜
		DeleteTexture(id);
	}
}

