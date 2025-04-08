#include <iostream>
#include <algorithm>
#include <string>

#define LOTTO_NUMBER	45

using namespace std;

int main()
{
	//init
	srand((unsigned int)time(NULL));
	int LOTTO[LOTTO_NUMBER] = { 0, };
	for (int Index = 0; Index < LOTTO_NUMBER; Index++)
	{
		LOTTO[Index] = Index + 1;
	}

	//shuffle
	int Temp = 0;
	for (int Count = 0; Count < LOTTO_NUMBER * 100; Count++)
	{
		int First = rand() % LOTTO_NUMBER;
		int Second = rand() % LOTTO_NUMBER;
		Temp = LOTTO[First];
		LOTTO[First] = LOTTO[Second];
		LOTTO[Second] = Temp;
	}

	//print
	cout << "Lotto Number : ";

	for (int Index = 0; Index < 6; Index++)
	{
		cout << LOTTO[Index] << ", ";
	}

	cout << "\n *^^*";

	return 0;
}

