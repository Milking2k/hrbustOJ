#include <bits/stdc++.h>
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

const int N = 2e6+7;
int n,a,b;
int dmg[N], hp[N];
bool cmp(int i, int j){
    if (hp[i] - dmg[i] != hp[j] - dmg[j])
        return hp[i] - dmg[i] > hp[j] - dmg[j];
    return i < j;
}
int get(int id){
    return hp[id] > dmg[id] ? hp[id] : dmg[id];
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> a >> b;
    rep(i,0,n){
        cin >> hp[i] >> dmg[i];
    }

    ll sum = 0;
    b = min(b, n);
    vector<int> p(n);
    
    rep(i, 0, n) p[i] = i;
    sort(all(p), cmp);

    rep(i,0,n){
        int id = p[i];
        if(i<b)
            sum += get(id);
        else
            sum += dmg[id];
    }

    ll res = sum;

    if(b==0){
        cout << res << endl;
        return 0;
    }

    ll x = (1 << a);
    rep(i,0,n){
        int id = p[i];
        ll nres = sum;
        if(i < b){
            nres -= get(id);
            nres += hp[id] * x;
        }
        else{
            nres -= dmg[id];
            nres += hp[id] * x;
            int id2 = p[b - 1];
            nres -= get(id2);
            nres += dmg[id2];
        }
        res = max(res, nres);
    }

    cout << res << endl;

    return 0;
}

/*
1000000000
500000000
*/