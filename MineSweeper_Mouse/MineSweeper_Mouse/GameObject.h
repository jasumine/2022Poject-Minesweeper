#pragma once
#include <iostream>
#include "InputManager.h"

using namespace std;

class GameObject
{
	InputManager input;
	MOUSE_EVENT_RECORD mer;


public:
	GameObject() {}
	virtual ~GameObject() {}

	void update()
	{
		// mer ������ �Է� �ޱ����� gameObject ���
		input.mouseEvent(mer);
	}

};

