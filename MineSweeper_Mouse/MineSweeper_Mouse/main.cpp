// �ʿ��� ���
// 2. Ŭ���ϸ� ������ ���ڰ� ���̰� �ϱ�
// 7. ���ڸ� ������ �������� �� ������ ��� ����
//

#include <iostream>
#include "GameManager.h"
#include "GameObject.h"
#include "InputManager.h"


using namespace std;

int main()
{
	
	GameManager gameManager;
	GameObject object;
	InputManager input;

	gameManager.initialization(); // screen�� '@'�� �ʱ�ȭ
	gameManager.setMineRandomly(); // mine���� ��ġ
	
	while (1)
	{
		input.readEveryFrame();
		gameManager.getScreen(); // 10x10 ȭ�� ���
		object.update();
	}

	return 0;


}