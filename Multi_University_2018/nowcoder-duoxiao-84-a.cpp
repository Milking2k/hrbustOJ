#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi head
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e5+7;

int t,n,m;
int a[N][20];

queue<int> que;

int main()
{
    //memset()

    scanf("%d",&t);
    int Cas=1;
    while(t--) {
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    m = powmod(2,n);
    rep(i,1,m+1){
        que.push(i);
        rep(j,1,n+1){
            scanf("%d",&a[i][j]);
        }
        sort(a[i]+1, a[i]+1+n);
    }

    int now1,now2;
    while(que.size() != 1){
        now1 = que.front();que.pop();
        now2 = que.front();que.pop();
        int max1=-1;
        int max2=-1;
        for(int i=1;i<=16;i++) {
            max1=max(max1,a[now1][i]);
        }
        for(int i=1;i<=16;i++) {
            max2=max(max2,a[now2][i]);
        }
        if(max1>max2) {
            int temp;
            for(int i=1;i<=16;i++) {
                if(a[now1][i]>max2) {
                    a[now1][i]=-1;
                    break;
                }
            }
            que.push(now1);
        }
        else {
            for(int i=1;i<=16;i++) {
                if(a[now2][i]>max1) {
                    a[now2][i]=-1;
                    break;
                }
            }
            que.push(now2);
        }
    }
    int f=que.front();
    que.pop();
    printf("Case #%d: %d\n",Cas++,f);
    }
    return 0;
}
