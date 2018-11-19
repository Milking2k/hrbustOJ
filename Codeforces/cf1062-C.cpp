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
int a[N],pre[N];
char ch[N];
void solve(ll l, ll r){
    ll ans = 0;
    ll pr = pre[r] - pre[l - 1];
    ans = (powmod(2, pr, mod) - 1) % mod;
    if(pr==0)ans=0;

    pr =  r - l + 1ll - pr;
    ans = (ans * powmod(2, pr, mod)) % mod;
    cout << ans << endl;
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> ch;
    int len = strlen(ch);
    rep(i,0,len){
        if(ch[i]=='0')
            a[i+1] = 0;
        else
            a[i+1] = 1; 
        pre[i + 1] = a[i + 1] + pre[i];
    }
    rep(i,1,m+1){
        ll l, r;
        cin >> l >> r;
        // printf("debug:%d %d %d\n", l, r, pre[r] - pre[l-1]);
        solve(l, r);
    }
    return 0;
}
// 1 3 7 15 31

/*

1.1.1.1
..2.2.2
....4.4
......8


0.1
1..
... = 2

0.1.1
1...2 = 1
3.... = 3
..... = 6

0.1.1
1...2 = 1
....3 = 2
..... = 5


0.0.1.1
1.1.2.. = 1
3.3.... = 3
6...... = 6
....... = 12


*/