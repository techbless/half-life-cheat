#include <windows.h>
#include <stdio.h>

void hack(void);
int applyCheat(HANDLE hProcess);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	hack();
}

void hack(void)
{
	HWND hWnd = FindWindow(NULL, "HALF-LIFE");
	if (hWnd != NULL) {
		DWORD dwProcessId = 0;
		DWORD dwThreadId = 0;
		dwThreadId = GetWindowThreadProcessId(hWnd, &dwProcessId);
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
		applyCheat(hProcess);

	}
}

int applyCheat(HANDLE hProcess)
{
	BYTE res[1];
	ReadProcessMemory(hProcess, (LPVOID)0x2208BA43, res, 1, NULL);
	if (res[0] == 0x90) {
		int select = MessageBox(NULL, "do you want to go back?", "1/2 Life", MB_YESNO);
		if (select == IDYES) {
			const LPVOID base = (LPVOID)0x2208BA43;
			BYTE buffer[5] = { 0x89, 0x10, 0xC2, 0x04, 0x00 };
			BOOL is_successed = WriteProcessMemory(hProcess, base, buffer, sizeof(buffer), NULL);
			return is_successed == 0;
		}

	}
	else {
		int select = MessageBox(NULL, "Are you sure that you want infinity bullet?", "1/2 Life", MB_YESNO);
		if (select == IDYES) {
			const LPVOID base = (LPVOID)0x2208BA43;
			BYTE buffer[2] = { 0x90, 0x90 };
			BOOL is_successed = WriteProcessMemory(hProcess, base, buffer, sizeof(buffer), NULL);
			return is_successed == 0;
		}

	}
	
}

