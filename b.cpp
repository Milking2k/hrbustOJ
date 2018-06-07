#include <iostream>
#include <cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long ll;

int T;
int a,b,k;
ll quickmod(int x, int n)
{
    ll res = 1;
    while(n>0)
    {
        if(n&1)
            res = (res*x);
        if(res>=k) return -1;
        if(x*x>=k) return -1;
        x = (x * x);
        n >>= 1;
    }
    return res;
}

ll calt(ll n)
{
    int cnt = ceil(log(n)/log(2));

    ll res1 = quickmod(n, a);
    ll res2 = quickmod(cnt,b);
    if(res1 < 0 || res2 < 0) return -1;

    return res1*res2;
}

ll solve(ll left, ll right)
{
    ll mid = (left+right)/2;

    printf("%lld %lld test\n", left, right);

    if(left == right+1 || left == right)
    {
        return right;
    }
    printf("calt1:%lld calt2:%lld\n", calt(left), calt(right));
    ll leftans = calt(left);
    ll rightans = calt(right);
    if(leftans <= 0) return solve(mid, right);
    else if(rightans <= 0) return solve(left, mid);

    else if(leftans < rightans)
        return solve(mid,right);
    else
        return solve(left, mid);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%lld",&a,&b,&k);
        printf("%lld\n",solve(2,k));
//        printf("%lld\n",quickmod(a,b));
    }
    return 0;
}
//<><<<<><<><<<><<>
//<><<<<><<><<<><<
//<><<<<><<><<<><<

