#include <iostream>
#include <windows.h> //윈도우제공함수
#include <conio.h> //C언어제공함수 C++ 헤더파일

#define UP 0x48
#define LEFT 0x4B
#define RIGHT 0x4D
#define DOWN 0x50
#define SPACE 0x20

using namespace std;

void GotoXY(int X, int Y)
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur); //window.h 제공 함수
}

//custom 자료형
struct PlayerInfo
{
	int X;
	int Y;
	string Shape;
};

int main()
{
	//플레이어 초기화
	PlayerInfo* PlayerData;
	PlayerData = new PlayerInfo;

	PlayerData->X = 5; //Playerdata[0] 이 생략된거임.
	PlayerData->Y = 5;
	PlayerData->Shape = "P";

	while (true)
	{
		//Input();
		//if (kbhit()) //!kbhit 하면 거짓일 때
		{
			int Key = _getch(); //읽은 문자 반환
			if (Key == 0x48 || toupper(Key) == 'W')
			{
				PlayerData->Y--;
			}
			else if (Key == 0x4B || toupper(Key) == 'A')
			{
				PlayerData->X--;
			}
			else if (Key == 0x4D || toupper(Key) == 'D')
			{
				PlayerData->X++;

			}
			else if (Key == 0x50 || toupper(Key) == 'S')
			{
				PlayerData->Y++;
			}
			else if (Key == 27)
			{
				break;
			}
		}
		//더블 버퍼링
		system("cls");
		GotoXY(PlayerData->X, PlayerData->Y);
		cout << PlayerData->Shape << endl;

	}
	
	delete PlayerData;
	PlayerData = nullptr;

	return 0;
}