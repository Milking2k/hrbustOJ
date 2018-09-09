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
//const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;
int T,n,m,k;
ll seed,vmax;

struct node
{
    int l,r;
    mutable ll v;
    node(int _l,int _r = -1,ll _v = 0) : l(_l), r(_r), v(_v){}
    bool operator < (const node &a) const { return l < a.l; }
};

set<node> s;
vector < pair <ll, int> > vp;

set<node>::iterator split(int pos){
    auto it = s.lower_bound(node(pos));
    if(it != s.end() && it->l == pos) return it;
    else --it;

    if(pos > it->r) return s.end();
    int L = it->l, R = it->r;
    ll V = it->v;
    s.erase(it);
    s.insert(node(L,pos-1,V));
    return s.insert(node(pos,R,V)).fi;
}
void assign(int l, int r, ll val=1){
    auto itr = split(r+1), itl = split(l);
    s.erase(itl,itr);
    s.insert(node(l,r,val));
}

void add(int l, int r, int val = 1){
    auto itr = split(r+1),itl = split(l);
    for(;itl != itr;itl++) itl->v += val;
}

ll Rank(int l, int r, int k, bool reversed = 0){
    if(reversed) k = r - l + 2 - k;
    auto itr = split(r+1),itl = split(l);
    vp.clear();
    for(;itl!=itr;itl++){
        vp.push_back({itl->v, itl->r - itl->l + 1});
    }
    sort(vp.begin(), vp.end());
    for(auto i:vp){
        k -= i.se;
        if(k <= 0) return i.fi;
    }
    return -1;
}

ll sum(int l, int r, int ex, ll mod){
    auto itr = split(r+1), itl = split(l);
    ll res=0;
    for(;itl != itr;itl++){
        res = (res + (ll)(itl->r - itl->l + 1) * powmod(itl->v, ex,mod))%mod;
    }
    return res;
}


ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

int main() {
    cin >> n >> m >> seed >> vmax;
    for (int i = 1; i <= n; i++) {
        s.insert(node(i, i, (rnd() % vmax + 1)));
    }
    for (int i = 1; i <= m; i++) {
        int op = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1;
        int x, y;
        if (l > r)  swap(l, r);
        if (op == 3) {
            x = (rnd() % (r - l + 1)) + 1;
        } else {
            x = rnd() % vmax + 1;
        }
        if (op == 4) {
            y = (rnd() % vmax) + 1;
        }
        if (op == 1) {
            add(l, r, x);
        } else if (op == 2) {
            assign(l, r, x);
        } else if (op == 3) {
            cout << Rank(l, r, x) << endl;
        } else {
            cout << sum(l, r, x, y) << endl;
        }
    }
    return 0;
}
