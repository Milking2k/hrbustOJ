#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
typedef long long ll;
const int N = 1e4+7;
int T,n,m,k;
const int V = 200;
bool c[V][V];//edge
int x[V];
bool flag[V];
bool vis[V];

void hamilton()
{
    rep(i,0,n){
        x[i] = -1,vis[i] = false;
    }
    int k = 1;
    vis[0] = true;
    x[0] = 0;
    while(k >= 0){
        x[k]++;
        while(x[k] < n){
            if(!vis[x[k]] && c[x[k - 1]][x[k]])
                break;
            else
                x[k]++;
        }
        if((x[k] < n) && (k != n - 1)){
            vis[x[k]] = true;
            k++;
        }
        else if((x[k] < n) && k == n - 1 && c[x[k]][x[0]]){
            break;
        }
        else{
            x[k] = -1;
            k--;
            vis[x[k]] = false;
        }
    }
}

int main()
{
    for(scanf("%d",&T);T;T--){
        scanf("%d%d%d",&m,&n,&k);
        memset(c,0,sizeof(c));
        memset(flag,0,sizeof(flag));
        if(k==3){
            printf("1\n");
            rep(i,0,n){
                rep(j,0,m-1){
                    printf("(%d,%d)\n",i,j);
                }
            }
            per(i,0,n){
                printf("(%d,%d)\n",i,m-1);
            }
            continue;
        }
        else if(k==6){
            if()
        }

        rep(i,0,n*m)rep(j,0,n*m){
            printf(j==n*m-1?"%d\n":"%d ",c[i][j]);
        }

        hamilton();

        bool f = false;
        rep(i,0,n){
            flag[x[i]]=1;
        }
        rep(i,0,n){
            if(!flag[i]) f=1;
        }
        if(f) printf("-1\n");
        else{
            printf("1\n");
            rep(i,0,n*m){
                printf("(%d,%d)\n",x[i]/n,x[i]%n);
            }
        }
    }

    return 0;
}
/*
10
4 3 3
4 2 6

*/
