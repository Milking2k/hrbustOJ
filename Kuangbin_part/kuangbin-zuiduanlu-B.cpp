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

const int N = 1e5+7;
const int M = 4e2+7;
int T,n,m,k,tot=1;
double ans=0;
struct point
{
    int x, y;
}p[N];
struct node
{
    int x, y;
    double z;
    bool operator < (const node &b) const{
        return z < b.z;
    }
}edge[N];

int fa[N];
int get(int x){
    if(x==fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

double dis(int x,int y, int u, int v){
    return (1.0 * (x - u) * (x - u) + 1.0 * (y - v) * (y - v));
}

int main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int Cas = 0;
    while(~scanf("%d",&n) && n){
        tot = 1;
        ans = 0;
        rep(i,1,n+1){
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        rep(i,1,n+1)rep(j,i+1,n+1){
            point u = p[i], v = p[j];
            double w = dis(u.x, u.y, v.x, v.y);
            edge[tot].x = i, edge[tot].y = j, edge[tot].z = w;
            tot++;
        }
        sort(edge + 1, edge + tot);
        rep(i, 1, n + 1) fa[i] = i;

        rep(i,1,tot){
            int x = get(edge[i].x);
            int y = get(edge[i].y);
            if(x==y)
                continue;
            fa[x] = y;
            if(get(1)==get(2)){
                ans = edge[i].z;
                break;
            }
        }
        printf("Scenario #%d\n",++Cas);   
        printf("Frog Distance = %.3f\n\n", sqrt(ans));
    }    

    return 0;
}

