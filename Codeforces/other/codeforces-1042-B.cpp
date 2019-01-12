#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
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

const int N = 2e6+7;
int n, m, k;
priority_queue<int, vector<int>, greater<int> > a[10];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    a[1].push(0x3f3f3f3f);// B
    a[2].push(0x3f3f3f3f);// B
    a[3].push(0x3f3f3f3f);// C
    a[4].push(0x3f3f3f3f);// AB
    a[5].push(0x3f3f3f3f);// AC
    a[6].push(0x3f3f3f3f);// BC
    a[7].push(0x3f3f3f3f);// ABC

    cin >> n;
    bool ok1 = 0, ok2 = 0, ok3 = 0;
    rep(i,1,n+1){
        int u;
        char s[10];
        cin >> u >> s;
        int len = strlen(s);
        int cnt = 0;
        rep(j,0,len){
            if(s[j]=='A')
                cnt+=1,ok1 = 1;
            else if(s[j]=='B')
                cnt+=2,ok2 = 1;
            else if(s[j]=='C')
                cnt+=4,ok3 = 1;
        }
        // cout << len << endl;
        if(cnt==1) a[1].push(u);// A
        else if(cnt==2) a[2].push(u);// B
        else if(cnt==4) a[3].push(u);// C
        else if(cnt==3) a[4].push(u);// AB
        else if(cnt==5) a[5].push(u);// AC
        else if(cnt==6) a[6].push(u);// BC
        else if(cnt==7) a[7].push(u);// ABC
    }

    if(ok1==0 || ok2==0||ok3==0){
        cout << "-1";
        return 0;
    }

    ll res = 0x3f3f3f3f;
    res = min(res, 0ll + a[1].top() + a[2].top() + a[3].top());
    // cout << res << endl;
    res = min(res, 0ll + a[1].top() + a[6].top());
    res = min(res, 0ll + a[4].top() + a[6].top());
    res = min(res, 0ll + a[5].top() + a[6].top());
    // cout << res << endl;
    res = min(res, 0ll + a[2].top() + a[5].top());
    res = min(res, 0ll + a[4].top() + a[5].top());
    // cout << res << endl;
    res = min(res, 0ll + a[3].top() + a[4].top());
    // cout << res << endl;
    res = min(res, 0ll + a[7].top());
    cout << res << endl;

    return 0;
}
