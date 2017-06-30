/*
 * Select Sort
 */
#include <iostream>
#include <algorithm>
using namespace std;

void selectSort(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

int main()
{
	int a[10] = { 5,7,6,23,9,12,4,8,34,17 };
	selectSort(a, 9);
	for (int i = 0; i < 10; i++)
		printf("%d\n",a[i]);
	return 0;
}
