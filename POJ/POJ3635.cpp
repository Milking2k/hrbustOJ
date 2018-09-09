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
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e3+7;
const int M = 1e5+7;
const int INF = 1<<28;
struct ROAD{
    int city,dist;
    ROAD(int a,int b):city(a),dist(b){}
};
struct NODE{
    int cost, city,fuel;
    NODE(int cost, int city,int fuel):cost(cost),city(city),fuel(fuel){}
    bool operator < (const NODE & a) const {return cost > a.cost;} 
};

int T,n,m,k;
int prc[N],cst[N][200];
bool vis[N][200];
vector<ROAD> edge[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    rep(i,1,n+1){
        cin >>prc[i];
    }
    rep(i,1,m+1){
        int u,v,d;
        cin >> u >> v >> d;
        edge[u].pb((ROAD){v,d});
        edge[v].pb((ROAD){u,d});
    }

    cin >> k;// k times question
    while(k--){
        int c,s,e;
        cin >> c >> s >> e;

        // init
        rep(i,0,n+1){
            rep(j,0,c+1){
                cst[i][j] = INF;
                vis[i][j] = false;
            }
        }
        cst[s][0] = 0;

        priority_queue<NODE> pq;
        pq.push(NODE(0,s,0));
        while(pq.size()){
            int ncost = pq.top().cost;
            int ncity = pq.top().city;
            int nfuel = pq.top().fuel;pq.pop();
            if(vis[ncity][nfuel]) continue;
            if(ncity == e) break;

            if(nfuel < c){
                if(ncost + prc[ncity] < cst[ncity][nfuel+1]){
                    cst[ncity][nfuel+1] = ncost + prc[ncity];
                    pq.push(NODE(NODE(cst[ncity][nfuel+1], ncity, nfuel+1)));
                }
            }
            vis[ncity][nfuel] = true;            
        }
        if(cst[e][0] < INF) cout << cst[e][0];
        else cout << printf("impossible\n");
    }

    return 0;
}
