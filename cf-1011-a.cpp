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


int t,n,m;
char s[57];
int cnt[57];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s);

    rep(i,0,n){
        cnt[i] = s[i] - 'a' + 1;
    }

    sort(cnt,cnt+n);
    int len = unique(cnt,cnt+n)-cnt;
    if(len < m) return !printf("-1");

//    printf("%d\n",len);
    int ans = 0;
    int tot=0;
    int nowcnt=-1000;
    for(int i = 0; i < len && tot < m; i++){
//        printf("%d::%d\n",nowcnt,cnt[i]);
        if(nowcnt+1 == cnt[i]){
            continue;
        }

        nowcnt = cnt[i];
        ans += nowcnt;
        tot++;
    }
    if(tot < m) printf("-1");
    else printf("%d",ans);
    return 0;
}
