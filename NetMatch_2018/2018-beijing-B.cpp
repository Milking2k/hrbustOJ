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

set<string> st[11];
string t,ans;
int len;
void dfs(int i,int cur)
{
    if(cur == len) {
        if(ans == "") return;
        st[i].insert(ans);
        int _len = ans.length();
        for(int j = 1; j < _len; j++) {
            st[i].insert(ans.substr(j,len - j) + ans.substr(0,j));
        }
        return;
    }
    for(int j = 0; j <= 1; j++) {
        if(j == 0) ans.push_back(t[cur]);
        dfs(i,cur + 1);
        if(j == 0) ans.erase(ans.end() - 1);
    }
}
int main(void)
{
    int n;
    while(scanf("%d",&n) != EOF) {
        for(int i = 0; i < n; i++) {
            st[i].clear();
        }
        for(int i = 0; i < n; i++) {
            cin >> t;
            len = t.length();
            dfs(i,0);
        }
        set<string>::iterator it;
        string ans = "0";
        int flag;
        for(it = st[0].begin(); it != st[0].end(); it++) {
            t = *it;
            flag = 0;
            for(int i = 1; i < n; i++) {
                if(!st[i].count(t)) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                if(ans == "0") {
                    ans = t;
                }
                else if(t.length() > ans.length()) {
                    ans = t;
                }
                else if(t.length() == ans.length() && ans > t) {
                    ans = t;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
