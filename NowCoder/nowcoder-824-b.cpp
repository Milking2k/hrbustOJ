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

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 100010
int lsum[maxn<<2],rsum[maxn<<2],msum[maxn<<2];
int num[maxn];
void pushup(int l,int r,int rt)
{
    int m=(l+r)/2;
    lsum[rt]=lsum[rt<<1];
    rsum[rt]=rsum[rt<<1|1];
    msum[rt]=max(msum[rt<<1],msum[rt<<1|1]);
    if(num[m]<num[m+1])
    {
        if(lsum[rt<<1]==m-l+1)
            lsum[rt]=lsum[rt<<1]+lsum[rt<<1|1];
        if(rsum[rt<<1|1]==r-m)
            rsum[rt]=rsum[rt<<1|1]+rsum[rt<<1];
        msum[rt]=max(msum[rt],lsum[rt<<1|1]+rsum[rt<<1]);
    }
}
void build(int l,int r,int rt)
{
    
    if(l==r)
    {
        lsum[rt]=rsum[rt]=msum[rt]=1;
        return;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    pushup(l,r,rt);
}
void updata(int p,int c,int l,int r,int rt)
{
    if(l==r)
    {
        num[l]=c;
        return ;
    }
    int m=(l+r)/2;
    if(m>=p)
        updata(p,c,lson);
    else updata(p,c,rson);
    pushup(l,r,rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(l>=L&&R>=r)
        return msum[rt];
    int ret=0;
    int m=(l+r)/2;
    if(m>=L)
        ret=max(ret,query(L,R,lson));
    if(R>m)
        ret=max(ret,query(L,R,rson));
    if(num[m]<num[m+1])
    {
        ret = max(ret, min(m - L + 1, rsum[rt << 1]) + min(R - m, lsum[rt << 1 | 1]));
    }
    return ret;
}
int main()
{
    int n,t,m,i;

        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&num[i]);
        build(1,n,1);
        int a,b;
        printf("%d\n",query(1,n,1,n,1));
        while(m--)
        {
            scanf("%d %d",&a,&b);
            updata(a,b,1,n,1);
            printf("%d\n",query(1,n,1,n,1));
        }

}