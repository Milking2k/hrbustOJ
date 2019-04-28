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
int a[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >>n;
    string s;
    cin >> s;
    rep(i,0,n){
        cin >> a[i];
    }
    vector<pair<ll,ll>> as[5],ans1[5],ans2[5],ans3[5];

    rep(i,0,n){
        if(s[i] == 'h'){
            as[0].pb(mp(i, a[i]));
        }
        else if(s[i] == 'a'){
            if(as[0].size() > 0) {
                while(as[0].size()){
                    ans1[0].pb(as[0].back());
                    as[0].pop_back();
                }
                ans1[1].pb(mp(i, a[i]));
            }
            else if(ans1[0].size() > 0){
                ans1[1].pb(mp(i, a[i]));
            }
        }
        else if(s[i] == 'r') {
            if(ans1[0].size() > 0 && ans1[1].size() > 0) {
                while (ans1[0].size())
                {
                    ans2[0].pb(ans1[0].back());
                    ans1[0].pop_back();
                }
                while(ans1[1].size()){
                    ans2[1].pb(ans1[1].back());
                    ans1[1].pop_back();
                }
                ans2[2].pb(mp(i, a[i]));
            }
            else if(ans2[0].size() > 0 && ans2[1].size() > 0){
                ans2[2].pb(mp(i, a[i]));
            }
        }
        else if(s[i] == 'd'){
            if (ans2[0].size() > 0 && ans2[0].size() > 0 && ans2[0].size() > 0){
                while(ans2[0].size()){
                    ans3[0].pb(ans2[0].back());
                    ans2[0].pop_back();
                }
                while(ans2[1].size()){
                    ans3[1].pb(ans2[1].back());
                    ans2[1].pop_back();
                }
                while(ans2[2].size()){
                    ans3[2].pb(ans2[2].back());
                    ans2[2].pop_back();
                }
                ans3[3].pb(mp(i, a[i]));
            }
            else if(ans3[0].size() > 0 && ans3[1].size() > 0 && ans3[2].size() > 0){
                ans3[3].pb(mp(i, a[i]));
            }
        }
    }

    ll ret = 0x3f3f3f3f3f3f3f3f;
    rep(i,0,4){
        ll cur = 0;
        // printf("debug:");
        for(auto x:ans3[i]){
            // printf("%d ", x.second);
            cur += x.second;
        }
        // puts("");
        ret = min(ret, cur);
    }
    printf("%lld\n", ret);

    return 0;
}
/*

*/