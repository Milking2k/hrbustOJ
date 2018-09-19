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
int n;
struct node
{
    int x, y, p;
} a[N];
bool cmp(node a, node b){
    if(a.x==b.x){
        return a.y > b.y;
    }
    return a.x < b.x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i].x >> a[i].y;
        a[i].p = i;
    }
    sort(a + 1, a + 1 + n,cmp);
    int cnt = a[1].y;
    int pos1 = a[1].p;
    rep(i,2,n+1){
        if(a[i].y > cnt){
            cnt = a[i].y;
            pos1 = a[i].p;
        }
        else{
            cout << a[i].p << " " << pos1;
            return 0;
        }
    }
    cout << "-1 -1";

    return 0;
}

/*
1000000000
500000000
*/