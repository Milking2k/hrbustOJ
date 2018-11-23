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
ll T,n,m;

priority_queue<ll, vector<ll>, greater<ll> > q;
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    ll ans = 0;
    bool flag = true;
    rep(i,1,m+1){
        ll x;
        cin >> x;
        ans += x;
        q.push(x);
        if(ans>1e18 || ans<0){
            flag = false;
        }
    }
    if(ans!=n) flag = false;

    while(q.size()!=1 && flag){
        ll cur1 = q.top();
        q.pop();
        ll cur2 = q.top();
        q.pop();
        if(abs(cur1-cur2)<=1){
            q.push(cur1 + cur2);
        }
        else {
            flag = false;
        }
    }

    puts(flag ? "misaka" : "ham");

    return 0;
}