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
const int N = 2e5+7;
int T,n,m;
int a[N];

struct node
{
    int v;
};

map<int, node> mm;
bool vis[N];

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    vector<PII> head;
    vector<int> val;
    cin >> n >> m;
    
    rep(i, 0, n) {
        int x;
        cin >> x;
        head.push_back(mp(x,i));
        val.push_back(x);
    }
    sort(head.begin(), head.end(), [](PII a, PII b) { return a.fi > b.fi; });
    int cur = 1;
    for (auto x:head){
        if(vis[x.se] == 0) {
            int tpos = x.se;
            vis[tpos] == 1;
            if(tpos < m){

            }
            else {
                tpos -= m;
                rep(i,1,2*m+1){
                    v.earse
                }
            }
        }
    }

    return 0;
}
/*

*/