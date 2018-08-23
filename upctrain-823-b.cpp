#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mp[2][55][55];
int n,m,t,p;
int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&t,&p)){
        if(n==0&&m==0&&t==0&&p==0)break;
        int now=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                mp[now][i][j]=1;
            }
        }
        for(int k=1;k<=t;k++){
            int op,as;
            scanf("%d%d",&op,&as);
            if(op==1){
                bool ok=true;
                if(as > n/2){
//                    printf("test1\n");
                    for(int i=1;i<=m;i++){
                        for(int j=1;j<=n/2;j++){
                            swap(mp[now][i][j],mp[now][i][n-j+1]);
                        }
                    }
                    as=n-as;
                    ok=false;
                }
//                printf("saaaaaaaaaaa %d\n",m);
                for(int i=1;i<=m;i++){
                    for(int j=1;j<=as;j++){
                        mp[now][i][as*2-j+1]+=mp[now][i][j];
                    }
                }
                for(int i=1;i<=m;i++){
                    for(int j=as+1,p=1;j<=n;j++,p++){
                        mp[now^1][i][p]=mp[now][i][j];
                    }
                }
                for(int i=1;i<=m;i++){
                    for(int j=1;j<=n;j++)mp[now][i][j]=1;
                }
                n-=as;
                now^=1;

            }
            else{
                bool ok=true;
                if(as>m/2){
//                    printf("fuck1 \n");
                    for(int i=1;i<=n;i++){
                        for(int j=1;j<=m/2;j++){
                            swap(mp[now][j][i],mp[now][m-j+1][i]);
                        }
                    }
                    as=m-as;ok=false;
                }
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=as;j++){
                        mp[now][as*2+1-j][i]+=mp[now][j][i];
                    }
                }
                for(int i=1;i<=n;i++){
                    for(int j=as+1,p=1;j<=m;j++,p++){
//                        printf("qwe i==%d j==%d p==%d\n",i,j,p);
                        mp[now^1][p][i]=mp[now][j][i];
                    }
                }
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++)mp[now][j][i]=1;
                }
                now^=1;
                m-=as;
            }
        }
        for(int k=1;k<=p;k++){
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            printf("%lld\n",mp[now][y][x]);
        }
    }
    return 0;
}
