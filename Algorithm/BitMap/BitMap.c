/*Bit-Map 的具体实现
 *来自于《编程珠玑》
 *所谓的Bit-map就是用一个bit位来标记某个元素对应的Value， 而Key即是该元素。
 *由于采用了Bit为单位来存储数据，因此在存储空间方面，可以大大节省。
 */
#include <stdio.h>
#define BITSERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
#define EOF (-1)

int a[1 + N / BITSERWORD];//申请内存的大小

//设置所在的bit位为1
void set(int i) 
{
	a[i >> SHIFT] |= (1<<(i & MASK));
}

//初始化所有的bit位为0
void clr(int i)
{
	a[i >> SHIFT] &= ~(1 << (i & MASK));
}

//test测试所在的bit位是否为1
int test(int i)
{
	return a[i >> SHIFT] & (1<<(i & MASK));
}

int main()
{
	int i;
	for (i = 0; i < N; i++)
		clr(i);
	while (scanf_s("%d", &i) != EOF)
		set(i);
	for (i = 0; i < N; i++)
		if (test(i))
			printf_s("%d\n",i);
	return 0;
}

