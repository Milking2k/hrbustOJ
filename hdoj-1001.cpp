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
inline int read(int &n){char c=getchar();int x=0,se=1;while(c<'0'||c>'9'){if(c=='-')se=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*se;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

struct Node{
    int dt;
    int f;
};

struct cmp{
    bool operator ()(Node a,Node b){
        if(a.dt == b.dt){
            return a.f < b.f;
        }
        return a.dt > b.dt;
    }
};

int main()
{
    int T,n,m;
    scanf("%d",&T);
    long long ans = 0;
    long long anss = 0;
    Node a[100005];
    while(T --){
        priority_queue<Node,vector<Node>,cmp> Q;
        ans = 0;anss = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i ++){
            scanf("%d",&a[i].dt);
            a[i].f = 0;
            if(!Q.empty() && a[i].dt > Q.top().dt){
                ans += a[i].dt - Q.top().dt;
                Node tmp = a[i];
                tmp.f = 1;
                if(Q.top().f == 0){anss += 1;}
                Q.pop();
                Q.push(tmp);
            }
            Q.push(a[i]);
         }
         printf("%lld %lld\n",ans,anss + anss);
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
inline int read(int &n){char c=getchar();int x=0,se=1;while(c<'0'||c>'9'){if(c=='-')se=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*se;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

struct Node{
    int dt;
    int f;
};

struct cmp{
    bool operator ()(Node a,Node b){
        if(a.dt == b.dt){
            return a.f < b.f;
        }
        return a.dt > b.dt;
    }
};

int main()
{
    int T,n,m;
    scanf("%d",&T);
    long long ans = 0;
    long long anss = 0;
    Node a[100005];
    while(T --){
        priority_queue<Node,vector<Node>,cmp> Q;
        ans = 0;anss = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i ++){
            scanf("%d",&a[i].dt);
            a[i].f = 0;
            if(!Q.empty() && a[i].dt > Q.top().dt){
                ans += a[i].dt - Q.top().dt;
                Node tmp = a[i];
                tmp.f = 1;
                if(Q.top().f == 0){anss += 1;}
                Q.pop();
                Q.push(tmp);
            }
            Q.push(a[i]);
         }
         printf("%lld %lld\n",ans,anss + anss);
    }

    return 0;
>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
}