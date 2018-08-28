<<<<<<< HEAD
<<<<<<< HEAD
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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e5+7;
int T,n,m,p;
int fa[N],r[N];

void init()
{
    rep(i,0,n+1){
        fa[i] = i;
        r[i] = 0;
    }
}

int getfa(int x)
{
    if(fa[x] == x) return x;
    else{
        int tmp = fa[x];
        fa[x] = getfa(fa[x]);
        r[x] ^= r[tmp];
        return fa[x];
    }
}

bool unite(int u, int v, int s)
{
    int fu = getfa(u);
    int fv = getfa(v);
    if(fu != fv){
        fa[fu] = fv;
        r[fu] = r[u] ^ r[v] ^ s;
        return true;
    }
    if(r[u] ^ r[v] != s) return false;
    else return true;
}

int main()
{
    for(read(T);T;T--){

        read(n),read(m);

        init();
        rep(i,1,n){
            int u,v;
            read(u),read(v);
        }

        int flag = 0;
        rep(i,1,m+1){
            int u,v,s;
            read(u),read(v),read(s);
            if(!unite(u,v,s) && !flag){
                flag = i;
            }
        }

        printf("%d\n", flag - 1);
    }

    return 0;
=======
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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e5+7;
int T,n,m,p;
int fa[N],r[N];

void init()
{
    rep(i,0,n+1){
        fa[i] = i;
        r[i] = 0;
    }
}

int getfa(int x)
{
    if(fa[x] == x) return x;
    else{
        int tmp = fa[x];
        fa[x] = getfa(fa[x]);
        r[x] ^= r[tmp];
        return fa[x];
    }
}

bool unite(int u, int v, int s)
{
    int fu = getfa(u);
    int fv = getfa(v);
    if(fu != fv){
        fa[fu] = fv;
        r[fu] = r[u] ^ r[v] ^ s;
        return true;
    }
    if(r[u] ^ r[v] != s) return false;
    else return true;
}

int main()
{
    for(read(T);T;T--){

        read(n),read(m);

        init();
        rep(i,1,n){
            int u,v;
            read(u),read(v);
        }

        int flag = 0;
        rep(i,1,m+1){
            int u,v,s;
            read(u),read(v),read(s);
            if(!unite(u,v,s) && !flag){
                flag = i;
            }
        }

        printf("%d\n", flag - 1);
    }

    return 0;
>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
=======
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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e5+7;
int T,n,m,p;
int fa[N],r[N];

void init()
{
    rep(i,0,n+1){
        fa[i] = i;
        r[i] = 0;
    }
}

int getfa(int x)
{
    if(fa[x] == x) return x;
    else{
        int tmp = fa[x];
        fa[x] = getfa(fa[x]);
        r[x] ^= r[tmp];
        return fa[x];
    }
}

bool unite(int u, int v, int s)
{
    int fu = getfa(u);
    int fv = getfa(v);
    if(fu != fv){
        fa[fu] = fv;
        r[fu] = r[u] ^ r[v] ^ s;
        return true;
    }
    if(r[u] ^ r[v] != s) return false;
    else return true;
}

int main()
{
    for(read(T);T;T--){

        read(n),read(m);

        init();
        rep(i,1,n){
            int u,v;
            read(u),read(v);
        }

        int flag = 0;
        rep(i,1,m+1){
            int u,v,s;
            read(u),read(v),read(s);
            if(!unite(u,v,s) && !flag){
                flag = i;
            }
        }

        printf("%d\n", flag - 1);
    }

    return 0;
>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
}