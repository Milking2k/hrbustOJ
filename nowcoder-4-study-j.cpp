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
const ll MOD = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;
int T,n,m,k,flag,t,num,cnt;
int a[N],fa[N],ans[N],vis[N];

priority_queue<PII> q;

int getfa(int x){
    if(fa[x] != x) return fa[x] = getfa(fa[x]);
    return x;
}

int main()
{
    for(read(T);T;T--){
        flag = 0;
        num = 0;
        cnt = 0;
        t = 0;
        read(n);
        rep(i,0,n){
            read(a[i]);
            cnt += (a[i] != -1);

            fa[i] = i;
            vis[i] = 0;
            if(a[i]%n == i && a[i]!=-1){
                q.push(mp(-a[i], -i));
                vis[i] = 1;
            }
            
        }

        while(!q.empty()){
            PII now = q.top();
            q.pop();
            ans[t++] = now.fi;
            int x = -now.fi, id = -now.se;
            num++;
            int ne = getfa((id+1)%n);
            fa[id] = ne;
            if(!vis[ne] && getfa(id) == getfa(a[ne]%n)){
                vis[ne] = 1;
                if(a[ne]!=-1){
                    q.push(mp(-a[ne], -ne));
                }
            }
        }
        
        if(num < cnt) puts("-1");
        else {
            rep(i,0,num){
                printf(i == num - 1 ? "%d\n" : "%d ", -ans[i]);
            }
        }
    }
    return 0;
}