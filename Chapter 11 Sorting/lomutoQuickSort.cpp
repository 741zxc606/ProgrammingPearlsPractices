/*
 * Lomuto QuickSort
 */

#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int a[], int l, int u)
{
	if (l > u)
		return;
	int m = l;//

	for (int i = l + 1; i < u; ++i)
	{
		if (a[i] < a[l])
			swap(a[++m], a[i]);
	}
	swap(a[l], a[m]);
	quickSort(a, l, m - 1);
	quickSort(a, m + 1, u);
}

int main()
{
	int a[10] = {3,4,2,1,6,5,7,8};
	quickSort(a,0,7);
	for (int i = 0; i < 8; i++)
		printf("%d\n",a[i]);
	return 0;
}
