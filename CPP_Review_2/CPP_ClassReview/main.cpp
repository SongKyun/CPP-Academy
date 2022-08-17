#include <iostream>

#define Log(x) std::cout << x << std::endl

// 플레이어
//클래스 -> 새로운 타입(유형). = int, float ... 같은 타입

class Player
{

public: //가시성(Visibility)
	//private:
	//접근 제한자(한정자).
	int x;
	int y;
	int speed;

	//생성자 Constructor 함수
	//클래스 이름과 동일함
	//반환형이 없음
	//객체(물체)가 생성될 때 한번 실행(호출)됨
	Player()
	{
		x = 0;
		y = 0;
		speed = 0;
		std::cout << "첫번째 생성자 호출됨\n";
	}

	// 생성자 오버로딩 ( 이름은 같은데 파라미터나 그런게 다른)
	Player(int x, int y)
	{
		this->x = x;
		this->y = y;
		speed = 0;
		std::cout << "두번째 생성자 호출됨\n";
	}

	void Initialize() // 초기화
	{
		x = 0;
		y = 0;
		speed = 0;
	}

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}

};

int main()
{
	// Player
	// 클래스 타입의 변수를 생성하는 과정 -> 객체를 생성한다(만든다)
	Player player1(10, 10);
	player1.x += 2;
	player1.Print();
	/*player1.Initialize();
	player1.Print();*/
	/*player1.x = 0;
	player1.y = 0;
	player1.x += 2;*/

	Player player2(2, 2);
	/*player2.Initialize();*/

	//동적(Runtime - 실행 중에) 할당
	//힙(Heap)에 저장 공간을 확보하겠다
	//힙 : 공간이 크다, 속도가 상대적으로 느리다
	//우리가 원하는 만큼 확보 가능하다
	//다 쓴 공간을 우리가 해제해야 한다
	Player* player3 = new Player(0, 0); // new 동적할당 키워드
	// (*player3).x += 2;
	player3->x += 2;
	(*player3).Print();

	delete player3; // new 와 delete 짝꿍

	std::cin.get();
}