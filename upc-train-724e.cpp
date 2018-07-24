#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7,MOD = 1e9+7, INF=0x3f3f3f3f;
int t,n,m,emt[N];
int main()
{
    int pos=0;
    int sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x>=n){
            sum++;
        }
        else {
            emt[pos]=x;
            pos++;
        }
    }

    sort(emt,emt+pos);
    for(int i=pos-1;i>=0;i--){
        if(emt[i]>=sum){
            sum++;
        }
    }
    printf("%d\n",sum);
    return 0;
}
