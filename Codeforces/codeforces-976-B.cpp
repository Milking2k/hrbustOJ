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

const int N = 2e6+7;
ll T, n, m, k;
int main()
{
    cin >> n >> m >> k;
    if (k <= n - 1){
        cout << k+1 << " " << 1;
    }
    else{
        k = k-(n - 1);
        ll a = k / (m - 1);
        ll b = k % (m - 1);
        ll c = n - a + 1;
        // cout << k << " " << a << " " << b << " "<< c << " \n";
        if(a&1){
            if(b==0){
                cout << c << " " << m;
            }
            else 
                cout << c - 1 << " " << m - b+1;
        }
        else{
            if(b==0){
                cout << c << " " << 2;
            }
            else
                cout << c - 1 << " " << b + 1;
        }
    }
    return 0;
}