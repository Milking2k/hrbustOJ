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
int T,n,m,k;
struct node
{
    int pos;
    int x,y;
    ll ans;
}a[N];

bool cmp1(node a, node b){return a.x<b.x;}
bool cmp2(node a, node b){return a.pos<b.pos;}

priority_queue <int, vector<int> , greater<int> > mls;

int main()
{
    // ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    rep(i,1,n+1){
        a[i].pos = i;
        cin >> a[i].x;
    }
    rep(i,1,n+1) cin >> a[i].y;

    sort(a+1,a+1+n,cmp1);
    ll sum=0;

    a[1].ans = a[1].y;
    rep(i,1,n+1){
        if(i<=k){
            mls.push(a[i-1].y);
            sum += a[i-1].y;
            a[i].ans = sum + a[i].y;
        // cout <<"sum1 " <<  sum << endl;
        }
        else{
            // cout << "top: " << mls.top() << endl;
            // printf("a[i].y:%d ",a[i].y);
            if(mls.size() && a[i-1].y > mls.top()){
                mls.push(a[i-1].y);
                sum -= mls.top();
                sum += a[i-1].y;
                mls.pop();
            }
            a[i].ans = sum + a[i].y;
        // cout <<"sum2 " <<  sum << endl;
        }
    }
    sort(a+1,a+1+n,cmp2);
    rep(i,1,n+1){
        cout << a[i].ans << " ";
    }


    return 0;
}