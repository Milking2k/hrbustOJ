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

const int N = 1e5+7;
int T,n,m;
int sum[N],cnt[N];
map<int,int> s;

int main()
{
    for(read(T);T;T--){
        read(n),read(m);
        s.clear();
        int ans = -1,u;
        rep(i,1,n+1){
            read(u);
            s[u]++;
            sum[i]=0,cnt[i]=0;
        }
        for(auto &v : s){
            sum[v.se] += v.se;
            cnt[v.se]++;
        }

        per(i,1,n){
            sum[i] += sum[i+1];
            cnt[i] += cnt[i+1];
        }
        for(auto &v:s){
            int tot = sum[v.se] - (v.se-1)*cnt[v.se] - 1;
            if(tot <= m){
                ans = max(ans, v.fi);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
