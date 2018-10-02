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
int T, n, m, k;
PII a[N];
map<double, int> cnt;
bool cmp (PII a, PII b){
    if(a.se==b.se)
        return a.fi < b.fi;
    return a.se < b.se;
}
double dis(PII a, PII b){
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}
int main()
{
    for (scanf("%d", &T); T;T--){
        cnt.clear();
        scanf("%d", &n);
        rep(i,1,n+1){
            scanf("%d %d", &a[i].fi, &a[i].se);
        }
        if(n>=5){
            printf("NO\n");
        }
        else if(n==4){
            double len1 = dis(a[1], a[2]);
            double len2 = dis(a[3], a[4]);
            
            double len3 = dis(a[1], a[3]);
            double len4 = dis(a[2], a[4]);
            
            double len5 = dis(a[1], a[4]);
            double len6 = dis(a[2], a[3]);
            if(len1!=len2 || len3!=len4 || len5!=len6){
                printf("NO\n");
            }
            else
                printf("YES\n");
        }
        else if(n==3){
            double len1 = dis(a[1], a[2]);
            double len2 = dis(a[1], a[3]);
            double len3 = dis(a[3], a[2]);
            if(len1 != len2 || len1!=len3 || len1!=len2){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
        }
    }
    return 0;
}