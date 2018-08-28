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

const int N = 1e6+7;
int T,n,m,k,a[N];
int d[310][310];
map<int, int> ans;
int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin >> n && n){
        memset(d,0x3f,sizeof(d));
        ans.clear();
        cin >> m;
        rep(i,1,n+1) d[i][i] = 0;
        rep(i,1,m+1) {
            int x,y;
            cin >> x >> y;
            x++,y++;
            d[x][y] = min(d[x][y], 1);
            d[y][x] = min(d[y][x], 1);
        }

        rep(i,1,n+1) rep(j,1,n+1) rep(k,1,n+1){
            d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
        }
        rep(i,1,n+1) rep(j,1,n+1){
            // cout <<i<< "_"<<j<<"_"<< d[i][j] << endl;
            if(i==j || d[i][j] == 0x3f) continue;
            ans[ d[i][j] ] += 1;
        }
        // sort(ans.begin(), ans.end());
        for(auto i = ans.begin(); i!=ans.end(); i++){
            cout << i->first << " " << i->second << endl;
        }
        
    }    

    return 0;
}
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

const int N = 1e6+7;
int T,n,m,k,a[N];
int d[310][310];
map<int, int> ans;
int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin >> n && n){
        memset(d,0x3f,sizeof(d));
        ans.clear();
        cin >> m;
        rep(i,1,n+1) d[i][i] = 0;
        rep(i,1,m+1) {
            int x,y;
            cin >> x >> y;
            x++,y++;
            d[x][y] = min(d[x][y], 1);
            d[y][x] = min(d[y][x], 1);
        }

        rep(i,1,n+1) rep(j,1,n+1) rep(k,1,n+1){
            d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
        }
        rep(i,1,n+1) rep(j,1,n+1){
            // cout <<i<< "_"<<j<<"_"<< d[i][j] << endl;
            if(i==j || d[i][j] == 0x3f) continue;
            ans[ d[i][j] ] += 1;
        }
        // sort(ans.begin(), ans.end());
        for(auto i = ans.begin(); i!=ans.end(); i++){
            cout << i->first << " " << i->second << endl;
        }
        
    }    

    return 0;
}
>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
