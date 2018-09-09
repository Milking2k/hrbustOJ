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
const int N = 2e6+7;
int n,m,k;
int a[N];
int main()
{
    while(~scanf("%d",&n)){
        rep(i,1,n+1){
            a[i] = read();
        }
        rep(i,1,n+1){
            int x;
            x = read();
            a[i] = a[i] - x;
            a[i+n] = a[i];
        }
        rep(i,1,2*n+1){
            a[i] += a[i-1];
        }
        int j=0;
        rep(i,1,n+1){
            j = max(i,j);
            while(j<=2*n && a[j] - a[i-1] >= 0){
                j++;
            }
            if(j-i+1>=n){
                printf("%d\n",i-1);
                break;
            }
        }
    }
    return 0;
}
