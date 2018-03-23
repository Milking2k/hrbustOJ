// 比例简化
// 现给出支持人数A，反对人数B，以及一个上限L，
// 请你将A比B化简为A’比B’，要求在A’和B’均不大于L且A’和B’互质
// （两个整数的最大公约数是1）的前提下，A’/B’≥A/B且A’/B’-A/B的值尽可能小。

// 直接暴力了L范围内所有互质的数的组合
// 在进行一个一个比较，取得最接近的那个数

#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main(int argc, char const *argv[])
{
    double a,b,l;
    cin >> a >> b >> l;
    double max=0x3f3f3f3f;
    double cnt;
    double ansa,ansb;// 存最后的结果
    for(double i = 1;i <= l; ++i)
    {
        for(double j = 1;j <= l; ++j)
        {
            cnt = i/j-a/b;// 这里是判断是否最接近的
            // printf("gcd:%d\n", gcd(i,j));
            if( cnt >= 0 && cnt < max && gcd(i,j) == 1)
            {
                ansa=i;
                ansb=j;
                max=cnt;
            }
            // printf("ansa:%d  ansb:%d  max:%d\n", ansa,ansb,max);
        }
    }
    printf("%.0f %.0f\n", ansa,ansb);
    return 0;
}