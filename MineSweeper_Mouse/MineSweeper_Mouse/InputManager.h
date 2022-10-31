#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Utils.h"
#include "GameManager.h"

using namespace std;

class InputManager :public GameManager
{
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	INPUT_RECORD irInBuf[128];

	COORD mousePos;

	VOID ErrorExit(LPCSTR lpszMessage)
	{
		fprintf(stderr, "%s\n", lpszMessage);

		// Restore input mode on exit.

		SetConsoleMode(hStdin, fdwSaveOldMode);

		ExitProcess(0);
	}

public:

	void readEveryFrame() {
		DWORD cNumRead = 0;

		Borland::GotoXY(0, 0);
		if (GetNumberOfConsoleInputEvents(hStdin, &cNumRead) == 0)
		{
			printf("Input Reading Failure %d\n", GetLastError());
			return;
		}

		if (cNumRead == 0) {
			printf("cNumRead = %d (no event)\n", cNumRead);
			return;
		}

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle
			irInBuf,     // buffer to read into
			128,         // size of read buffer
			&cNumRead)) // number of records read
			ErrorExit("ReadConsoleInput");

		printf("cNumRead = %d (event)   \n", cNumRead);

		for (int i = 0; i < (int)cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case MOUSE_EVENT: // mouse input
				mouseEvent(irInBuf[i].Event.MouseEvent);
				break;
			}
		}
	}

	void mouseEvent(MOUSE_EVENT_RECORD mer)
	{
		// ��Ŭ���� ������ ��
		if (GetAsyncKeyState(0x01))
		{
			// ���콺�� ��ġ�� �޾ƿͼ�
			mousePos = mer.dwMousePosition;
			// �ش� ��ġ�� ������ ���
			if (enemy[mousePos.X][mousePos.Y] == '*')
			{
				// ����
				exit(0);
			}
			else // ���ڰ� �ƴ� ���
			{
				// ������ ���ڰ� �ִ��� ������ Ž��

			}
		}

		// ��Ŭ���� ������ ��
		else if (GetAsyncKeyState(0x02))
		{
			// ���콺�� ��ġ�� �޾ƿͼ�
			mousePos = mer.dwMousePosition;
			// �ش� ��ġ�� ��߷� ����
			if (screen[mousePos.X][mousePos.Y] == '@')
			{
				screen[mousePos.X][mousePos.Y] = '#';
			}
			// �̹� ����� �������� ���
			if (screen[mousePos.X][mousePos.Y] == '#')
			{
				screen[mousePos.X][mousePos.Y] = '@';
			}
		}

	}
};

