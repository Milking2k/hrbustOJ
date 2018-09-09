#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL sum;
void solve(int x)
{
    if(x==2){
        sum+=1;
        return ;
    }
    if(x==3){
        sum+=7;
        return ;
    }
    if(x==4){
        sum+=4;
        return ;
    }
    if(x==5){
        sum+=8;
        return ;
    }
    if(x==6){
        sum+=14;
        return ;
    }
    else {
        int as=x/3-1;
        sum+=as*7;
        x-=as*3;
//        printf("test %d %d\n",x,as);
        solve(x);
    }
}
int main()
{
    scanf("%d",&n);
    sum=0;
    solve(n);
    printf("%lld\n",sum);
    return 0;
}