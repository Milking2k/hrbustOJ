#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+7;
const int MOD = 1e9+7;

int t,n,m;
int emt[50007];
int c[50007][11][11];
void update(int x, int k, int add, int mod)
{
    while(x>0){
        c[x][k][mod] += add;
        x -= x&(-x);
    }
}
int sum(int x, int a)
{
    int res=0;
    while(x<50007){
        for(int i=1;i<11;i++){
            res += c[x][i][a%i];
        }
        x += x&(-x);
    }
    return res;
}

int main()
{
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&emt[i]);
        }
        memset(c,0,sizeof(c));
        scanf("%d",&m);

        for(int i=1;i<=m;i++){
            int op,a,b,k,add;
            scanf("%d",&op);
            if(op==1){
                scanf("%d%d%d%d",&a,&b,&k,&add);
                update(b,k,add,a%k);
                update(a-1,k,-add,a%k);
            }
            else{
                scanf("%d",&a);
                printf("%d\n",emt[a]+sum(a,a));
            }
        }
    }

}
