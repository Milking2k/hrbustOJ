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
const int N = 1e5+7;
int T,n,m;

map<string, int> id;
map<string, string> order;
vector<string> names;
bool cmp(string a, string b){
    if(order[a]==order[b]) return a < b;
    return order[a] > order[b];
}
int main()
{
    id["upper"] = 3 + 48;
    id["middle"] = 2 + 48;
    id["lower"] = 1 + 48;
    while(~scanf("%d",&n))    
    {
        string name;
        rep(i,1,n+1){
            cin >> name;
            name.erase(name.end() - 1);
            names.pb(name);
            string tmp,tmpAns="";
            int len = 0;
            rep(i, 0, 50) tmpAns += 50;
            while(cin>>tmp && tmp[0]!='c'){
                tmpAns[len] = id[tmp];
                len++;
            }
            reverse(tmpAns.begin(), tmpAns.begin() + len);
            order[name] = tmpAns;
        }
        sort(names.begin(), names.end(), cmp);
        for(auto u : names) cout << u << endl;
    }
    return 0;
}