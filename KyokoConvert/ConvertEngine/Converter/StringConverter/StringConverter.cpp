#include "StringConverter.h"
#include <Windows.h>

std::wstring StringConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	if (mString.empty()) {
		return std::wstring();
	}

	int sizeNeeded = MultiByteToWideChar(CP_UTF8, 0, reinterpret_cast<const char*>(&mString[0]), static_cast<int>(mString.size()), NULL, 0);
	if (sizeNeeded == 0) {
		return std::wstring();
	}
	std::wstring result(sizeNeeded, 0);
	MultiByteToWideChar(CP_UTF8, 0, reinterpret_cast<const char*>(&mString[0]), static_cast<int>(mString.size()), &result[0], sizeNeeded);
	return result;
}

std::string StringConverter::ConvertWideStringToMultiByteString(const std::wstring& wString)
{
	if (wString.empty()) {
		return std::string();
	}

	int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, wString.data(), static_cast<int>(wString.size()), NULL, 0, NULL, NULL);
	if (sizeNeeded == 0) {
		return std::string();
	}
	std::string result(sizeNeeded, 0);
	WideCharToMultiByte(CP_UTF8, 0, wString.data(), static_cast<int>(wString.size()), result.data(), sizeNeeded, NULL, NULL);
	return result;
}
