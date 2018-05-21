#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	/* 
	(1) 判断int型变量a是奇数还是偶数           
       a&1   = 0 偶数
       a&1 =   1 奇数
	(2) 取int型变量a的第k位 (k=0,1,2……sizeof(int))，即a>>k&1
	(3) 将int型变量a的第k位清0，即a=a&~(1<<k)
	(4) 将int型变量a的第k位置1，即a=a|(1<<k)
	(5) int型变量循环左移k次，即a=a<<k|a>>16-k   (设sizeof(int)=16)
	(6) int型变量a循环右移k次，即a=a>>k|a<<16-k   (设sizeof(int)=16)
	(7)整数的平均值
	对于两个整数x,y，如果用 (x+y)/2 求平均值，会产生溢出，因为 x+y 可能会大于INT_MAX，但是我们知道它们的平均值是肯定不会溢出的，我们用如下算法：
	int average(int x, int y)   //返回X,Y 的平均值
	{   
	     return (x&y)+((x^y)>>1);
	}
	(8)判断一个整数是不是2的幂,对于一个数 x >= 0，判断他是不是2的幂
	boolean power2(int x)
	{
	    return ((x&(x-1))==0)&&(x!=0)；
	}
	(9)不用temp交换两个整数
	void swap(int x , int y)
	{
	    x ^= y;
	    y ^= x;
	    x ^= y;
	}
	(10)计算绝对值
	int abs( int x )
	{
		int y ;
		y = x >> 31 ;
		return (x^y)-y ;        //or: (x+y)^y
	}
	(11)取模运算转化成位运算 (在不产生溢出的情况下)
	         a % (2^n) 等价于 a & (2^n - 1)
	(12)乘法运算转化成位运算 (在不产生溢出的情况下)
	         a * (2^n) 等价于 a<< n
	(13)除法运算转化成位运算 (在不产生溢出的情况下)
	         a / (2^n) 等价于 a>> n
	        例: 12/8 == 12>>3
	(14) a % 2 等价于 a & 1       
	(15) if (x == a) x= b;
		 else x= a;
		 等价于 x= a ^ b ^ x;
	(16) x 的 相反数 表示为 (~x+1)
	 */
	return 0;
}