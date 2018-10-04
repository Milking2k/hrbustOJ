#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define x first
#define y second
#define mp(i,j) make_pair(i,j)
typedef long long ll;
typedef pair<ll, ll> PII;
ll n,m;
 
PII ans;
 
PII solve(ll pre, ll level, ll totRelese)
{
//    printf("%lld %lld %lld\n",pre, level, totRelese);
    if(level==2){
        PII tmp;
        if(totRelese==1)tmp.x=1,tmp.y=1;
        else if(totRelese==2)tmp.x=1,tmp.y=2;
        else if(totRelese==3)tmp.x=2,tmp.y=2;
        else tmp.x=2,tmp.y=1;
 
//        printf("pre:%lld res::%lld %lld\n",pre,tmp.x,tmp.y);
        return tmp;
    }
 
    ll block = ((level*level)>>2);
    block = totRelese/block - (totRelese%block?0:1);
    totRelese %= ((level*level)>>2);
    if(totRelese==0){totRelese = ((level*level)>>2);}
 
    PII tmp = solve(block, level>>1, totRelese);
 
//    printf("pre:%lld block:%lld\n",pre,block);
//    printf("tmp33:%lld %lld\n",tmp.x, tmp.y);
 
    if(block==1){
        tmp.y += level/2;
    }
    else if(block==2){
        tmp.x += level/2;
        tmp.y += level/2;
    }
    else if(block==3){
        int tmps = tmp.x;
        tmp.x = level/2+1-tmp.y;
        tmp.y = level/2+1-tmps;
        tmp.x += level/2;
    }
    else if(block==0){
        swap(tmp.x, tmp.y);
    }
 
//    printf("tmp:%lld %lld\n",tmp.x, tmp.y);
    return tmp;
}
 
int main()
{
    while(~scanf("%d%d",&n,&m)){
        ans = solve(0, n ,m);
        printf("%lld %lld\n",ans.x, ans.y);
    }
    return 0;
}