#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int a[20];
ll dp[20][200][200][2],as;
 
ll dfs(int pos,int sum,int val,int mod,bool limit)
{
    if(pos==-1){
//        printf("test pos==%d sum==%d val==%d\n",pos,sum,val);
        if(sum==0&&val==0)return 1;
        else return 0;
    }
 
    if(dp[pos][sum][val][limit]!=-1)return dp[pos][sum][val][limit];
    int up=limit?a[pos]:9;
    ll ans=0;
//    printf("duck pos=%d sum==%d val==%d mod==%d limit==%d up==%d\n",pos,sum,val,mod,limit,up);
    for(int i=0;i<=up;i++){
        if(sum-i<0)continue;
        ans+=dfs(pos-1,sum-i,(val*10+i)%mod,mod,limit&&i==a[pos]);
//        printf("test2 pos==%d i==%d ans==%lld up==%d\n",pos,i,ans,up);
    }
//    printf("zzz\n");
    dp[pos][sum][val][limit]=ans;
//    printf("qwe pos=%d sum==%d val==%d mod==%d limit==%d up==%d ans==%lld\n",pos,sum,val,mod,limit,up,ans);
    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x){
        a[pos++]=x%10;
        x/=10;
    }
    ll res=0;
    int z=(pos)*9;
//    printf("qqq %d\n",z);
//    printf("aaaa == %d\n",dfs(pos-1,1,0,1,true));
    for(int i=1;i<=z;i++){
        memset(dp,-1,sizeof(dp));
        res+=dfs(pos-1,i,0,i,true);
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--){
//        memset(dp,-1,sizeof(dp));
//        cout<<dp[2][1][23][0]<<endl;
        scanf("%lld",&as);
        printf("Case %d: %lld\n",cas++,solve(as));
//        printf("adas %lld\n",dp[0][9][0][1]);
    }
    return 0;
}