#include <stdio.h>
#include <iostream>
#include <windows.h>   
using namespace std;

int prime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n%i == 0)
			return 0;
	return 1;
}

int main()
{
	LARGE_INTEGER Freq;//
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	QueryPerformanceFrequency(&Freq);//获取时钟周期  “1次/秒”，记做Hz（赫兹）。1Hz就是每秒一次
	QueryPerformanceCounter(&start);//获取时钟计数  

	int i,n;
	n = 1000;
	for (i = 2; i <= n; i++)
		if (prime(i))
			cout << i << " ";

	QueryPerformanceCounter(&end);
  /*此处*1000，以毫秒为单位；*1000000 以微秒为单位*/   
  /*由于执行时间极短（可能是几微秒），所以采用微秒为单位*/  
  /*  1s=10^3ms(毫秒)=10^6μs(微秒)=10^9ns(纳秒)  */   
	printf("%dms",(end.QuadPart-start.QuadPart)*1000/Freq.QuadPart);
	return 0;
}
