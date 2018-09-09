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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;

struct node
{
    int l,r;
    bool operator < (const node &a) const {
        if(l==a.l) return r<a.r;
        return l<a.l;
    }
}a[N];
int n,m;

int _l[N],_r[N];

void solve()
{
    int ans=m;
    int l=0,r=0;
    int tmp=m;
    while(r<n)
    {
        while(r+1<n && _l[r+1] - _r[r]-1<=tmp )
        {
            tmp-= _l[r+1] - _r[r]-1;
            r++;
        }
        ans = max(ans,_r[r]-_l[l]+tmp);
        if(l+1<n && _l[l+1] - _r[l]-1 >0 && _l[l+1] - _r[l]-1+tmp <= m)
        {
            tmp+=_l[l+1] - _r[l]-1;
        }
        l++;
        while(l>r)
            r++;
    }
    printf("%d\n",ans);

}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        rep(i,1,n+1){
            scanf("%d%d",&a[i].l,&a[i].r);
        }
        sort(a+1,a+1+n);

        int cntr = a[1].r;
        int cntl = a[1].l;
        int pos = 1;
        rep(i,1,n+1){
            cntl = a[i].l;
            cntr = a[i].r;
            bool flag = false;
            while(++i <= n && a[i].l <= cntr){
                cntr = a[i].r;
                flag = true;
            }
            i--;
            _l[pos] = cntl;
            _r[pos] = cntr;
            pos++;
        }
        n = pos;
        solve();
    }
    return 0;
}
/*

4 3
1 4
3 7
12 13 15 17
*/
