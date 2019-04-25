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
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int A, B, C;
    cin >> A >> B >> C;
    int time = min(min(A / 3, B / 2), C / 2);

    A -= time * 3;
    B -= time * 2;
    C -= time * 2;
    // printf("%d %d %d\n", A, B, C);
    int pra[20] = {1, 0, 0, 1, 0, 0, 1};
    int prb[20] = {0, 1, 0, 0, 0, 1, 0};
    int prc[20] = {0, 0, 1, 0, 1, 0, 0};
    int ans = time*7;
    int cur = time*7;
    int a, b, c;
    rep (i, 0, 7) {
        rep (j, 0, 7) {
            a = b = c = 0;
            rep(k,0,j+1){
                int t = (i + k) % 7;
                a += pra[t];
                b += prb[t];
                c += prc[t];
            }
            if (A >= a && B >= b && C >= c) {
                // printf("%d %d %d::%d\n", a, b, c,cur+j+1);
                ans = max(ans, cur + j + 1);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
/*
1.  2,  3;  4.  5;  6,  7.
1: 3 2 2 
2: 
*/