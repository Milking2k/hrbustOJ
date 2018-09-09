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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int k,tot,head[100004];
struct edge{
    int to,next,w;
}elmt[500004];
queue<int>q;

int dis[100004];
void add(int u,int v,int w){
     elmt[++tot].to = v; elmt[tot].next = head[u];
     elmt[tot].w = w;
     head[u]=tot;
}
int main()
{    
    scanf("%d",&k);
    rep(i,0,k){
        add(i,(i+1)%k,1);
        add(i,(i*10)%k,0);
    }

    q.push(1);
    memset(dis,127/3,sizeof(dis));
    dis[1]=0;
    // printf("test\n");
    while(!q.empty()){
        int now = q.front();q.pop();

        for(int i = head[now];i; i = elmt[i].next){
            if( dis[elmt[i].to] > dis[now]+elmt[i].w){
                dis[elmt[i].to] = dis[now]+elmt[i].w;
                q.push(elmt[i].to);
            }
        }
    }

    printf("%d\n",dis[0]+1);
    return 0;
}