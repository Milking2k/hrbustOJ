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
const int N = 1e6+7;
int T,n,m;
vector<ll> vnums, onums;
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    n = s.length();

    ll vnum = 0, onum = 0;
    bool flag = false;
    for (size_t i = 1; i <= n; ++i) {
        if (s[i] == s[i - 1]) {
            if (s[i] == 'o') {
                if (!flag) continue;
                onum++, vnum = 0;
            }
            else {
                flag = true;
                vnum++;
                if (onum) onums.push_back(onum), onum = 0;
            }
        }
        else {
            if (s[i] == 'o') {
                if (!flag) continue;
                onum++;
                if (vnum) vnums.push_back(vnum), vnum = 0;
            }
        }
    }
    if (onum) onums.push_back(onum), onum = 0;
    if (vnum) vnums.push_back(vnum), vnum = 0;

    ll ans = 0;
    ll vnumSum = 0;
    for (auto num:vnums) {
        vnumSum += num;
    }
    ll tempSum = vnumSum;
    m = onums.size();
    // printf("%d %d %lld\n",vnums.size(), m, tempSum);
    for (size_t i = 0; i < m; ++i) {
        if (i < vnums.size())
            tempSum -= vnums[i];
        ans += (vnumSum - tempSum) * onums[i] * tempSum;
    }

    printf("%lld\n", ans);
    return 0;
}