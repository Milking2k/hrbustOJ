#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int MOD = 1e9+7;
const int N = 2e5+7;

int k,n,m;
int sum[26][N],p[N];
int ans1[30],ans2[30];
char emt[N];
//---------------------------------------
int get(int id,int l,int r)
{
    return (sum[id][r]-1ll*sum[id][l-1]*p[r-l+1])%MOD;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",emt+1);
    // 计算字符串中每一个字符的前缀个数和
    for(int i=0;i<26;i++)
        for(int j=1;j<=n;j++)
            sum[i][j] = (2ll*sum[i][j-1]+(emt[j]=='a'+i))%MOD;
    //
    p[0]=1;
    for(int i=1;i<=n;i++) p[i]=(p[i-1]<<1)%MOD;

    while(m--)
    {
        int x,y,len;
        scanf("%d%d%d",&x,&y,&len);
        // 查找某个区间中每个字母各有多少个 PS:话说这种方法不会有特殊情况吗?
        for(int i=0;i<26;i++){
            ans1[i] = (get(i,x,x+len-1)+MOD)%MOD;
            ans2[i] = (get(i,y,y+len-1)+MOD)%MOD;
        }
        sort(ans1,ans1+26);
        sort(ans2,ans2+26);
        // 查两个序列是不是全等
        int flag = 1;
        for(int i=0;i<26 && flag;i++)
            if(ans1[i]!=ans2[i]) flag = 0;
        puts(flag?"YES":"NO");
    }
    return 0;
}