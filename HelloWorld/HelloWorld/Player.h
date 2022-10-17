#pragma once
#include <conio.h>
#include "GameObject.h"

class Player :
    public GameObject
{

	void processInput()
	{
		int key;
		// int minor;

		if (!_kbhit()) return;

		Borland::GotoXY(0, 21);
		key = _getch();
				
		Borland::GotoXY(1, 23);
		printf("player key is %c   %x %d\n", key, key, key);

		Position pos = getPos();

		switch (key) {
		/*case 224:
			minor = _getch();
			printf("player minor key is %c   %x %d\n", minor, minor, minor);
			switch (minor) {
			case 'K':
				pos.x--;
				break;
			case 'M':
				pos.x++;
				break;
			case 'P':
				pos.y++;
				break;
			case 'H':
				pos.y--;
				break;
			}
			break;*/
		case 'w':
			pos.y--;
			break;
		case 'a':
			pos.x--;
			break;
		case 's':
			pos.y++;
			break;
		case 'd':
			pos.x++;
			break;
		case 'f':
			/* 
			if(player.getPos() == '#')
			{ 
			// 이미 깃발이 표시되어있다면
			flag --;  깃발 갯수 -1
			mine ++; 남은 지뢰 갯수 +1
			}
			else // 깃발이 표시가 안되어 있다면
			player.getPos() 에 "#" 표시
			flag ++;
			mine --;
			*/
			break;
		case 'r':
			/* 
			클릭 후 주위 탐색 함수
			if(player.getPos() == enemy.getPos() || '*')
			{ // 지뢰를 클릭할 경우 게임 종료
			Borland::GotoXY(1, 15);
			cout << "GAME OVER" << endl;
			exit(0);
			}
			else
			{ // 지뢰가 아닌경우
			주위의 지뢰 갯수를 노출
			재귀함수
			}
			*/
			break;
		case 'q':
			exit(0);
			break;
		}
		setPos(pos);
	}

public:
    Player(int x, int y, Screen& screen) : GameObject('>', x, y, screen) {}


	void update() override
	{
		processInput();
	}

	
};

