#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e7+7;
vector<int> son[N];

ll dp[N][2],vis[N],h[N],n;
struct Circle{double x,y,r;int wi,id;}a[N];

bool check(Circle i, Circle j){
    double dist = (i.x-j.x)*(i.x-j.x) + (i.y-j.y)*(i.y-j.y);
    if(dist - (j.r-i.r)*(j.r-i.r) > -1e-8) return true;

    return false;
}

void dp_fc(int x){
    dp[x][0] = 0;
    dp[x][1] = h[x];
    rep(i,0,son[x].size()){
        int y = son[x][i];
        dp_fc(y);
        dp[x][0] += max(dp[y][0],dp[y][1]);
//        printf("i:%d 0:%d 1:%d\n",x,dp[x][0],dp[x][1]);
    }
}

bool cmp(Circle a, Circle b){
    return a.r<b.r;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)){
        rep(i,1,n+1){
            scanf("%lf %lf %lf",&a[i].x, &a[i].y, &a[i].r);
            scanf("%d",&h[i]);// wi
            a[i].id = i;
        }

        sort(a+1,a+1+n,cmp);
        rep(i,1,n+1)
        rep(j,i+1,n+1){
            if(check(a[i],a[j])){
                vis[j]=1;
                son[j].pb(i);// iÔÚjÔ²ÄÚ
                printf("%d -> %d \n",a[j].id ,a[i].id);
                break;
            }
        }

        int root;
        rep(i,1,n+1){
            if(!vis[i]){
                root = i;
                break;
            }
        }

        printf("root:   %d\n",root);

        dp_fc(root);

        ll maxnum=0;
        rep(i,1,n+1){
            maxnum=max(maxnum, max(dp[i][0], dp[i][1]));
        }
        printf("%lld\n",maxnum);
    }
    return 0;
}
