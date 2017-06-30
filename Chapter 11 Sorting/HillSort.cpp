/*
 * Hill Sort
 */

#include <iostream>
#include "stdio.h"

void hillsort(int a[], int n)
{
	int k = n / 2;//
	while (k > 0)
	{
		for (int i = k; i < n; i++)//
		{
			int t = a[i];
			int j = i - k;//
			while (j > 0 && t < a[j])
			{
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = t;
		}
		k = k / 2;
	}
}

int main()
{
	int a[9] = {2,1,3,6,5,4,8,7};
	hillsort(a, 8);

	for (int i = 0; i < 8; i++)
		printf("%d\n",a[i]);
	return 0;
}
