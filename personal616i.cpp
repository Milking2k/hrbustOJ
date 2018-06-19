//#include <bits/stdc++.h>
#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    for(int i=10000;i<=99999;i++)
    {
        int y = i%100;
        int x = ((i/1000)%10)*((i/10000)%10);
        if(x==y)
            printf("%d\n",i);
    }
    return 0;
}
