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

int n,k;
int a[300010];
int main()
{
    scanf("%d%d",&k,&n);
    if(k&1)
    {
        int now=n;
        rep(i,1,n+1) a[i]=(k+1)/2;

        rep(i,1,n/2+1){
            if(a[now]==1) now--;
            else 
            {
                a[now]--;
                rep(j,now+1,n+1) a[j]=k;
                now=n;
            }
        }

        rep(i,1,now+1) printf("%d ",a[i]); 
    }
    else
    {
        printf("%d ",k/2);
        rep(i,2,n+1) printf("%d ",k);
    }
    return 0;
}