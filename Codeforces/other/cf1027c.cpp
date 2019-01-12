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
int T,n,m;
int v[10007],a[N];
int main()
{
    for(read(T);T;T--){
        read(n);
        memset(v,0,sizeof(v));
        rep(i,1,n+1) read(a[i]),v[a[i]]++;

        sort(a+1,a+1+n);
        int flag = -1;
        ll ans1=1e8,ans2=1;
        int c=0,d=0;
        rep(i,1,n+1){
            if(i>1 && a[i] == a[i-1]) continue;
            int cnt = a[i];
            if(v[cnt] >= 4){
                ll t1 = (ll)(2*cnt)*(2*cnt);
                ll t2 = (ll)(cnt*cnt);
                if(ans1*t2 > ans2*t1) {
                    ans1 = t1,ans2 = t2;
                    c = d = cnt;
                }
            }
            else if(v[cnt] >= 2 && flag != -1){
                ll t1 = (ll)(flag+cnt)*(flag+cnt);
                ll t2 = (ll)(flag*cnt);
                if(ans1*t2 > ans2*t1){
                    ans1 = t1,ans2 = t2;
                    c=flag,d=cnt;
                }
            }

            if(v[cnt] >= 2)flag = cnt;
        }
        printf("%d %d %d %d\n",c,c,d,d);
    }
    return 0;
}
