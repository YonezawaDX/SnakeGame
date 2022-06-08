/*
リソースの管理クラス
*/
#pragma once

#include <string>

//
//


// テクスチャの種類
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

	// どこからでもアクセスできるようにするための処理
	static ResourceManager* GetInstance()
	{
		static ResourceManager instance;

		return &instance;
	}

private:

	// テクスチャの配列
	int mTextures[static_cast<int>(eTEXTURE::MAX)];

public:

	// コンストラクタ
	ResourceManager();

	// デストラクタ
	~ResourceManager();

	// テクスチャの読み込み
	int LoadTexture(eTEXTURE textureId, std::string path);

	// テクスチャの取得
	int GetTexture(eTEXTURE textureId);

	// 画像の削除
	void DeleteTexture(eTEXTURE textureId);

	// 全画像の削除
	void DeleteTextureAll();
};