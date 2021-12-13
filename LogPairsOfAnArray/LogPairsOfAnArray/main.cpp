#include <iostream>
#include <array>

using namespace std;

array <const int, 5> logMe{1, 2, 3, 4, 5};

int main()
{
	for (int i = 0; i <= 4; i++)
	{
		int firstNum = logMe[i]; //grab the number from the logMe array

		for (int i = 0; i <= 4; i++)
		{
			cout << firstNum << logMe[i] << endl; //print the number stored in firstNum with an element in the array
		}
	}

	return 0;
}