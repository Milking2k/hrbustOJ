// H

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

const int N=1010000;
int stk[N],top,l[N],r[N],vis[N],n,x,_;
PII a[N];
ll inv[N],ret;


int dfs(int u) {
	int s=1;
	if (l[u]) s+=dfs(l[u]);
	if (r[u]) s+=dfs(r[u]);
	ret=ret*inv[s]%mod;
	return s;
}
void build() {
	int top=0;
	rep(i,1,n+1) l[i]=0,r[i]=0,vis[i]=0;
	rep(i,1,n+1) {
		int k=top;
		while (k>0&&a[stk[k-1]]>a[i]) --k;
		if (k) r[stk[k-1]]=i;
		if (k<top) l[i]=stk[k];
		stk[k++]=i;
		top=k;
	}
	rep(i,1,n+1) vis[l[i]]=vis[r[i]]=1;
	int rt=0;
	rep(i,1,n+1) if (vis[i]==0) rt=i;
	dfs(rt);
}

int main() {
	inv[1]=1;
	rep(i,2,1000001) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,1,n+1) {
			scanf("%d",&x);
			a[i]=mp(-x,i);
		}
		ret=inv[2]*n%mod;
		build();
		printf("%lld\n",ret);
	}
}
