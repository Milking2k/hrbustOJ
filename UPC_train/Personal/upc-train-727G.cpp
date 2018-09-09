#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=5010;
int n,k,d,u,v,g[N][N],p[N];
VI e[N];

void dfs(int u,int f,int r) { // dfs�����뵱ǰ�����ģ����е�ľ���
    for (auto v:e[u]) if (v!=f) {
        g[v][r]=g[u][r]+1;
        dfs(v,u,r);
    }
}
int solve(int d) {
    rep(i,1,n+1) p[i]=i;
    sort(p+1,p+n+1,[&](int x,int y) { return g[1][x]<g[1][y];});
//    rep(i,1,n+1){
//        printf(i==n?"%d\n":"%d ",p[i]);
//    }
    ll ans=1;
    rep(i,1,n+1) {
        int u=p[i];
        int gg=0;
        rep(j,1,i) if (g[p[i]][p[j]]<d) gg++;
//        printf("%d\n",gg);
        if (gg>=k) return 0;
        else ans=ans*(k-gg)%mod;
    }
    return ans;
}

int main() {
    scanf("%d%d%d",&n,&k,&d);
    rep(i,1,n) {
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    rep(i,1,n+1) dfs(i,0,i);
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            printf("%d ",g[i][j]);
//        }
//        puts("");
//    }
    int ans=(solve(d)-solve(d+1))%mod;
    if (ans<0) ans+=mod;
    printf("%d\n",ans);
}
//
//7.26-7.27�ܽ�-���⣨CEGI��
//1.��������������⣨C�����Գ���ʹ��3�η�ת������������������޹ص������ת��Ϊ�ַ�������������rope<int>����
//2.�����E���������ʹ��hash����һֱ���������������ʹ����һ����ѭ���ڽ����
//3.G����һ������Ⱦɫ���⡣һ��ʼ�ͷ����ˡ���ʵ�������ر��ѣ�ת��һ��˼ά���ܺ�������⵽��
//
