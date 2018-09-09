#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int MOD=998244353;
LL qmod(LL a, LL b)
{
    if (b == 0) return 1;
    LL r = a % MOD;
    LL k = 1;
    while (b > 1){
        if ((b & 1)!=0)
            k = (k * r) % MOD;
        r = (r * r) % MOD;
        b >>= 1;
    }
    return (r * k) % MOD;
}
LL gcd(LL a,LL b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main() {
    int T;
    read(T);
    while(T--) {
        LL a,b,c,a1,b1,c1;
        cin>>a>>b>>c>>a1>>b1>>c1;
        LL fm=a+b+c;
        LL fz=b1*a-b1*c+c1*b-c1*a+a1*c-a1*b;
        LL m=gcd(fm,abs(fz));
        if(fm/m==0 || fz/m==0) {
            cout<<0<<endl;
            continue;
        }
        if(fz<0)cout<<"-";
        fz=abs(fz);

        if(fm/m==1) {
            cout<<fz/m*(fm/m)<<endl;
            continue;
        }


        cout<<fz/m<<"/"<<fm/m<<endl;
        //cout<<200*123-200*789+456*1068-123*1068+789*100-456*100<<endl;
    }
}