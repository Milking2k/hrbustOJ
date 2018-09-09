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

const int N = 2e5+7;
int n,m,k;
char st[N];
stack<char> s;
stack<char> ans;
int a[N];
int main()
{
    read(n),read(m);
    scanf("%s",st);
    m /= 2;
//    printf("mm:%d\n",m);
    int j=0;
    int flag = 0;
    rep(i,0,n){
//        printf("%c %d\n",st[i],j);
        if(j<m && st[i]=='(') s.push(st[i]),j++;
        else if(j<m) s.push(st[i]);
        else if(j>=m && st[i]=='(') s.push(st[i]),flag++;
        else if(j>=m && st[i]==')' && flag) s.pop(),flag--;
        else s.push(st[i]);
//        printf("stop:%c\n",s.top());
    }
    while(s.size()){
        ans.push(s.top());
//        printf("%c",s.top());
        s.pop();
    }
//    puts("");
    while(ans.size()){
        printf("%c",ans.top());
        ans.pop();
    }
    return 0;
}
