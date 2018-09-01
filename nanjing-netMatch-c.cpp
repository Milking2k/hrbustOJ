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
const int N = 2e2+7;
int T,n,m;
int a[N];

multiset<int> player[N];

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (cin >> T; T;T--){
        cin >> n >> m;
        rep(i,0,n){
            player[i].clear();
            rep(j,1,6){
                int x;
                cin >> x;
                if(x==1)
                    x = 14;
                else if(x==2)
                    x = 15;
                player[i].insert(x);
            }
        }

        int cnt = *player[0].begin();
        player[0].erase(player[0].begin());

        int pos = 1, noresponse = 0;
        int winner = 0x3f3f3f3f;
        printf("test%d\n", *player[0].end());
        while(1){
            printf("player:%d sz:%d\n", pos, player[pos].size());
            printf("cnt:%d\n", cnt);
            if(noresponse==n-1){
                auto now = player[pos].begin();
                player[pos].erase(now);
                if(player[pos].size()==0){
                    winner = pos;
                    break;
                }
                cnt = *now;
                pos = (pos + 1) % n;
                noresponse = 0;
                continue;
            }
            auto now = player[pos].find(cnt+1);
            if(now == player[pos].end()){
                if(player[pos].find(15)==player[pos].end()){
                    noresponse++;
                }
                else{
                    player[pos].erase(player[pos].end());
                    if(player[pos].size()==0){
                        winner = pos;
                        break;
                    }
                    cnt = 15;
                    noresponse = n - 1;
                }
            }
            else{
                player[pos].erase(now);
                if(player[pos].size()==0){
                    winner = pos;
                    break;
                }
                cnt = *now;
                noresponse = 0;
            }
            pos = (pos+1)%n;
        }
        rep(i,0,n){
            if(i == winner)
                printf("Winner\n");
            else{
                int ans = 0;
                printf("a:%d\n",player[i].size());
                while(player[i].size()){
                    auto now = player[i].begin();
                    player[i].erase(now);
                    if(*now > 13)
                        ans += (*now - 13);
                    else
                        ans += *now;
                }
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}