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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;
int T,n,m,k,pre[N],vis[30];
char s[N];

int main()
{
    for(scanf("%d",&T);T;T--){
        scanf("%s",s+1);
        scanf("%d",&k);

        n = strlen(s+1);
//        printf("n:%d\n",n);
//        rep(i,0,n+1) pre[i] = 0;
        memset(vis,0,sizeof(vis));

//        rep(i,0,n){
//            if(!vis[s[i]-'a']){
//                pre[i+1] = pre[i] + 1;
//                vis[s[i]-'a']=1;
//            }
//            else{
//                pre[i+1] = pre[i];
//            }
//            printf("%d ",pre[i+1]);
//        }
//        puts("");
        int j=0,cnt=0;
        ll ans = 0;
        vis[s[0]-'a'] = 0x3f3f3f3f;
        rep(i,1,n+1){
            vis[s[i-1]-'a']--;
//            printf("visi:%d  cnt:%d\n",vis[s[i-1]-'a'],cnt);
            if((vis[s[i-1]-'a'])<=0) cnt--;
            j = max(i,j);
            while(j<=n+1 && cnt < k){
//                printf("before:sj: %c\n",s[j]);
                if(vis[s[j]-'a'] == 0) cnt++;
                vis[s[j]-'a']++;
                j++;
//                printf("cnt::%d\n",cnt);
            }
            ans = ans + (n-j+2);
//            printf("ijans:::%d %d %lld \n\n",i,j,ans);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
