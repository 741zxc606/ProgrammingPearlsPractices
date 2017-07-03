/*
 * Find the kth largest element in a linear time
 */
#include <iostream>
using namespace std;

inline void Swap(int a[], int i, int j)//
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int Partition(int a[], int p, int r)//
{
	int privot = a[r];
	int low = p - 1;
	int i;
	for (i = p; i < r; i++)
	{
		if (a[i] <= privot)
			Swap(a,++low,i);
	}
	Swap(a,++low,r);
	return low;
}

int RandomPartition(int a[], int p, int r)
{
	int i = p + rand() % (r - p + 1);//
	Swap(a, i, r);
	return Partition(a, p, r);//
}

int SelectKMin(int a[], int p, int r, int k)
{
	if (p == r)
		return a[p];
	int q = RandomPartition(a, p, r);
	int count = q - p + 1;//
	if (k == count)
		return a[q];
	else if (k < count)
		return SelectKMin(a, p, q - 1, k);
	else
		return SelectKMin(a,q+1,r,k-count);
}

int main()
{
	int a[] = { 2,3,4,1,5,10,9,7,8,6 };
	int k = 3;
	cout << SelectKMin(a, 0, 9, k) << endl;

	return 0;
}
