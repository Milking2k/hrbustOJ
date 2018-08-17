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
int T,n,m,k;
int a[N];
char s1[N],s2[N];
queue<char> op;

int solve()
{
    int res = 0;
    int cnt = 0;
    while(op.size()){
        char ch = op.front();op.pop();
        if(ch == '*') cnt++,res=max(res, cnt);
        else if(ch == '('){
            solve();
        }
        else if(ch == ')') return res;
        else if(ch == '+') {
            res = max(cnt, res);
        }
    }
}

int main()
{
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    rep(i,1,len1+1){
        if(s[i]!='x'){
            if(i>1 && s[i]=='(' && s[i-1] =='+')
                continue;
            else
                op.push(s[i]);
        }
    }
    int cnt = solve();
    printf("%d\n",cnt);
    return 0;
}
