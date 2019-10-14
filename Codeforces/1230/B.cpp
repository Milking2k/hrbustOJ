/*
 * @Project:
 * @Model:
 * @Description:
 * @Author: Jelech Fensi
 * @Date: 2019-09-24 15:22:43
 * @LastEditors: Jelech Fensi
 * @LastEditTime: 2019-09-24 18:07:27
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
    string s;
    cin >> n >> m;
    cin >> s;

    if (n == 1) {
        if (m > 0) {
            cout << 0 << endl;
        }
        else {
            cout << s << endl;
        }
        return 0;
    }
    if (m == 0){
        cout << s << endl;
        return 0;
    }


    if (s[0] != '1') {
        m--;
        s[0] = '1';
    }

    rep (i,1,m+1) {
        if (i > n) break;
        if (s[i] == '0')
            m++;
        s[i] = '0';
    }
    cout << s << endl;

    return 0;
}