#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
#include "ConvertEngine/Converter/TextureConverter/TextureConverter.h"

int main(int argc, char* argv[])
{
	// コマンドライン引数
	enum Argument
	{
		kApplicationPath, // アプリケーションのパス
		kFilePath,        // 渡されたファイルのパス
		NumArgument
	};

	assert(argc >= NumArgument);

	// COM ライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// テクスチャコンバータ
	TextureConverter converter;

	// テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	// COM ライブラリの終了
	CoUninitialize();
	
	system("pause");
	return 0;
}