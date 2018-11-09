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
const int N = 2e5+7;
int T,n,m;
ll a[N],sum[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    scanf("%d", &n);
    rep(i,1,n+1){
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }

    ll p[5] = {0, 0, 0, 0, 0}, minAns = 0x7fffffff;
    int l = 1, r = 3;
    rep(i,2,n-1){
        while (l < i && abs(sum[l] - sum[0] - (sum[i] - sum[l])) >= abs(sum[l + 1] - sum[0] - (sum[i] - sum[l + 1])))
            l++;
        while (r < n && abs(sum[r] - sum[i] - (sum[n] - sum[r])) >= abs(sum[r + 1] - sum[i] - (sum[n] - sum[r + 1])))
            r++;

        ll cnt = 0,cnt2=0x7fffffff;
        p[1] = sum[l] - sum[0];
        p[2] = sum[i] - sum[l];
        p[3] = sum[r] - sum[i];
        p[4] = sum[n] - sum[r];
        // minAns = min(minAns, cnt - cnt2);
        minAns = min(   minAns,max(p[1], max(p[2], max(p[3], p[4]))) - min(p[1], min(p[2], min(p[3], p[4])))  );
    }
    printf("%lld\n", minAns);
    return 0;
}