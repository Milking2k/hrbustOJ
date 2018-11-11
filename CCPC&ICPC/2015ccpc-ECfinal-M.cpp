#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=1007;
int mp[maxn][maxn];
int n,m;
int ansx,ansy;
int stk[maxn],top;
void aaa(int x)
{
    ansx+=(x+1)/2;
    ansy+=(x+1)/3;
    if((x+1)%3==2){
        ansy++;
    }
}
void bbb(int x)
{
    ansx+=x/2;
    ansy+=(x+1)/3;
    if((x+1)%3==2){
        ansy++;
    }
}
void solve(int x)
{
    top=0;
    int cnt=0;
    int i=1;
    while(mp[x][i])i++;
    for(;i<=m;i++){
        if(i==m){
            if(mp[x][i]==0)cnt++;
            stk[++top]=cnt;
            break;
        }
        if(mp[x][i]){
            stk[++top]=cnt;
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    for(int i=1;i<=top;i++){
        if(stk[i]==1){
            ansx++;ansy++;
            continue;
        }
        if(stk[i]&1)aaa(stk[i]);
        else bbb(stk[i]);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--){
        scanf("%d%d",&n,&m);
        ansx=0;ansy=0;
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                mp[i][j]=0;
            }
        }
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u++;v++;
            mp[u][v]++;
        }
        for(int i=1;i<=n;i++){
            solve(i);
        }
        printf("Case #%d: %d %d\n",cas++,ansx,ansy);
    }
    return 0;
}
/*
3
2 3
1
0 1

2 3
0

1 1
1
0 0
*/