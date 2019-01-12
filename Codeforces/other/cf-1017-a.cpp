
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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e3+7;

struct node
{
    int val,pos;
}sum[N];

bool cmp(node a, node b)
{
    if(a.val==b.val) return a.pos < b.pos;
    return a.val > b.val;
}

int main()
{
    int n;
    scanf("%d",&n);
    rep(i,1,n+1){
        sum[i].pos = i;
        sum[i].val = 0;
        rep(j,1,5){
            int x;
            scanf("%d",&x);
            sum[i].val += x;
        }
    }

    sort(sum+1,sum+1+n,cmp);
    rep(i,1,n+1){
        if(sum[i].pos == 1){
            printf("%d\n",i);
            break;
        }
    }

    return 0;
}





