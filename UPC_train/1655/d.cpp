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
    cin >>n ;
    string a;
    rep(i,1,n+1 ) {
        cin >> a;
        int len = a.length();
        if(len >= 2 && a[len-2] == 'n' && a[len-1]=='e'){
            a.pop_back();
            a.pop_back();
            a += "anes";
            cout << a << endl;
            continue;
        }
        switch (a[len-1])
        {
            case 'a':
            case 'o':
            case 'u':
                a.push_back('s');
                break;
            case 'i':
            case 'y':
                a.pop_back();
                a.append("ios");
                break;
            case 'l':
            case 'v':
            case 'r':
                a.append("es");
                break;
            case 'n':
                a.pop_back();
                a.append("anes");
                break;
            case 't':
            case 'w':
                    a.append("as");
                    break;
            default:
                a.append("us");
                break;
        }
        cout << a << endl;
    }

    return 0;
}
/*

*/