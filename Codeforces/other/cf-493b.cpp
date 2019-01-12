#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+7;
const int MOD = 1e9+7;

int t,n,m,pos=0;
int emt[107],oe[107],val[107];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&emt[i]);

        if(emt[i]&1) oe[i] = oe[i-1]+1;
        else oe[i] = oe[i-1] - 1;
        if(oe[i-1]==0 && i>1)
            val[pos++] = abs(emt[i]-emt[i-1]);
    }
    int ans=0,sum=0;
    sort(val,val+pos);

    for(int i=0;i<pos;i++){
        if(sum + val[i] <=m){
            sum += val[i];
            ans++;
        }
    }
    printf("%d\n",ans);

    return 0;
}
