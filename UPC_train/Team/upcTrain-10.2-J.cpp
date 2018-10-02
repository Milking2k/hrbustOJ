#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=500000;
int ch[N][2],sz,val[N],num[N];
int T,n,s[1050],i,j,ans;

void Insert(int x)
{
    int u = 0, c = 0, i;
    for (i = 31; i >= 0; i--)
    {
        c = (x >> i) & 1;
        if (!ch[u][c])
            ch[u][c] = sz++;
        u = ch[u][c];
        val[u]++;
    }
    num[u] = x;
}
void Delete(int x)
{
    int u = 0, c, i;
    for (i = 31; i >= 0; i--)
    {
        c = (x >> i) & 1;
        u = ch[u][c];
        val[u]--;
    }
}
int Query(int x)
{
    int u = 0, c, i;
    for (i = 31; i >= 0; i--)
    {
        c = (x >> i) & 1;
        if (ch[u][!c] && val[ch[u][!c]])
            u = ch[u][!c];
        else
            u = ch[u][c];
    }
    return x ^ num[u];
}
int main()
{
    for (scanf("%d", &T); T;T--)
    {
        sz = 1;
        memset(val, 0, sizeof(val));
        memset(ch, 0, sizeof(ch));

        scanf("%d", &n);
        rep(i,0,n){
            scanf("%d", s[i]);
            Insert(s[i]);
        }
        ans = -1;
        rep(i,0,n){
            Delete(s[i]);
            rep(j,i+1,n){
                Delete(s[j]);
                ans = max(ans, Query(s[i] + s[j]));
                Insert(s[j]);
            }
            Insert(s[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
