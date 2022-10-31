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
		// mer 변수를 입력 받기위해 gameObject 사용
		input.mouseEvent(mer);
	}

};

