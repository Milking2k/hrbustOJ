#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+7;
const int MOD = 1e9+7;

int t,n,m;
int emt[17];
int vis[1007];
int main()
{
    scanf("%d",&n);
    int minnum=0x3f3f3f3f;
    int sum=0;
    int pos=1;
    int ptpos=1;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        sum += x;

        if(x < minnum){
            minnum = x,pos = i;
            continue;
        }
        if(!vis[x]){
            emt[ptpos++] = x;
            vis[x] = 1;
        }
        else{
            vis[x]++;
        }
    }

    sum -= minnum;
    if(sum == minnum || n <= 1)
        printf("-1");
    else{
        printf("%d\n",ptpos-1);
        for(int i=1;i<ptpos;i++){
            printf(i!=n?"%d ":"%d\n", emt[i]);
        }

    }


    return 0;
}
