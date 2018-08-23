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

const int N = 1e5+7;
const double SQRT3 = 1.732050807568877;
int T,n,m,k;
int a[N];

ll ans = 0;

struct node
{
    int x,y,id;
    double vl,vr;
    bool flag;
}emt[N];

vector<node> vleft;
vector<node> vright;
vector<node> vdown;

map<double, int> mapp;
map<double, int> mapp2;
map<int, int> mapp3;
PII pnt[N];
int vis[N],Next[N];

void solve(int a, double b, double c)
{

}

int main(int argc, char const *argv[])
{
    read(n,k);
    m = min(n-2, 5000);
    rep(i,1,n+1){
        int x,y;
        read(x,y);

        emt[i].x = x;
        emt[i].y = y;
        emt[i].id = i;
        emt[i].vr = SQRT3*x+y; // right
        emt[i].vl = SQRT3*x-y; // left
        emt[i].flag = false;
        
        vleft.pb(emt[i]);
        vright.pb(emt[i]);
        vdown.pb(emt[i]);
    }

    sort(all(vleft),[](node a, node b){return a.vl>b.vl;});
    sort(all(vright),[](node a, node b){return a.vr>b.vr;});
    sort(all(vdown),[](node a, node b){return a.y<b.y;});
    
    int now = 0;
    int klease = k;
    for(vector<node>::iterator i = vdown.begin(); i != vdown.end();) {
        while(i != vdown.end() && i->y < now){
            i++;
            klease--;
            emt[i->id].flag = true;
        }
        now = i->y;// delete the down point
        if(klease<0) break;

        vector<node>::iterator j = vleft.begin();
        int cntklease = klease;
        double leftnow = j->vl;
        int cnt = 0;
        for(; j != vleft.end();){
            while( j != vleft.end() && j!=vleft.begin() && leftnow - j->vl < 1e-15){
                j++, cnt++;
            }
            leftnow = j->vl;
            cntklease -= cnt;// delete the same left point

            if(cntklease == 0) solve(i->y, j->vl, vright[1].vl); // if right the left has the answer k,solve to min ans
            else if(cntklease > 0){// else to decrease the right hand;
                vector<node>::iterator k = vright.begin();
                int cnt = 0;
                double rightnow = k->vr;
                while(k != vleft.end() && cntklease > 0){
                    while( k != vleft.end() && fabs(rightnow - k->vl) < 1e-6) k++, cnt++;
                    klease -= cnt;
                    rightnow = k->vl;
                }
                if(klease == 0) solve(i->y, j->vl, k->vr);
            }
        }
    }

    printf("%lld\n",ans);
    
    return 0;
}
