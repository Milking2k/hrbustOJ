//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m;
int emt[100007];
int main()
{
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&emt[i]);
    }
    sort(emt+1,emt+1+n);
    long long x,y;
    for(int i=n-1;i>=1;i--){
//        printf("emt: %d\n",emt[i]);
        if(emt[i]==emt[i+1]){
            x=0ll+emt[i];
            for(int j=i-2;j>=1;j--){
                if(emt[j]==emt[j+1]){
                    y=0ll+emt[j];
                    return !printf("%lld\n",1ll*x*y);
                }
            }
        }
    }
    return !printf("0\n");
}
/*
6
1 1 2 2 3 4

6
1 1 1 1 1 1

6
1 1 2 3 4 4

6
1 2 3 4 5 6


*/
