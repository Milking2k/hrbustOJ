#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)

const int maxn=1055;
int ans[maxn][maxn];
int T,n,m;
void dfs(int x)
{
    if(x==2){
        return ;
    }
    dfs(x/2);
    int as=x/2;
    for(int k=1;k<=as;k++){
        for(int i=as+1,j=1;j<=as;i++,j++){
            ans[k][i]=ans[k][j]+as;
        }
    }
    for(int p=1,q=as+1;p<=as;p++,q++){
        for(int i=1,j=as+1;i<=as;i++,j++){
            ans[q][i]=ans[p][j];
        }
    }
    for(int p=1,q=as+1;p<=as;p++,q++){
        for(int i=1,j=as+1;i<=as;i++,j++){
            ans[q][j]=ans[p][i];
        }
    }
}
int main()
{
    ans[1][1]=1;ans[1][2]=2;
    ans[2][1]=2;ans[2][2]=1;
    dfs(1024);
//    for(int i=1;i<=16;i++){
//        for(int j=1;j<=16;j++){
//            printf("%3d",ans[i][j]);
//        }
//        puts("");
//    }
    for(scanf("%d",&T);T;T--){
        scanf("%d%d",&n,&m);
        int cnt=0;
        int as=n;
        int res=0;
        while(as){
            if(as&1){res|=(1<<cnt);break;}
            cnt++;as/=2;
        }
        if(res-1>=m && n%2!=1){
            rep(i,2,m+2) rep(j,1,n+1){
                printf("%d",ans[i][j]);
                if(j==n)printf("\n");
                else printf(" ");
            }
        }
        else{
            printf("Impossible\n");
        }

    }
    return 0;
}