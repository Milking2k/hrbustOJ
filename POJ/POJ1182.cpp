// #include <bits/stdc++.h>
// using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
// #define per(i,a,n) for (int i = n-1; i>=a; i--)
// #define pb push_back
// #define mp make_pair
// #define all(now) (now).begin(),(now).end()
// #define fi first
// #define se second
// #define SZ(now) ((int)(now).size())
// typedef vector<int> VI;
// typedef long long ll;
// typedef pair<int,int> PII;
// const ll mod = 1000000007;
// inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
// ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
// ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
#include<iostream>
#include<cstdio>
using namespace std;
// head
const int N = 5e4+7;
int T,n,m,k;
int a[N];
int ans = 0;
int op, x, y;

struct node
{
    int fa, relation;
} p[N];

int find(int x)
{
    if(x == p[x].fa) return x;
    int temp = find(p[x].fa);
    p[x].fa = find(temp);
    p[x].relation = (p[x].relation + p[temp].relation) % 3;
    return p[x].fa;
}

void init()
{
    rep(i, 1, n + 1)
    {
        p[i].fa = i;
        p[i].relation = 0;
    }
}
void merge(int x, int y, int ope)
{
    int root1 = find(x);
    int root2 = find(y);
    if ((ope==2 && x == y) || x > n || y > n 
        || (root1==root2 && ope==2 && (3 - p[x].relation + p[y].relation) % 3 != 1) 
        || (root1==root2 && ope==1 && (p[x].relation != p[y].relation)) )
    {
        ans++;
    }
    else if (root1 != root2)
    {
        p[root2].fa = root1;
        p[root2].relation = (3 + (ope - 1) + p[x].relation - p[y].relation) % 3;
    }
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    scanf("%d%d", &n, &k);
    
        ans = 0;
        init();

        rep(i, 1, k + 1)
        {
            scanf("%d%d%d", &op, &x, &y);
            merge(x,y,op);
        }

        printf("%d\n", ans);
    
    return 0;
}