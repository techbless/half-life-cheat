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
			LPVOID base = (LPVOID)0x2208BA43;
			BYTE buffer[5] = { 0x89, 0x10, 0xC2, 0x04, 0x00 };
			BOOL is_successed = WriteProcessMemory(hProcess, base, buffer, sizeof(buffer), NULL);
			base = (LPVOID)0x2209A5D1;
			BYTE buffer1[6] = { 0x89, 0x9E, 0xC4, 0x04, 0x00, 0x00 };
			is_successed = WriteProcessMemory(hProcess, base, buffer1, sizeof(buffer1), NULL);
			base = (LPVOID)0x22143A09;
			BYTE buffer2[7] = { 0x89, 0x9C, 0xBE, 0x30, 0x06, 0x00, 0x00 };
			is_successed = WriteProcessMemory(hProcess, base, buffer2, sizeof(buffer2), NULL);
		}

	}
	else {
		int select = MessageBox(NULL, "Are you sure that you want infinity bullet?", "1/2 Life", MB_YESNO);
		if (select == IDYES) {
			LPVOID base = (LPVOID)0x2208BA43;
			BYTE buffer[2] = { 0x90, 0x90 };
			BOOL is_successed = WriteProcessMemory(hProcess, base, buffer, sizeof(buffer), NULL);
			base = (LPVOID)0x2209A5D1;
			BYTE buffer1[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
			is_successed = WriteProcessMemory(hProcess, base, buffer1, sizeof(buffer1), NULL);
			base = (LPVOID)0x22143A09;
			BYTE buffer2[7] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
			is_successed = WriteProcessMemory(hProcess, base, buffer2, sizeof(buffer2), NULL);

		}

	}
	return 0;
	
}

