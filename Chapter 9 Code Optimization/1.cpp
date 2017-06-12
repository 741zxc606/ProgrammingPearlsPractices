#include <stdio.h>
#include <windows.h>
int main()
{
	int i;
	int t = 500;

	int a[1000];
	for (i = 0; i < 1000; ++i)
		a[i] = i;

	a[1000] = 50;//the guard
	i = 512;
	int l = -1;
	if (a[511] < t)
		l = 1000 - 512;
	while (i != 1)
	{
		i = i / 2;
		if (a[l + i] < t)
			l = l + i;
	}

	int p = l + 1;
	if (p > 1000 || a[p] != t)
	{
		p = -1;
		printf("false\n");
	}
	else
	{
		printf("Position is:%d\n",p);
		printf("true\n");
	}
}
