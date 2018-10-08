#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL gcd(LL x,LL y)
{
    return y==0?x:gcd(y,x%y);
}

LL a,b,c;
LL p1,p2,q1,q2;
LL d;

bool solve(LL tmp)
{
    double as=(c-a*tmp)*1.0/b*1.0;
    if(as==LL(as)){
      return true;
    }
    return false;
}
int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%lld%lld%lld%lld",&p1,&p2,&q1,&q2);
    d=gcd(a,b);
    if(c%d){
        puts("Kuon");
        return 0;
    }
    LL ans=1e18;

    double midcnt = (2*a*c*q2 + q1*a*b - p1*b*b)/(2*p2*b*b+2*q2*a*a);
    int T = 1e6;
    LL pos = (LL)floor(midcnt);
    LL tmp = pos;
    while(T--){
        tmp--;
        if(!solve(tmp))continue;
        LL xx=tmp,yy=(LL)(c-a*tmp)*1.0/b*1.0;
        LL as=p2*xx*xx+p1*xx+q2*yy*yy+q1*yy;
        ans = min(ans,as);
    }
    T=1e6;
    tmp=pos-1;
    while(T--){
        tmp++;
        if(!solve(tmp))continue;
        LL xx=tmp,yy=(LL)(c-a*tmp)*1.0/b*1.0;
        LL as=p2*xx*xx+p1*xx+q2*yy*yy+q1*yy;
        ans = min(ans,as);
    }
    printf("%lld\n",ans);
    return 0;
}
/*

2 5 10
1 1 1 1
*/
