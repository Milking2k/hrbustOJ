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
const int N = 50+7;
int T,n,m;
int a[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int x, y;
    while (cin >> x >> y) {
        memset(a, 0, sizeof(a));
        cin >> n;
        rep(i,1,n+1) {
            char ch[20];
            scanf("%s", ch);
            if(ch[0]=='L') a[i] = 1;
            else if(ch[0]=='R') a[i] = 2;
            else a[i] = 3;
        }
        vector<const char*> i2s{"", "Left", "Right", "Forward", ""};
        int dir = 0;// 0=up, 1=right, 2=down, 3=left
        PII FD[4] = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};
        bool ok = 0;
        rep(i,1,n+1) {
            // int i = 8;
            rep(j,1,4) {
                PII cur(0, 0);
                rep(k,1,n+1){
                    int temp = a[k];
                    if(k==i) temp = j;
                    if (temp == 1) {
                        dir = (dir - 1 + 4) % 4;
                    }
                    else if(temp == 2) {
                        dir = (dir + 1) % 4;
                    }
                    else {
                        cur.first += FD[dir].first;
                        cur.second += FD[dir].second;
                    }
                }
                // printf("i:%d j:%d :: %d %d\n", i, j, cur.first, cur.second);
                if(cur.first == x && cur.second == y){
                    cout << i << " " << i2s[j] << endl;
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
    }
    return 0;
}
/*

*/