#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
using namespace std;
typedef long long ll;
const int EF = 0.0000001;

ll a,b,c,d;

ll cal(int a,int b,int d){
    ll res = b/d-(a-1)/d;
    return res;
}

int main()
{
    while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d))
    {
        ll A1 = cal(a,b,2);
        ll B1 = cal(a,b,1009);
        ll C1 = cal(a,b,2018);

        ll A2 = cal(c,d,2);
        ll B2 = cal(c,d,1009);
        ll C2 = cal(c,d,2018);

        ll ans1 = (B1-C1)*A2;
        ll ans2 = (d-c+1)*C1;
        ll ans3 = (B2-C2)*(A1-C1);
        ll ans4 = (b-a+1-B1)*C2;
        printf("%lld\n",ans1+ans2+ans3+ans4);
    }
    return 0;
}