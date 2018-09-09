#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head


const int N = 1e6+7;
int T,n,m,k,Cas;
ll s1,s2,num2;

int main()
{
    for(read(T);T;T--){
        printf("Case %d: ",++Cas);
        s1=s2=num2=0;
        read(n);
        rep(i,1,n+1){
            read(m);
            if(m>0) s1 += m;
            else s2 += abs(m),num2++;
        }
        if((ll)n-num2 <= 0)printf("inf\n");
        else printf("%lld/%lld\n",(s1+s2)/gcd(s1+s2,(ll)n-num2), ((ll)n-num2)/gcd(s1+s2,(ll)n-num2));
    }

    return 0;
}
/*
3
1
1
2
-10 -3
3
3 -6 -9

*/
