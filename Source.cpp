#include <iostream>
#include <windows.h> //�����������Լ�
#include <conio.h> //C��������Լ� C++ �������

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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur); //window.h ���� �Լ�
}

//custom �ڷ���
struct PlayerInfo
{
	int X;
	int Y;
	string Shape;
};

int main()
{
	//�÷��̾� �ʱ�ȭ
	PlayerInfo* PlayerData;
	PlayerData = new PlayerInfo;

	PlayerData->X = 5; //Playerdata[0] �� �����Ȱ���.
	PlayerData->Y = 5;
	PlayerData->Shape = "P";

	while (true)
	{
		//Input();
		//if (kbhit()) //!kbhit �ϸ� ������ ��
		{
			int Key = _getch(); //���� ���� ��ȯ
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
		//���� ���۸�
		system("cls");
		GotoXY(PlayerData->X, PlayerData->Y);
		cout << PlayerData->Shape << endl;

	}
	
	delete PlayerData;
	PlayerData = nullptr;

	return 0;
}