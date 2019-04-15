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
int A, B, C;
int vis[107][107], dis[107][107];
int bfs()
{
    queue<PII> q;
    q.push(mp(0,0));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    while(!q.empty()) {
        PII temp = q.front();
        q.pop();
        rep(i,1,6+1) {
            int x = temp.first, y=temp.second;
            switch (i)
            {
                case 1:
                    y = B; // 倒满B
                    break;
                case 2:
                    x = A;// 倒满A
                    break;
                case 3:
                    y = 0;// 倒光B
                    break;
                case 4:
                    x = 0;// 倒光A
                    break;
                case 5:
                    if(x + y > B){
                        x = x + y - B;
                        y = B;
                    }
                    else {
                        y = x + y;
                        x = 0;
                    } // A到B
                    break;
                case 6:
                    if(x + y > A){
                        y = x + y - A;
                        x = A;
                    }
                    else {
                        x = x + y;
                        y = 0;
                    } // A到B
                    break;
            }
            if(!vis[x][y]){
                vis[x][y] = 1;
                dis[x][y] = dis[temp.first][temp.second] + 1;
                if(x==C || y==C)
                    return dis[x][y];
                q.push(mp(x, y));
            }
            
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin>> A>>B>>C) 
    {
        
        int ans = bfs();
        if(ans == -1){
            printf("impossible\n");
        }
        else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
/*

*/