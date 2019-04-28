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
int a[N];

struct B
{
    int v, p;
}b[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;

    int mx = 0, pos = 0;
    rep(i, 1, 10)
    {
        cin >> a[i];
        b[i].v = a[i];
        b[i].p = i;
    }
    sort(b + 1, b + 10, [](B a, B b) {if(a.v==b.v) return a.p>b.p; return a.v<b.v; });
    pos = b[1].p;
    mx = n/b[1].v;

    if (mx == 0)
    {
        cout << "-1";
        return 0;
    }
    else if (n % a[pos] == 0)
    {
        rep(i, 1, mx + 1)
        {
            cout << pos;
        }
        return 0;
    }

    int cur = n % a[pos];
    int morePos = 0;
    int i = 9;
    int count = 0;
    // printf("%d %d %d %d\n", cur, pos, mx, a[pos]);
    // system("pause");
    while (i >= pos + 1 && cur > 0)
    {
        // printf("\na[i]:%d\n", a[i]);
        if (a[i] <= cur + a[pos])
        {
            cout << i;
            cur -= a[i]-a[pos];
            count++;
        }
        else{
            i--;
        }
    }
    rep(i,count,mx){
        cout << pos;
    }

    return 0;
}
/*

*/