#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn=1e5+6;
int gcd(int a,int b)  {
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main() {
    int T;
    int Cas=1;
    read(T);
    while(T--) {
        int a,b,n;
        read(n);
        read(a);
        read(b);
        int t=gcd(a,b);
        int m=n/t;
        m-=2;
        if(m%2==0) {
            printf("Case #%d: Iaka\n",Cas++);
        }
        else{
            printf("Case #%d: Yuwgna\n",Cas++);
        }
    }
}
