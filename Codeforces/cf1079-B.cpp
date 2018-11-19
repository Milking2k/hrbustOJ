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
const int N = 1e3+7;
int T,n,m;
int a[N][N];
int pre[20];
string s;
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> s;
    int len = s.length();
    rep(i, 1, 20) pre[i] = pre[i - 1] + i;
    if(len<=20){
        printf("1 %d\n", len);
        cout << s;
        return 0;
    }
    for (int i = 2; i * i <= len;i++){
        int cnt = len / i + (len % i != 0);
        if (cnt <= 20 && cnt * i - len <= pre[i-1]) {
            printf("%d %d\n", i,cnt);
            int bookLen = cnt * i - len;
            for (int j = 0; j < cnt && bookLen;j++)
                for (int k = 0; k < i && bookLen;k++){
                    bookLen--;
                    a[k][j] = '*';
            }

            int tot = 0;
            rep(k, 0, i) rep(j, 0, cnt)
            {
                if (a[k][j]){
                    printf("%c", a[k][j]);
                } else{
                    printf("%c",s[tot]);
                    tot++;
                }
                if(j==cnt-1)
                    puts("");
            }
            return 0;
        }
    }
        return 0;
}