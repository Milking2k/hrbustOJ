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

const int N = 2e2+7;
struct P
{
    ll min, max;   
};
int T, n, m, k;
char s[N];

P operator+(const P &x, const P &y){
    return {x.min + y.min, x.max + y.max};
}
P operator-(const P &x, const P &y){
    return {x.min - y.max, x.max - y.min};
}
P operator*(const P &x, const P &y){
    vector<ll> s = {x.min * y.min, x.max * y.max, x.min * y.max, x.max * y.min};
    return {*min_element(s.begin(), s.end()), *max_element(s.begin(), s.end())};
}

P expression(int &i);
P term(int &i);
P power(int &i);
P number(int &i);
P digit(int &i);

P expression(int &i)
{
    P res = term(i);
    while(i<n){
        if(s[i] == '+'){
            i++;
            res = res + term(i);
        }
        else if(s[i] == '-'){
            i++;
            res = res - term(i);
        }
        else
            break;
    }
    return res;
}

P term(int &i)
{
    P res = power(i);
    while(i<n){
        if(s[i]=='*'){
            i++;
            res = res * power(i);
        }
        else
            break;
    }
    return res;
}
P power(int &i)
{
    P res = number(i);
    if(i<n && s[i]=='d'){
        i++;
        P t = power(i);
        t.min = 1;
        res = res * t;
    }
    return res;
}
P number(int &i){
    if(s[i]=='('){
        i++;
        P res = expression(i);
        assert(s[i] == ')');
        i++;
        return res;
    }
    return digit(i);
}

P digit(int &i)
{
    ll r = 0;
    while(i<n && isdigit(s[i])){
        r = r * 10 + s[i] - '0';
        i++;
    }
    return {r, r};
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while (cin >> s){
        n = strlen(s);
        int pos = 0;
        auto ans = expression(pos);
        cout << ans.min << " " << ans.max << "\n";
    }
    return 0;
}

/*

*/
