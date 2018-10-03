#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int N = 27;
int T,a,b,c,d;
struct mat
{
    ll a[N][N];
    int col,row;
};
mat operator*(mat s,mat t)
{
    ll x;
    int row = s.row;
    int col = t.col;
    int col2 = s.col;
    mat r;
    r.col = col;
    r.row = row;
    memset(r.a,0,sizeof(r.a));
    for(int i=1; i<=row; i++)
        for(int j=1; j<=col; j++)
        {
            x=0;
            for(int k=1; k<=col2; k++)
                x+=(s.a[i][k]*t.a[k][j]);
            r.a[i][j]=x;
        }
    return r;
}

int main()
{
    int Cas=0;
    while(~scanf("%d%d%d%d",&a,&b,&c,&d) && a && b && c && d){
        mat ans1,ans2;
        ans1.row = a;
        ans1.col = b;
        ans2.row = c;
        ans2.col = d;
        rep(i,1,a+1)rep(j,1,b+1){
            scanf("%d",&ans1.a[i][j]);
        }
        rep(i,1,c+1)rep(j,1,d+1){
            scanf("%d",&ans2.a[i][j]);
        }
        if(b!=c){
            printf("Case #%d:\nundefined\n",++Cas);
        }
        else{
            printf("Case #%d:\n",++Cas);
            mat ans = ans1*ans2;
            int row = ans1.row;
            int col = ans2.col;
            rep(i,1,row+1){
                printf("| ");
                rep(j,1,col+1){
                    printf("%d ",ans.a[i][j]);
                }
                printf("|\n");
            }
        }

    }

    return 0;
}

