#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    __int64 a[26],num[3],t = 16;
    int i,n,m;
    a[3] = 104;
    for(int i = 4;i < 26; i++)
    {
        num[1] = a[i-1];
        num[2] = a[i-1]-t;
        num[1] += 9*((__int64)pow(2,i-1)-2);
        num[2] += 4*((__int64)pow(2,i-2)-1)+6*((__int64)pow(2,i-1)-2);
        a[i] = 4*num[1] + 2*num[2];
        t  =  num[2];
    }
    for(int i = 3;i<26;i++)
    {   
        printf("N=%d: %I64d\n",i,a[i]);
    }
  
return 0;
}   