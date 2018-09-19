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
const ll mod = 1e8+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e3+100;
const int M = 4e6+100;
int T, n, m, k;
bitset<N> b[N];
char inmp[N][N];
int head[N], nxt[M], ver[M], tot = 0;
void add(int u,int v){
    ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
    b[u].set(v, 1);
}

bool legle(char ch){
    memset(head, -1, sizeof(head));
    tot = 0;
    rep(i, 0, n + 1) b[i].reset();

    rep(i,1,n+1) rep(j,1,n+1) if(inmp[i][j]==ch){
        add(i, j);
    }
    rep(i,1,n+1){
        for (int j = head[i]; j;j=nxt[j]){
            int now = ver[j];
            if((b[i]&b[now]) != b[now])
                return false;
        }
    }
    return true;
}

int main()
{
    for (scanf("%d", &T); T;T--){
        scanf("%d", &n);
        rep(i,1,n+1){
            scanf("%s",inmp[i]+1);
        }
        if(legle('P') && legle('Q'))
            printf("T\n");
        else
            printf("N\n");
    }

    return 0;
}