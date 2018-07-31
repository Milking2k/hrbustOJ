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


int t,n,m,k;
int emt[307][307];
int v[307][307];
int d[307][307];


int main()
{
    scanf("%d",&n);
    rep(i,1,n+1){
        rep(j,1,n+1){
            scanf("%d",&d[i][j]);
            v[i][j] = 0;
            emt[i][j] = d[i][j];
        }
    }

    bool flag = true;
    ll sum=0;
    rep(k,1,n+1)
    rep(i,1,n+1)
    rep(j,1,n+1){
//        printf("d[%d %d %d]:%d  %d\n",i,j,k,d[i][j] , d[i][k]+d[i][j]);
//        v[i][j] |= v[i][k] & v[k][j];
        if(i!=k && k!=j && d[i][j] == d[i][k]+d[k][j]){
            v[i][j] = 1;
        }
        else if(i!=k && k!=j && d[i][j] > d[i][k]+d[k][j]){
            flag = false;
//            printf("flag\n");
        }
    }


    rep(i,1,n+1)
    rep(j,i+1,n+1){
        if(i!=j && v[i][j]==0 && emt[i][j] == d[i][j]){
            sum+=d[i][j];
//            printf("i:%d j:%d = %d\n",i,j,d[i][j]);
        }
    }
    if(!flag)
        printf("-1\n");
    else
        printf("%lld",sum);

/*

4
0 2 1 3
2 0 4 2
1 4 0 5
3 2 5 0
*/

    return 0;
}


