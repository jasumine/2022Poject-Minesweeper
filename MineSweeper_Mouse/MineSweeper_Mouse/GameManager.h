// ==============================================
// GameManager.h
// 화면에 보여지는 기능 
// ==============================================
#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

class GameManager
{
protected:
	char screen[10][10]; // 보여지는 화면
	char enemy[10][10]; // 지뢰의 위치 저장

public:
	GameManager() {}
	virtual ~GameManager() {}

	// screen을 '@'로 초기화
	void initialization()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				 screen[i][j] = '@';
				 enemy[i][j] = '@';
			}
		}
	}

	void setMineRandomly() // 지뢰 랜덤 배치
	{
		int mine = 10;
		int count = 0;
		int x, y;
		srand((unsigned)time(NULL));
		while (mine > count)
		{
			x = rand() % 10;
			y = rand() % 10;
			if(enemy[x][y] != '*')
			enemy[x][y] = '*';
			count++;
		}
	}

	void getScreen()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << screen[i][j];
			}
			cout << "\0" << endl;
		}
	}


	
};

