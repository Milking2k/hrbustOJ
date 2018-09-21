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
int T, n, m, k,Cas=0;
struct node
{
    int pos, id, dir;
    bool operator < (const node& a) const{
        return pos < a.pos;
    }
} a[N];
int has[N];
int main()
{
    for (scanf("%d", &T); T;T--){
        scanf("%d%d%d", &k, &m, &n);
            char ch[10];
        rep(i,1,n+1){
            scanf("%d%s", &a[i].pos, ch);
            a[i].dir = ch[0] == 'R' ? 1 : -1;
            a[i].id = i;
        }
        
        sort(a + 1, a + 1 + n);
        rep(i,1,n+1){
            has[a[i].id] = i;
            a[i].pos += m * a[i].dir;
        }
        sort(a + 1, a + 1 + n);
        printf("Case #%d:\n", ++Cas);
        rep(i,1,n+1){
            int p = has[i];
            if(a[p].pos<0 || a[p].pos >k){
                printf("Fell off\n");
            }
            else if(a[p].pos == a[p-1].pos || a[p].pos==a[p+1].pos){
                printf("%d Turning\n", a[p].pos);
            }
            else {
                printf(a[p].dir == -1 ? "%d L\n" : "%d R\n", a[p].pos);
            }
        }
        puts("");
    }
        return 0;
}
