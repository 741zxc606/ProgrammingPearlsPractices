#include <iostream>
#include <algorithm>
using namespace std;

void QuickSort(int a[], int l, int u)
{
	if (l >= u)
		return;
	swap(a[l], a[rand() % (u - l) + l]);

	int t = a[l];//
	int i = l;
	int j = u + 1;
	for (;;)
	{
		do i++; while (i <= u&&a[i] < t);
		do j--; while (a[j] > t);
		if (i > j)
			break;
		swap(a[i], a[j]);
	}
	swap(a[i],a[j]);
	QuickSort(a, l, j - 1);
	QuickSort(a, j+1, u);
}
int main()
{
	int a[10] = {3,4,2,1,6,5,7,8};
	QuickSort(a, 0, 7);
	for (int i = 0; i < 8; i++)
		printf("%d\n",a[i]);
	return 0;
}
