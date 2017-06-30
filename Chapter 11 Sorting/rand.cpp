#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));//

	for (int i = 0; i != 50; ++i)
	{
		cout << rand() % 40 + 60 << endl;
	}
}
