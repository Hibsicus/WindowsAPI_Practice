// Cplusplus_Normal.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>

#define BUF_SIZE 256

//�ɶ��ഫ���
DWORD ShowFileTime(PFILETIME lptime)
{
	FILETIME ftLocal;
	SYSTEMTIME st;
	FileTimeToLocalFileTime(lptime, &ftLocal);

	FileTimeToSystemTime(&ftLocal, &st);
	printf("%d�~%#02d��%#02d��, %#02d:%#02d:%#02d\n",st.wYear,
													st.wMonth,
													st.wDay,
													st.wHour,
													st.wMinute,
													st.wSecond);
	return 0;
}

int main()
{
	//ReadFile CreateFile �}�� Ū��
	/*HANDLE hFileRead;
	DWORD nIn;
	CHAR buffer[BUF_SIZE];

	hFileRead = CreateFile(TEXT("UseCplusplus.txt"),
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hFileRead == INVALID_HANDLE_VALUE)
	{
		printf("Cannot open file. Error: %x\n", GetLastError());
		system("pause");
		return -1;
	}

	while (ReadFile(hFileRead, buffer, BUF_SIZE, &nIn, NULL) && nIn > 0)
	{
		printf("%s\n", buffer);
	}

	CloseHandle(hFileRead);*/

	//End Read Create

	//GetFileAttributes ���ɮ��ݩ�

	/*WIN32_FILE_ATTRIBUTE_DATA wfad;
	if (!GetFileAttributesEx(TEXT("Cplusplus_Normal.cpp"),
		GetFileExInfoStandard,
		&wfad))
	{
		printf("Error: %d\n", GetLastError());
	}

	printf("�Ыخɶ�:\t");
	ShowFileTime(&wfad.ftCreationTime);
	printf("�̫�X�ݮɶ�:\t");
	ShowFileTime(&wfad.ftLastAccessTime);
	printf("�̫�ק�ɶ�:\t");
	ShowFileTime(&wfad.ftLastWriteTime);*/
	
	//EndFileAttritube

	//GetSystemDirectory Ū���t�Φ�m
	/*TCHAR szSystemDir[MAX_PATH];
	GetSystemDirectory(szSystemDir, MAX_PATH);
	printf("%s\n", szSystemDir);

	HANDLE hFile;
	DWORD dwWritten;
	hFile = CreateFile(TEXT("systemroot.txt"),
		GENERIC_WRITE,
		0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile != INVALID_HANDLE_VALUE)
	{
		if (!WriteFile(hFile, szSystemDir, lstrlen(szSystemDir), &dwWritten, NULL))
		{
			return GetLastError();
		}
	}

	CloseHandle(hFile);*/
	//End
	system("pause");
    return 0;
}

