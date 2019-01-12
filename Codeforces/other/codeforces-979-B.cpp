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
const int N = 1e5+7;
int T,n,m;
int alph1[100],alph2[100],alph3[100];
char s1[N],s2[N], s3[N];
int mx1 = 0, mx2 = 0, mx3 = 0;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    // printf("%d\n",'z'-'A');
    cin >> s1 >> s2 >> s3;
    int len = strlen(s1);
    rep(i,0,len){
        mx1 = max(mx1, ++alph1[s1[i] - 'A']);
        mx2 = max(mx2, ++alph2[s2[i] - 'A']);
        mx3 = max(mx3, ++alph3[s3[i] - 'A']);
    }
    if(n==1 && mx1==len)
        mx1--;
    else
        mx1 = min(len, mx1 + n);
    
    if(n==1 && mx2==len)
        mx2--;
    else
        mx2 = min(len, mx2 + n);
    
    if(n==1 && mx3==len)
        mx3--;
    else
        mx3 = min(len, mx3 + n);
    
    // printf("%d %d %d\n", mx1, mx2, mx3);
    if(mx1>mx2 && mx1>mx3) cout << "Kuro\n";
    else if(mx2>mx1 && mx2>mx3) cout << "Shiro\n";
    else if(mx3>mx1 && mx3>mx2) cout << "Katie\n";
    else cout << "Draw\n";

    return 0;
}

