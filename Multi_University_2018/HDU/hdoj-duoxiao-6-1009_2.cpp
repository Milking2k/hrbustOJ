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

const int N =1E5+7;

PII say[N];
VI pre[N];
int n,m,k,res=0,flag[N],ans[N];
void dfs(int x, int root)
{
    flag[x] = 1;
    int xnext = say[x].fi;
    int totype = say[x].se;
    if(totype){ // to usr is village
        ans[totype] = root;
        dfs(xnext,root);
    }
    else if(ans[xnext]==root){ // to usr is wolf And it's the same root:it's totally a wolf
        res+=pre[xnext].size();
    }
}

void solve()
{
    res=0;
    rep(i,1,n+1){
        if(!flag[i] && ans[i]==0)
            dfs(i,i);
    }
//    rep(i,1,n+1){
//        if(ans[i]==-1)
//            res++;
//    }
    printf("%d\n",res);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        rep(i,1,n+1){
            flag[i] = 0;
            ans[i] = 0;
        }

        rep(i,1,n+1){
            char s[20];
            int usr;
            scanf("%d %s",&usr,s);
            if(s[0]=='v'){
                say[i] = mp(usr,1);
                pre[usr].pb(i);
            }
            else{
                say[i] = mp(usr,0);
            }
        }
        solve();
    }
    return 0;
}
