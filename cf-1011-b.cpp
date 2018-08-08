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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 107;
int t,n,m;
int a[N];
int vis[N];

int main()
{
    memset(vis,0,sizeof(vis));

    scanf("%d%d",&n,&m);
    rep(i,1,m+1){
        scanf("%d",a+i);
        vis[a[i]]++;
    }

    if(n>m) return !printf("0");

    int len = m/n; // 最多坚持天数
    per(i,1,len+1){
        int canserve = 0;
//        printf("i:%d\n",i);
        rep(j,1,101){
//            printf("%d ",vis[j]);
            canserve += (vis[j]/i);  // 当前种类分这么多天可养活人数
//            printf("%d ",canserve);
        }
        if(canserve >= n) return !printf("%d\n",i);
    }

    printf("0\n");
    return 0;
}

