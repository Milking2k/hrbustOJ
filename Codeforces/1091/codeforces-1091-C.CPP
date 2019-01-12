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
priority_queue<int> getPrimes(ll n)
{
    priority_queue<int> ret;
    for (int i = 2; i * i <= n;i++){
        if(n%i==0) {
            ret.push(i);
            if(i!=n/i)
                ret.push(n / i);
        }
    }
    return ret;
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    static long long n;
    cin >> n;
    priority_queue<int> primes = getPrimes(n);
    cout << 1 << " ";
    while(primes.size()){
        auto i = primes.top();primes.pop();

        ll cur = n / i;
        cout << cur+cur*(cur-1)*i/2 << " ";
        // printf("debug:%d %d\n", cur,i);
    }
    cout << n + n * (n - 1) / 2 << endl;


    return 0;
}