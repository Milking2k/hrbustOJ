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

const int N = 1e3+7;
const double eps = 1e-9;
int T,n,m,k,a[N];
char s[N][N];
int sgn(double x)
{
    if (x < -eps)
        return -1;
    if (x > eps)
        return 1;
    return 0;
}
struct vec
{
    double x, y;
    vec() { x = y = 0; }
    vec(double _x, double _y) { x = _x, y = _y; }
    vec operator+(vec v) { return vec(x + v.x, y + v.y); }
    vec operator - (vec v) { return vec(x-v.x, y-v.y); }
    vec operator*(double v) { return vec(x * v, y * v); }
    vec operator/(double v) { return vec(x / v, y / v); }
    double operator*(vec v) { return x * v.x + y * v.y; }
    double len() { return hypot(x, y); }
    double len_sqr() { return x * x + y * y; }
    //逆时针旋转
    vec rotate(double c) { return vec(x * cos(c)-y * sin(c), x * sin(c) + y * cos(c)); }
    vec trunc(double l) { return (*this) * l / len(); }
    vec rot90() { return vec(-y, x); }
};

vec t1, t2, t3;

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool point_on_segment(vec p, vec a, vec b)
{
    return sgn(cross(b-a, p-a)) == 0 && sgn((p-a) * (p-b)) <= 0;
}

int has_intersection(vec a, vec b, vec p, vec q)
{
    int d1 = sgn(cross(b-a, p-a)), d2 = sgn(cross(b-a, q-a));
    int d3 = sgn(cross(q-p, a-p)), d4 = sgn(cross(q-p, b-p));
    if (d1 * d2 < 0 && d3 * d4 < 0)
        return 1; //有交点，且交点不在端点
    if ((d1 == 0 && point_on_segment(p, a, b)) ||
        (d2 == 0 && point_on_segment(q, a, b)) ||
        (d3 == 0 && point_on_segment(a, p, q)) ||
        (d4 == 0 && point_on_segment(b, p, q)))
        return -1; //重合或交点在端点上
    return 0;
}

bool check(int x,int y,int tox,int toy){
    vec a(x, y),b(tox,toy);
    return (has_intersection(a, b, t1, t2) == 0 
        || has_intersection(a, b, t2, t3) == 0 
        || has_intersection(a, b, t1, t3) == 0 );
}

bool vis[N][N];
int dirx[10] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
int diry[10] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
queue<int ,PII> que;
int dfs(int sx,int sy){
    que.push(mp(0,mp(sx, sy)));
    int ans = 0;
    while(!que.empty()){
        auto now = que.front();
        int ans = now.fi;
        int x = now.se.fi, y = now.se.se;
        if(x==n-1 && y==n-1){
            return ans;
        }
        vis[x][y] = 1;
        rep(i,1,n+1){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx<1 || nx>n || ny<1 || ny>n || vis[nx][ny] || s[nx][ny]=='#' || !check(x,y,nx,ny)){
                printf("%d %d %d\n", ans + 1, nx, ny);
                que.push(mp(ans+1,mp(nx, ny)));
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // for (cin >> T; T;T--){
        cin >> n;
        cin >> t1.x >> t1.y >> t2.x >> t2.y >> t3.x >> t3.y;
        rep(i,1,n+1){
            cin >> s[i];
        }
        cout << dfs(0,0);

    // }

        return 0;
}
