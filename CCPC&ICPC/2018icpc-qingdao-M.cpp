#include <bits/stdc++.h>
using namespace std;

int solve(int x,int k)
{
//    printf("std %d %d\n",x,k);
    if(k==0)return x;
    if(x<10){
        if(k==1){
            if(x==8)return 2;
            if(x==0||x==4||x==6||x==9)return 1;
            return 0;
        }
        if(k&1){
            if(x==8)return 1;
            if(x==0||x==4||x==6||x==9)return 1;
            return 0;
        }
        else {
            if(x==8)return 0;
            if(x==0||x==4||x==6||x==9)return 0;
            return 1;
        }
    }
    int res=0;
    while(x){
        int as=x%10;
        if(as==8)res+=2;
        if(as==0||as==4||as==6||as==9)res++;
        x/=10;
    }
//    printf("test %d %d\n",res,k);
    return solve(res,k-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int a,k;
        scanf("%d%d",&a,&k);
        int ans=solve(a,k);
        printf("%d\n",ans);
    }
    return 0;
}
/*
6
123456789 1
888888888 1
888888888 2
888888888 999999999
98640 12345
1000000000 0


1
888888888 2

*/