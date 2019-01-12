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

int n,m,q;
char s[1007];
char t[1007];

int lft[100007];
int rit[100007];

int main()
{
    scanf("%d%d",&n,&m);
    int ans1[107];
    int ans2[107];
    int cnt1=0;
    int cnt2=0;
    int x;
    rep(i,1,n+1){
        scanf("%d",ans1+i);
        cnt1 ^= ans1[i];
    }
    int cnt=0;
    rep(i,1,m+1){
        scanf("%d",ans2+i);
        cnt2 ^= ans2[i];
        if(i==m-1) cnt = cnt2;
    }

    if(cnt1!=cnt2){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        rep(i,1,n){
            rep(j,1,m){
                printf("0 ");
            }
            printf("%d\n",ans1[i]);
        }
        rep(j,1,m)
            printf("%d ",ans2[j]);
        printf("%d\n",cnt^ans1[n]);
    }


    return 0;
}


