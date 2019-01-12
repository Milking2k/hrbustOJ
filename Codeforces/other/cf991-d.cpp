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
int a[1007];
char s[2][1007];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> s[0];
    cin >> s[1];
    int len = strlen(s[0]);
    rep(i,0,len){
        if(s[0][i]=='0' && s[1][i]=='0')
            a[i] = 2;
        else if(s[0][i]!='0' && s[1][i]!='0')
            a[i] = 0;
        else
            a[i] = 1;
        // cout << a[i] << " ";
    }
    // cout << endl;

    int i = 0, j = 1;
    int ans = 0;
    while(i<len && j<len){
        // cout << i << " " << j << endl;
        if(a[i]*a[j]==2){
            ans++;
            i += 2;
            j += 2;
        }
        else if(a[i]*a[j]==4){
            j++;
            ans++;
            if(a[i]*a[j]==4){
                ans++;
                i += 3;
                j += 2;
            }
            else{
                i += 2;
                j += 1;
            }
        }
        else{
            i++, j++;
        }
    }

    cout << ans;

    return 0;
}