/*
 * @Project:
 * @Model:
 * @Description:
 * @Author: Jelech Fensi
 * @Date: 2019-09-24 15:58:19
 * @LastEditors: Jelech Fensi
 * @LastEditTime: 2019-09-24 16:25:32
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
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    vector<vector<bool>> edge(10, vector<bool>(10, false));
    cin >> n >> m;
    rep(i,1,m+1) {
        int u, v;
        cin >> u >> v;
        edge[u][v] = true;
        edge[v][u] = true;
    }
    if (n == 6) {
        cout << m << endl;
    }
    else {
        int ans = 10000;
        rep(i,1,7+1) rep(j,1,7+1) {
            int count = 0;
            rep(k,1,7+1) {
                if(edge[i][k] && edge[j][k]) count ++;
            }
            ans = min(ans, count);
        }
        cout << m - ans << endl;
    }

    return 0;
}