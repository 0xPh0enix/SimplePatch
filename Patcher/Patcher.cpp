#include <Windows.h>
#include <stdio.h>

int main()
{
	SetConsoleTitleA("Simple C++ Binary Patch by 0xPh0enix");

	HANDLE hFile = CreateFileA("Test.exe", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	DWORD dwWritten = 0;
	DWORD dwOffset = 0x130D;

	if (hFile == INVALID_HANDLE_VALUE) {
		MessageBoxA(NULL, "Failed patch file: " + GetLastError(), "", MB_OK);
	}

	char patch[] = { 'A' };

	//0x00006135

	SetFilePointer(hFile, dwOffset, 0, FILE_BEGIN);
	WriteFile( hFile, patch, sizeof(patch), &dwWritten, NULL);
	CloseHandle(hFile);





}