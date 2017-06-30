/*
 * Sentinel Quick Sort
 */

#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int a[], int l, int u)
{
	if (l >= u)
		return;
	int m = u + 1;//
	int i = u + 1;
	do
	{
		while (a[--i] < a[l]);//

		swap(a[--m], a[i]);//
	} while (i != l);

	quickSort(a, l, m - 1);
	quickSort(a, m + 1, u);
}

int main()
{
	int a[10] = { 5,7,6,23,9,12,4,8,34,17 };
	quickSort(a, 0, 9);
	for (int i = 0; i < 10; i++)
		printf("%d\n", a[i]);
	return 0;
}
