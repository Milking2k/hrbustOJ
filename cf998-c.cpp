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
int T,n,m,k;
char a[N];

int main()
{
    int x,y;
    read(n,x,y);
    char cnt;
    int pos=0;
    a[0] = 'a';
    m = n;
    while(scanf("%c",&cnt) && n--){
        if(a[pos]==cnt) continue;
        else{
            a[++pos] = cnt;
        }
    }
    ll num0=0,num1=0;
    rep(i,0,pos+1){
        if(a[i]=='0') num0++;
        else if(a[i]=='1') num1++;
    }

    if(m<=1){
        if(a[1]=='0')cout<<y;
        else cout << 0;
        return 0;
    }
    else if(pos==0){
        cout << 0;
        return 0;
    }

    if(a[1]=='1')num1--;
    if(a[pos]=='1')num1--;
    // cout<< a[1] << "_" << a[pos] <<endl;
    num0 = max(0ll, num0);
    num1 = max(0ll, num1);
    ll ans = min(num0*y, num1*x+y);
    cout << ans << endl;

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

const int N = 1e6+7;
int T,n,m,k;
char a[N];

int main()
{
    int x,y;
    read(n,x,y);
    char cnt;
    int pos=0;
    a[0] = 'a';
    m = n;
    while(scanf("%c",&cnt) && n--){
        if(a[pos]==cnt) continue;
        else{
            a[++pos] = cnt;
        }
    }
    ll num0=0,num1=0;
    rep(i,0,pos+1){
        if(a[i]=='0') num0++;
        else if(a[i]=='1') num1++;
    }

    if(m<=1){
        if(a[1]=='0')cout<<y;
        else cout << 0;
        return 0;
    }
    else if(pos==0){
        cout << 0;
        return 0;
    }

    if(a[1]=='1')num1--;
    if(a[pos]=='1')num1--;
    // cout<< a[1] << "_" << a[pos] <<endl;
    num0 = max(0ll, num0);
    num1 = max(0ll, num1);
    ll ans = min(num0*y, num1*x+y);
    cout << ans << endl;

    return 0;
>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
}