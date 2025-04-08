#include <iostream>
#include <algorithm>
#include <string>

#define LOTO_NUMBER	45

using namespace std;

int main()
{
	//init
	srand((unsigned int)time(NULL));
	int LOTO[LOTO_NUMBER] = { 0, };
	for (int Index = 0; Index < LOTO_NUMBER; Index++)
	{
		LOTO[Index] = Index + 1;
	}

	//shuffle
	int Temp = 0;
	for (int Count = 0; Count < LOTO_NUMBER * 100; Count++)
	{
		int First = rand() % LOTO_NUMBER;
		int Second = rand() % LOTO_NUMBER;
		Temp = LOTO[First];
		LOTO[First] = LOTO[Second];
		LOTO[Second] = Temp;
	}

	//print
	cout << "Loto Number : ";

	for (int Index = 0; Index < 6; Index++)
	{
		cout << LOTO[Index] << ", ";
	}

	return 0;
}

