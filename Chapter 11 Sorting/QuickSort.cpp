#include <stdio.h>

void Partition(int a[], int left, int right)
{
	int i = left, j = right;
	int temp = a[i];//

	if (left >= right)//
		return;

	while (i < j)
	{
		while (i < j&&temp < a[j])//start from right
			j--;
				a[i] = a[j];//
				while (i < j&&temp >= a[i])//
					i++;
				a[j] = a[i];
	}
	a[i] = temp;//

	Partition(a, left, j - 1);
	Partition(a, j + 1, right);
}

int main()
{
	int a[10] = { 3,4,2,1,6,5,7,8 };
	Partition(a,0,7);
	for (int i = 0; i < 8; i++)
		printf("%d\n",a[i]);
	return 0;
}
