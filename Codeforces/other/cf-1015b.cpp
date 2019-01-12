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

const int N = 107;
int n,m,k;
char s[N];
char t[N];
vector <int> ans;

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",t+1);

    for (int i = 1; i <= n; i++){
		int x = i;
		while (x <= n && s[x] != t[i])
			x++;
		if (x > n){
			printf("-1\n");
			return 0;
		}
		for (int j = x - 1; j >= i; j--){
			ans.push_back(j);
			swap(s[j],s[j + 1]);
		}
	}
	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ",ans[i]);
	printf("\n");



    return 0;
}

