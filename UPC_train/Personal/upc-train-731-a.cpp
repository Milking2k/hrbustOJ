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


int t,n,m;
int vx[100007],vy[100007];
int main()
{
    while(~scanf("%d",&n)){
        rep(i,0,n+2){
            vx[i]=vy[i]=0;
        }

        ll sum=0,sumx=0,sumy=0;
        rep(i,1,n+1){
            int x,y;
            scanf("%d%d",&x,&y);
            sum++;
            if(vx[x]==0){
                sumx++;
                vx[x]=1;
            }
            if(vy[y]==0){
                sumy++;
                vy[y]=1;
            }
        }

        ll cnt = sumx*sumy;
//        printf("cnt:%lld sx*xy:%lld sum:%d\n",cnt,sumx*sumy,sum);
        if(cnt < 2*sum){
            printf("%lld\n",2*sum-cnt);
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}


/*
2
1 1
2 2

4
1 1
2 2
1 2
2 1

4
1 1
2 2
3 2
2 3



*/
