//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
//typedef vector<int> VI;
//typedef pair<int,int> PII;
typedef long long ll;
const ll mod = 1000000007;
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
//ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e5+7;
int T,n,m,k,s;
int a[N];
ll sum[N];
int main()
{
    for(scanf("%d",&T);T;T--){
        scanf("%d %d",&n,&s);
        rep(i,1,n+1){
            scanf("%d",a+i);
            sum[i] = sum[i-1] + a[i];
        }

        int j=0;
        int ans = n;
        rep(i,1,n+1){
            j = max(i,j);
            while(j<=n && sum[j] - sum[i-1] < s) j++;
            if(j>n && sum[j-1] - sum[i-1] < s) break;
            ans = min(ans, j-i+1);
        }
        if(ans==n)printf("0\n");
        else printf("%d\n",ans);
    }

    return 0;
}
