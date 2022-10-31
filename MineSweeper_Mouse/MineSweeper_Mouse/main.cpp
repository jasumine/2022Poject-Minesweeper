// 필요한 기능
// 2. 클릭하면 주위에 숫자가 보이게 하기
// 7. 지뢰를 제외한 나머지를 다 열었을 경우 성공
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

	gameManager.initialization(); // screen을 '@'로 초기화
	gameManager.setMineRandomly(); // mine랜덤 배치
	
	while (1)
	{
		input.readEveryFrame();
		gameManager.getScreen(); // 10x10 화면 출력
		object.update();
	}

	return 0;


}