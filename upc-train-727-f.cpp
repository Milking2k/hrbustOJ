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

const int N = 2e5+7;
int t,n,m;
char s[N];
int dp[200005];
int Next[200005][30];

int main()
{
    freopen("out.txt","w",stdout);
    scanf("%s",s);
    int len = strlen(s);
    rep(i,0,26){
        Next[len][i] = len;
    }

    per(i,0,len){
        rep(j,0,26){
            if(s[i]==j+'a'){
                Next[i][j] = i;
            }
            else{
                Next[i][j] = Next[i+1][j];
            }
            printf("Next[%d][%c]:%d\n",i,j+'a',Next[i][j]);
        }
    }

    dp[len] = 1;
    per(i,0,len){
        dp[i] = dp[Next[i][0]+1]+1;
        rep(j,1,26){
            dp[i] = min(dp[i], dp[Next[i][j]+1] + 1);
            printf("dp[%d]:%d\n",i,dp[i]);
        }
    }

    int flag = 0;
    while(dp[flag]){
        rep(i,0,26){
            if(dp[flag] == dp[Next[flag][i]+1] + 1){
                printf("%c",'a'+i);
                flag = Next[flag][i] + 1;
                break;
            }
        }
    }

    printf("\n");
    return 0;
}

