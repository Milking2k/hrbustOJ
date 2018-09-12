#include <algorithm>
#include <assert.h>
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include<cmath>
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

const int N = 1e3+7;
const int M = 1e6+7;
int T,n,m,k,tot=0;
int ans=0;


struct node
{
    int x, y;
    double z;
    bool operator < (const node &b) const{
        return z < b.z;
    }
}edge[M];

int fa[N];
int get(int x){
    if(x==fa[x]) return x;
    return fa[x] = get(fa[x]);
}

void addedge(int u,int v, int w){

}

int main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int Cas = 0;
    for (scanf("%d", &T); T;T--){
        tot = 0;
        ans = 0;
        int mx = 1000007;
        scanf("%d%d", &n, &m);
        rep(i,1,m+1){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[tot].x = u;
            edge[tot].y = v;
            edge[tot].z = mx-w;
            tot++;
        }
        sort(edge, edge + tot);
        rep(i, 1, n + 1) fa[i] = i;
        rep(i,0,tot){
            int x = get(edge[i].x);
            int y = get(edge[i].y);
            if(x==y)
                continue;
            fa[x] = y;
            if (get(1) == get(n)){
                ans = mx-edge[i].z;
                break;
            }
        }
        printf("Scenario #%d\n", ++Cas);
        printf("%d\n", ans);
    }
    return 0;
}

