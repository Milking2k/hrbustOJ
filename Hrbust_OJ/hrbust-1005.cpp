#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;
int T,n,m,k,a[N];

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for (cin >> T; T;T--){
        cin >> n;
        rep(i,1,n+1){
            cin >> a[i];
        }
        int i = 1,j = 1;
        ll sum = 0;
        int ans = 0;
        for (int i = 1; i <= n;i++){
            sum -= a[i-1];
            j = max(i, j);

            while (i <= n && sum > 47){
                sum -= a[i];
                i++;
                // printf("i:%d sum:%d\n", i,sum);
            }

            while (j <= n && sum < 47){
                sum += a[j];
                j++;
                // printf("j:%d sum:%d\n", j,sum);
            }

            if(sum==47){
                ans+=1;
                // cout << ans << endl;
            }
                // printf("i:%d j:%d ans:%d sum:%d \n", i, j, ans, sum);
        }
        cout << ans << "\n";
    }
        return 0;
}

