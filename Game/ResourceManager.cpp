#include "ResourceManager.h"
/*----------------------------------------------
コンストラクタ
-------------------------------------------------*/
ResourceManager::ResourceManager()
	:mTextures{}
{
}

/*-----------------------------------------------
デストラクタ
-----------------------------------------------*/
ResourceManager::~ResourceManager()
{
}

/*----------------------------------------------
テクスチャの読み込み
引数	: TEXTURE id (画像番号) , std::string pash (画像パス)
-------------------------------------------------*/
int ResourceManager::LoadTexture(eTEXTURE textureId, std::string path)
{
	// 列挙型を整数型にキャスト
	int id = static_cast<int>(textureId);

	// 画像が読み込まれていたら処理しない
	if (mTextures[id] > 0)
	{
		return mTextures[id];
	}

	// パス文字列の生成
	std::string texturePath = "Resources/Textures/" + path;
	//!! 文字列連結

	// 画像読み込み
	int handle = LoadGraph(texturePath.c_str());
	//!! string型をchar型に変換している

	// 画像読み込みに成功していたらハンドルを保存
	mTextures[id] = handle;

	// ハンドル番号を返却
	return mTextures[id];
}

/*----------------------------------------------------
テクスチャの取得
引数	　: TEXTURE id (画像番号)
---------------------------------------------------*/
int ResourceManager::GetTexture(eTEXTURE textureId)
{
	// 列挙型を整数にキャスト
	int id = static_cast<int>(textureId);

	return mTextures[id];
}

/*-------------------------------------------------
画像の削除
引数	 : TEXTURE id (画像番号)
---------------------------------------------------*/
void ResourceManager::DeleteTexture(eTEXTURE textureId)
{
	// 列挙型を整数型にキャスト
	int id = static_cast<int>(textureId);

	// ハンドルが存在しなければ処理しない
	if (mTextures[id]<= 0)
	{
		return;
	}

	// 画像の削除
	DeleteGraph(mTextures[id]);

	// 画像ハンドルを0でリセット
	mTextures[id] = 0;
}

/*-----------------------------------------------
全画像の削除
-----------------------------------------------*/
void ResourceManager::DeleteTextureAll()
{
	// 列挙型の最大数を整数型にキャスト
	int max = static_cast<int>(eTEXTURE::MAX);

	// 全画像の削除
	for (int i = 0; i < max; i++)
	{
		// 整数型を列挙型にキャスト
		eTEXTURE id = static_cast<eTEXTURE>(i);

		// 画像の削除
		DeleteTexture(id);
	}
}

