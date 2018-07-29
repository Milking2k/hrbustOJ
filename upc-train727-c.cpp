/*所罗门王的宝藏*/

#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)

using namespace std;
const int N = 1e3+7;
int t,n,m,k;
int t1[N][N],t2[N][N],v1[N][N],v2[N][N];
int x[N],y[N],c[N];

int sub(int i, int j, int tp)
{
    if(tp==0){
        if(y[i]>y[j]) return c[j]-c[i];
        return c[i] - c[j];
    }
    else {
        if(x[i]>x[j]) return c[j]-c[i];
        return c[i]-c[j];
    }
}

bool solve()
{
    rep(i,1,k+1){
        rep(j,i+1,k+1){
            int a1=x[i],a2=x[j],b1=y[i],b2=y[j];

            if(a1==a2 && b1==b2 && c[i]!=c[j]) return 0;
            else if(a1==a2){
                if(v1[ b1 ][ b2 ] && t1[ b1 ][ b2 ]!=sub(i,j,0)) return 0;
                t1[b1][b2]=t1[b2][b1]=sub(i,j,0);
                v1[b1][b2]=v1[b2][b1]=1;
            }
            else if(b1==b2){
                if(v2[ a1 ][ a2 ] && t2[ a1 ][ a2 ]!=sub(i,j,1)) return 0;
                t2[a1][a2]=t2[a2][a1]=sub(i,j,1);
                v2[a1][a2]=v2[a2][a1]=1;
            }
        }
    }

    rep(i,1,n+1) if(t1[i][i]) return 0;
    rep(i,1,m+1) if(t2[i][i]) return 0;

    return 1;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));

        scanf("%d %d %d",&n,&m,&k);
        rep(i,1,k+1){
            scanf("%d%d%d",&x[i],&y[i],&c[i]);
        }

        if(solve())
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

