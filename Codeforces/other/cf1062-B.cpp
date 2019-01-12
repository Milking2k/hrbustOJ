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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e5+7;
int T,n,m;

void divide(int n) {
    if(n==1)
    {
        puts("1 0");
        return;
    }
    m = 0;
    ll ans = 1;
    ll cnt = 0;
    ll cnt2 = 0;
    bool flag = 0;
    for (int i = 2; i * i <= n;i++){
        if(n%i==0){
            ans *= i, cnt2 = 0;
            while (n % i == 0)
                n /= i, cnt2++;
            if(cnt!=0 && cnt!=cnt2)
                flag = 1;
            cnt = cnt > cnt2 ? cnt : cnt2;
        }
    }

    if (n > 1){
        ans *= n, cnt2 = 1;
        cnt = cnt > cnt2 ? cnt : cnt2;
        if(cnt!=1) flag = 1;
    }

    int ans2 = 0;
    ll x = cnt;
    while(cnt){
        cnt >>= 1;
        ans2++;
    }
    if(x!=powmod(2,max(0,ans2-1))){
        ans2++;
        flag = 1;
    }
    if(flag)ans2++;
    cout << ans << " " << ans2-1 << endl;
}
int main()
{    cin >> n;
    divide(n);
    return 0;
}

// 1 2 3 5 6 7 10 11 13 14 15 17