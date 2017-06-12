#include <stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define obs(a) a>0?a:-a

int Partition(int a[], int i, int j)
{
	int temp = a[i];
	while (i < j)
	{
		while (i < j&&temp < a[j])
			j--;
		a[i] = a[j];
		
		while (i < j&&temp >= a[i])
			i++;
		a[j] = a[i];
	}
	a[i] = temp;
	return i;
}

void Quicksort(int a[], int i, int j)
{
	int p;
	if (i < j)
	{
		p = Partition(a, i, j);
		Quicksort(a, i, p - 1);
		Quicksort(a,p + 1,j);
	}
}

int main()
{
	int a[6] = {3,4,-2,-9,10,8};
	int cumarr[6]; cumarr[-1] = 0;
	int i, j;
	int minsofar = 65535;

	for (i = 0; i < 6; ++i)
	{
		cumarr[i] = cumarr[i - 1] + a[i];
	}

	Quicksort(cumarr, 0, 4);

	for (i = 0; i < 5; ++i)
	{
		minsofar = min(minsofar,obs(cumarr[i+1]-cumarr[i]));
	}

	printf("min=%d\n",minsofar);
	return 0;
}
