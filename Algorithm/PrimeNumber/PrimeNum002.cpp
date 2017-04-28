#include <stdio.h>
#include <iostream>
#include <windows.h> 
#include <cmath>
using namespace std;

int root(int n)
{
	return(int) sqrt((float)n);
}

int prime(int n)
{
	int i,bound;
	if (n % 2 == 0)
		return 0;
	if (n % 3 == 0)
		return 0;
	if (n % 5 == 0)
		return 0;
	bound = root(n);
	for (i = 7; i <= bound; i=1+2)//
		if (n%i == 0)
			return 0;
	return 1;
}

int main()
{
	LARGE_INTEGER Freq;//
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	QueryPerformanceFrequency(&Freq);//
	QueryPerformanceCounter(&start);//

	int i, n;
	n = 1000;
	for (i = 2; i <= n; i++)
		if (prime(i))
			cout << i << " ";

	QueryPerformanceCounter(&end);
	printf("%dms", (end.QuadPart - start.QuadPart) * 1000 / Freq.QuadPart);
	return 0;
}
