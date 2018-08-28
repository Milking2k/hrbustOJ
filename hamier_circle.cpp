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
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int V = 200;
int n,m;
bool c[V][V];//edge
int x[V];
bool flag[V];
bool vis[V];

void hamilton()
{
    rep(i,0,n){
        x[i] = -1,vis[i] = false;
    }
    int k = 1;
    vis[0] = true;
    x[0] = 0;
    while(k >= 0){
        x[k]++;
        while(x[k] < n){
            if(!vis[x[k]] && c[x[k - 1]][x[k]])
                break;
            else
                x[k]++;
        }
        if((x[k] < n) && (k != n - 1)){
            vis[x[k]] = true;
            k++;
        }
        else if((x[k] < n) && k == n - 1 && c[x[k]][x[0]]){
            break;
        }
        else{
            x[k] = -1;
            k--;
            vis[x[k]] = false;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin >> n >> m){
        // init
        memset(c,0,sizeof(c));
        memset(flag,0,sizeof(flag));

        rep(i,0,m){
            int a,b;
            cin >> a >> b;
            a--,b--;
            c[a][b]=true;
            c[b][a]=true;
        }

        hamilton();

        bool f = false;
        rep(i,0,n){
            flag[x[i]]=1;
        }
        rep(i,0,n){
            if(!flag[i]) f=1;
        }
        if(f) cout <<"no solution" <<endl;
        else{
            rep(i,0,n){
                if(i==n-1) cout << x[i]+1 <<endl;
                else cout << x[i]+1 <<" ";
            }
        }
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
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int V = 200;
int n,m;
bool c[V][V];//edge
int x[V];
bool flag[V];
bool vis[V];

void hamilton()
{
    rep(i,0,n){
        x[i] = -1,vis[i] = false;
    }
    int k = 1;
    vis[0] = true;
    x[0] = 0;
    while(k >= 0){
        x[k]++;
        while(x[k] < n){
            if(!vis[x[k]] && c[x[k - 1]][x[k]])
                break;
            else
                x[k]++;
        }
        if((x[k] < n) && (k != n - 1)){
            vis[x[k]] = true;
            k++;
        }
        else if((x[k] < n) && k == n - 1 && c[x[k]][x[0]]){
            break;
        }
        else{
            x[k] = -1;
            k--;
            vis[x[k]] = false;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin >> n >> m){
        // init
        memset(c,0,sizeof(c));
        memset(flag,0,sizeof(flag));

        rep(i,0,m){
            int a,b;
            cin >> a >> b;
            a--,b--;
            c[a][b]=true;
            c[b][a]=true;
        }

        hamilton();

        bool f = false;
        rep(i,0,n){
            flag[x[i]]=1;
        }
        rep(i,0,n){
            if(!flag[i]) f=1;
        }
        if(f) cout <<"no solution" <<endl;
        else{
            rep(i,0,n){
                if(i==n-1) cout << x[i]+1 <<endl;
                else cout << x[i]+1 <<" ";
            }
        }
    }
    return 0;
>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
}