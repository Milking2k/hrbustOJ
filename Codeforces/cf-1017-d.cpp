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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 20;
const int S = 5000;
const int X = 2000;
int n,m,q,w[N],f[S],g[S][S],F[S][X],s[S];
char st[N];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 0; i < n; i++)
		scanf("%d",&w[i]);
	for (int i = 0; i < 1 << n; i++)
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) f[i] += w[j];
	for (int i = 1; i <= m; i++){
		scanf("%s",st);
		int x = 0;
		for (int j = 0; j < n; j++)
			if (st[j] == '1')
				x += 1 << j;
		s[x] ++;
	}
	for (int i = 0; i < 1 << n; i++){
		for (int j = 0; j < 1 << n; j++){
			g[i][j] = f[i ^ j ^ ((1 << n) - 1)];
			F[i][g[i][j]] += s[j];
		}
		for (int j = 1; j <= 1200; j++)
			F[i][j] += F[i][j - 1];
	}
	for (int i = 1; i <= q; i++){
		scanf("%s",st);
		int x = 0;
		for (int j = 0; j < n; j++)
			if (st[j] == '1')
				x += 1 << j;
		int k;
		scanf("%d",&k);
		printf("%d\n",F[x][k]);
	}
}
