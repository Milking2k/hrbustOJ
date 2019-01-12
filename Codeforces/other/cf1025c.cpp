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
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e6+7;
int T,n,m;
char s[N];
int main()
{
    scanf("%s", s);
    n = strlen(s);
    int len = 1;
    int ans = 1;
    rep(i,0,n){
        s[i + n] = s[i];
    }
    if(n==1) return !printf("1\n");
    // printf("%s\n", s);
    rep(i,1,2*n-1){
        if(s[i] == s[i-1])
            len=1;
        else{
            len++;
            ans = max(ans, len);
        }
        // printf("%c nowans;%d len:%d\n",s[i], ans,len);
    }
    printf("%d\n", min(n,ans));
    return 0;
}