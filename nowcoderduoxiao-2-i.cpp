#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int maxn=5e4+7;
int n,m;
int x[100007],y[100007];
 
int main()
{
    while(~scanf("%d%d",&n,&m)){
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        bool flag = false;
        int pos1,pos2;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&pos1,&pos2);
            x[pos1]=1;
            y[pos2]=1;
//            if(pos1==pos2 && pos1==(n+1)/2) flag = true;
        }
 
        int sum=0;
 
        for(int i=1;i<=n;i++){
            if(x[i]==1) sum++;
            if(y[i]==1) sum++;
            if(x[i]==y[i] &&x[i] == 1&& i ==(n+1)/2)flag = true;
        }
        //cout<<sum<<" "<<flag<<endl;
        if(n&1){
            if(flag) sum--;
            printf("%d\n",2*(n-1)+1-sum);
        }
        else {
            printf("%d\n",2*n-sum);
        }
    }
    return 0;
}