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
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    sort(a + 1, a + 1 + n);
    // rep(i, 1, n + 1) printf("%d ", a[i]);
    // puts("");

    int l = 1, r = 1;
    int ans = 1;
    int pre = a[1];
    int ansl = 1, ansr = 1;
    while(r <= n) {
        if(a[r] == pre){
            r++;
        }
        else if(a[r] - pre != 1){
            pre = a[r];
            // ans = max(ans, r - l);
            if(r-l > ans){
                ans = r - l;
                ansr = r-1;
                ansl = l;
            }
            l = r;
            r++;
        }
        else{
            // printf("%d_._%d\n", a[r], pre);
            if(r==n || a[r+1] != a[r]){
                // printf("debug::%d\n", r);
                // ans = max(ans, r - l + 1);
                if(r-l+1 > ans){
                    ans = r - l + 1;
                    ansr = r;
                    ansl = l;
                }
                pre = a[r];
                l = r;
                r++;
            }
            else{
                pre = a[r];
                r++;
            }
        }
        if(r==n+1){
            if(r-l+1 > ans){
                ans = r - l;
                ansr = r-1;
                ansl = l;
            }
        }
    }
    printf("%d\n", ans);

    map<int, int> mm;
    rep(i,ansl,ansr+1){
        mm[a[i]]++;
    }
    for (auto &x:mm){
        while(x.second > 1){
            printf("%d ", x.first);
            x.second--;
        }
    }
    vector<int> ans2;
    for (auto &x:mm){
        ans2.pb(x.first);
        x.second--;
    }
    sort(ans2.begin(), ans2.end(), [](int a, int b) { return a > b; });
    for (auto &x:ans2){
        printf("%d ", x);
    }

    return 0;
}
/*

*/