#include"Process.h"

void SetCreateProcess(char cmd[])
{
	STARTUPINFO si = {};
	PROCESS_INFORMATION pi = {};
	if (CreateProcess(
		NULL,
		cmd,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	))
	{
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		DrawFormatString(50, 50, GetColor(255, 0, 0), "ê¨å˜");
	}
	else
	{

	}
}