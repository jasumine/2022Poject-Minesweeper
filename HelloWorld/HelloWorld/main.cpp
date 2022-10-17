#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;


void initialization()
{
	
}

int main()
{
	GameObject gameObject;
	Screen screen(11, 11);
	Player player{ 0, 0, screen };
	Enemy* enemy[10];

	char screenPos[10][10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = new Enemy (i, i, screen);
		screenPos[i][i] = '*';
	}

	/* enemy 10개 랜덤 생성
	Enemy* enemy[10];
	srand(time(NULL));
	int enemyNumber = 10;
	int count = 0;
	while (enemyNumber > count)
	{
		int x = rand() % 9;
		int y = rand() % 9;
		if (enemy[count] !=new Enemy(x,y,screen))
			{
				enemy[count] = new Enemy(x, y, screen);
			}
	}
	*/

	while (1)
	{
		screen.clear();

		screen.draw(player.getPos(), player.getShape());
		for (int i = 0; i < 10; i++)
		{
			screen.draw(enemy[i]->getPos(), enemy[i]->getShape());
		}
		screen.render();
		player.update(); // player 움직임 함수

		Borland::GotoXY(1, 18);
		cout << "현재 남은 지뢰의 갯수 : " << gameObject.mine << endl;
	
	return 0;
}