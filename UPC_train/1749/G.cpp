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
const int N = 1e6 + 7;
const int M = 1e5 + 7;
int T,n,m;

int head[N], edge[M], tot, Next[M], ver[M];
bool v[N];


void addedge(int u,int v, int w)
{
    ver[++tot] = v, edge[tot] = w, Next[tot] = head[u], head[u] = tot;
}

int aans[N];
// vector<PII> tempans[2];
priority_queue<PII> tempans[2];
int bfs(int x, int f)
{
    if(f==1){
        // for (auto x:tempans[0]) {
        //     // printf("%d_", x.fi);
        // }
        while(!tempans[0].empty()){
            v[tempans[0].top().fi] = 0;
            tempans[0].pop();
        }
        // puts("");
    }
    int nowf = f;
    int ans = 0;
    while (!tempans[nowf].empty()) tempans[nowf].pop();


    queue<PII> Q;
    Q.push({x,f});

    v[x] = 1;
    aans[x] = f;


    while(!Q.empty()) {
        PII now = Q.front();
        Q.pop();
        int y = now.fi;
        int sonf = now.se;
        // printf("\n%d-%d\n", y, sonf);
        ans += (sonf == 0);
        aans[y] = sonf;
        v[y] = 1;
        tempans[nowf].push({y,sonf});

        for (int i = head[y]; i; i = Next[i]) {
            if(v[ver[i]] == 1) {
                if(sonf==1 && edge[i] != aans[ver[i]]){
                    return -1;
                }
                else if(sonf == 0 && (edge[i]^1) != aans[ver[i]]){
                    return -1;
                }
                else continue;
            }
            if(sonf == 1){ // 父节点为真人
                Q.push({ver[i], edge[i]});
            }
            else {
                Q.push({ver[i], 1^edge[i]});
            }
            v[ver[i]] = 1;
        }
    }
    return ans;
}
/*
3
3 2
1 2 1
1 2 1
5 4
1 2 1
2 3 0
2 4 0
1 5 0
3 3
1 2 1
1 3 0
2 3 1
*/

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    scanf("%d",&T);
    for (size_t _ = 0; _ < T; _++)
    {
        scanf("%d%d", &n, &m);
        fill(head, head + n + 5, 0);
        fill(aans, aans + n + 5, 0);
        fill(v, v + n + 5, 0);
        // memset(head, 0, sizeof(head));
        // memset(aans, 0, sizeof(aans));
        // memset(v, 0, sizeof(v));
        map<int, PII> mmm;
        tot = 0;
        bool ok = 0;

        rep(i,1,m+1){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
            if(mmm.find(u) != mmm.end()){
                PII temp = mmm[u];
                if(v == temp.fi && w != temp.se) ok = 1;
            }
            mmm[u] = {v,w};
        }
        rep(i,1,n+1) {
            if(v[i]) continue;
            int ans1 = bfs(i, 0);
            // puts("time2");
            int ans2 = bfs(i, 1);
            // printf("ans:%d %d\n", ans1, ans2);
            if(ans1 <0 && ans2<0){
                ok = 1;
                break;
            }
            else if(ans1 < 0){
                while(!tempans[1].empty()){
                    PII temp = tempans[1].top();
                    if (temp.se == 0) break;
                    aans[temp.fi] = temp.se;
                    tempans[1].pop();
                }
                // for (auto x : tempans[1]) aans[x.fi] = x.se;
            }
            else if(ans2 < 0) {
                while (!tempans[0].empty())
                {
                    PII temp = tempans[0].top();
                    if (temp.se == 0)
                        break;
                    aans[temp.fi] = temp.se;
                    tempans[0].pop();
                }
                // for(auto x : tempans[0]) aans[x.fi] = x.se;
            }
            else if(ans1 < ans2){
                while (!tempans[0].empty())
                {
                    PII temp = tempans[0].top();
                    if (temp.se == 0)
                        break;
                    aans[temp.fi] = temp.se;
                    tempans[0].pop();
                }
                // for(auto x : tempans[0]) aans[x.fi] = x.se;
            }
            else {
                while (!tempans[1].empty())
                {
                    PII temp = tempans[1].top();
                    if (temp.se == 0)
                        break;
                    aans[temp.fi] = temp.se;
                    tempans[1].pop();
                }
                // for(auto x : tempans[1]) aans[x.fi] = x.se;
            }
        }

        if(ok){
            puts("-1");
            continue;
        }
        rep(i, 1, n + 1) printf("%d", aans[i]);
        puts("");
    }
    
    return 0;
}
/*

*/