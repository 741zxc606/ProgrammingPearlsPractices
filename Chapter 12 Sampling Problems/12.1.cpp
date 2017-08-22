/*
 * Programming Pearls Chapter 12 Sampling Problems
 * Problem:How to generate m random integers (not repetitive) within 0 ~ n-1
 * Requirements: Output in sequence, and ensure that each subset is selected for the same probability.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandNum(int m, int n)//select m subsets in 0~n-1
{
	srand(time(NULL));//

	int i, j;
	for (i = 0; i < n; i++)
	{
		if (rand() % (n - i) < m)
		{
			printf("%d ",i);
			m--;
		}
	}
}

int main()
{
	getRandNum(6, 12);
	return 0;
}
