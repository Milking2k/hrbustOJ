// // #include <bits/stdc++.h>
// #include<iostream>
// #include<cstdio>
// #include<vector>
// #include<cstring>
// #include<assert.h>
// #include<set>
// #include<queue>
// using namespace std;
// #define rep(i,a,n) for (int i = a; i<n; i++)
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
// // head
// const int N = 1e2+7;
// const int M = 45e2+7;
// int T,n,m;

// int head[N],out[N],in[N], ver[M], nxt[M], tot;
// void add(int x, int y)
// {
//     ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
//     out[x]++;
//     in[y]++;
// }

// int ans,vis[N];
// set<int> fa[N];
// void topsort()
// {
//     queue<int> Q;
//     rep(i,1,n+1){
//         if(in[i]==0){
//             Q.push(i);
//             // printf("::%d ",i);
//         }

//     }

//     while(!Q.empty()){
//         int cur = Q.front();Q.pop();
//         // printf("\ncur:%d\n", cur);
//         if(out[cur]+fa[cur].size() >= n) ans++;

//         for (int i = head[cur]; i;i=nxt[i]){
//             int v = ver[i];
//             // printf("%d ", v);
//             if(vis[v]) continue;
//             in[v]--;

//             set<int>::iterator it;
//             for (it=fa[cur].begin(); it != fa[cur].end(); it++)
//                 fa[v].insert(*it);

//             if (in[v] == 0)
//             {
//                 Q.push(v);
//                 vis[v] = 1;
//             }
//         }
//     }
//     printf("%d\n", ans);
// }

// int main()
// {
//     //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     while(~scanf("%d%d",&n,&m)){
//         memset(head, 0, sizeof(head));
//         memset(vis, 0, sizeof(vis));
//         memset(out, 0, sizeof(out));
//         memset(in, 0, sizeof(in));
//         rep(i, 1, n + 1) fa[i].clear();
//         ans = 0, tot = 0;

//         if(n==1){
//             printf("1\n");
//             return 0;
//         }
//         rep(i,1,n+1){
//             fa[i].insert(i);
//         }
//         rep(i,1,m+1){
//             int x,y;
//             scanf("%d%d", &x, &y);
//             add(x, y);
//         }
//         topsort();
//     }
//     return 0;
// }
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxnum=101;
int map[maxnum][maxnum];
int n,m;

void floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j]=map[i][j] || (map[i][k]&&map[k][j]);//判断i和j是否连通
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(map,0,sizeof(map));
    int i,j,u,v;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        map[u][v]=1;
    }
    floyd();
    int ans,res=0;
    for(i=1;i<=n;i++)
    {
        ans=0;
        for(j=1;j<=n;j++)
        {
            if(i==j)    continue;
            else if(map[i][j] || map[j][i])
                ans++;
        }
        if(ans==n-1)//出度+入度=n-1
            res++;
    }
    printf("%d\n",res);
    return 0;
}

cnblogs.com###cnblogs_post_body
cnblogs.com###cnblogs_post_body a