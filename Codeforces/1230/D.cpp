/*
 * @Project:
 * @Model:
 * @Description:
 * @Author: Jelech Fensi
 * @Date: 2019-09-24 17:14:33
 * @LastEditors: Jelech Fensi
 * @LastEditTime: 2019-09-24 17:55:42
 */
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
ll a[N];
int b[N];
map<ll, pair<int,ll> > hasBanlance;

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    set<ll> single, more;
    rep(i, 1, n + 1)
    {
        cin >> a[i];
        hasBanlance[a[i]] = {0, 0};
    }
    rep(i, 1, n + 1) {
        cin >> b[i];
        hasBanlance[a[i]].first++;
        hasBanlance[a[i]].second += b[i];
    }

    ll ans = 0;
    for(auto p:hasBanlance)if (p.second.first > 1){
        ans += p.second.second;
    }

    rep(i,1,n+1) {
        if (hasBanlance[a[i]].first > 1){
            more.insert(a[i]);
        }
        else
            single.insert(a[i]);
    }
    for(auto c_1:more){
        for (auto c_2:single) {
            // cout << c_1 << " " << c_2 << endl;
            if (((c_1^c_2) & c_2) == 0 && hasBanlance[c_2].first != -1) {
                ans += hasBanlance[c_2].second;
                hasBanlance[c_2].first = -1;
            }
        }
    }

    cout << ans << endl;


    return 0;
}