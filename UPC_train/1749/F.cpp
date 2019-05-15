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
int a[N],b[N];
char s[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    scanf("%d", &T);
    for (size_t _ = 0; _ < T; _++)
    {
        scanf("%d%d", &n, &m);
        scanf("%s", s);
        rep(i, 0, n){
            if(i > 0){
                a[i] = a[i - 1];
                b[i] = b[i - 1];
            }
            s[i] != '0' ? a[i]++:b[i]++;
            // printf("%d ", b[i]);
        }
        // puts("");
        // rep/

        int ans = 0;
        int r = 1;
        rep(l,0,n) {
            r = max(l + 1, r);
            while(r <= n && (a[r+1] - a[l] + (s[l]=='1')) <= m){
                // printf("r:%d %d %d ", r, a[r] , a[l]);
                r++;
            }
            ans = max(ans, min(r, n - 1) - l + 1);
            // printf("::%d %d\n", ans, r);
        }
        r = 1;
        rep(l, 0, n) {
            r = max(l + 1, r);
            while (r <= n && (b[r + 1] - b[l] + (s[l] == '0')) <= m)
            {
                // printf("r:%d %d %d ", r, b[r] , b[l]);
                r++;
            }
            ans = max(ans, min(r, n - 1) - l + 1);
            // printf("ans:%d  r:%d\n", ans, r);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
/*

*/