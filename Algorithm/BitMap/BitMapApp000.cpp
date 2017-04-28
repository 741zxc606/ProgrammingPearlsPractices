/*Bit-Map Application
 *2.5亿个整数中找出不重复的整数的个数，内存空间不足以容纳这2.5亿个整数.
 *将bit-map扩展一下，用2bit表示一个数即可，0表示未出现，1表示出现一次，2表示出现2次及以上，
 *在遍历这些数的时候，如果对应位置的值是0，则将其置为1；如果是1，将其置为2；如果是2，则保持不变。
 *或者我们不用2bit来进行表示，我们用两个bit-map即可模拟实现这个2bit-map，都是一样的道理。
 */

#include <stdio.h>
#include <memory.h>

//用char数组存储2-Bitmap,不用考虑大小端内存的问题
unsigned char flags[1000];//数组大小自定义
unsigned get_val(int idx)
{
	//   |    8 bit  |
	//   |00 00 00 00| //映射3 2 1 0
	//   |00 00 00 00| //表示7 6 5 4
	//   ...
	//   |00 00 00 00|

	int i = idx / 4; //一个char表示4个数
	int j = idx % 4;
	unsigned ret = (flags[i]&(0x3<<(2*j)))>>(2*j);
	//0x3是0011 j的范围为0-3，因此0x3<<(2*j)范围为00000011到11000000 如idx=7 i=1 ,j=3 那么flags[1]&11000000, 得到的是|00 00 00 00|  
  //
	return ret;
}

unsigned set_val(int idx, unsigned int val)
{
	int i = idx / 4;
	int j = idx % 4;
	unsigned tmp = (flags[i] & ~((0x3 << (2 * j)) & 0xff)) | (((val%4)<<(2*j))&0xff);
	return 0;
}

unsigned add_one(int idx)
{
	if (get_val(idx) >= 2)
	{
		return 1;
	}
	else 
	{
		set_val(idx,get_val(idx)+1);
		return 0;
	}
}

//只测试非负数的情况;    
//假如考虑负数的话,需增加一个2-Bitmap数组.  
int a[] = { 1,3,5,7,9,1,3,5,7,1,3,5,1,3,1,10,2,4,6,8,0 };

int main()
{
	int i;
	memset(flags,0,sizeof(flags));

	printf_s("Primary Array:");
	for (i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf_s("%d ", a[i]);
		add_one(a[i]);
	}

	printf_s("\r\n");

	printf_s("NUm Appear Once:");
	for (i = 0; i < 100; i++)
	{
		if (get_val(i) == 1)
			printf_s("%d ",i);
	}
	printf_s("\r\n");

	return 0;
}
