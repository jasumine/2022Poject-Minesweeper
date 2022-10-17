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


void initialize()
{
	
}

int main()
{
	Screen screen(11, 11);
	Player player{ 0, 0, screen };
	Enemy* enemy[10];
	for (int i = 0; i < 10; i++)
	{
		enemy[i] = new Enemy (i, i, screen);
	}

	/* enemy 10°³ ·£´ý »ý¼º
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
		player.update();
	}
	
	return 0;
}