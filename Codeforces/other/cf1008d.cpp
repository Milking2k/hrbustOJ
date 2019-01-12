#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100005;

long long C(int n,int m)
{
    long long ret=1;
    for(int i=1;i<=m;i++)
        ret*=(n-i+1);
    for(int i=1;i<=m;i++)
        ret/=i;
    return ret;
}
bool check(int a,int b,int c)
{
    if((a&1)&&(b&2)&&(c&4))
        return true;
    if((a&1)&&(c&2)&&(b&4))
        return true;
    if((b&1)&&(a&2)&&(c&4))
        return true;
    if((b&1)&&(c&2)&&(a&4))
        return true;
    if((c&1)&&(a&2)&&(b&4))
        return true;
    if((c&1)&&(b&2)&&(a&4))
        return true;
    return false;
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int n;
int q[MAXN],m;
int cnt[10],use[10];
int fac[MAXN];

int main()
{
//预处理因数个数
    for(int i=1;i<MAXN;i++)
        for(int j=i;j<MAXN;j+=i)
            fac[j]++;
    int T,X,Y,Z;
    scanf("%d",&T);
    long long ans;
    while(T--)
    {
        scanf("%d%d%d",&X,&Y,&Z);
        m=0;
        int xy=gcd(X,Y),yz=gcd(Y,Z),xz=gcd(X,Z);
        int xyz=gcd(xy,Z);
        //计算每种状态的因数个数
        cnt[7]=fac[xyz];//111
        cnt[6]=fac[yz]-fac[xyz];//110
        cnt[5]=fac[xz]-fac[xyz];//101
        cnt[4]=fac[Z]-fac[xz]-fac[yz]+fac[xyz];//100
        cnt[3]=fac[xy]-fac[xyz];//011
        cnt[2]=fac[Y]-fac[yz]-fac[xy]+fac[xyz];//010
        cnt[1]=fac[X]-fac[xy]-fac[xz]+fac[xyz];//001

        ans=0;
        for(int a=1;a<8;a++)
            for(int b=a;b<8;b++)
                for(int c=b;c<8;c++)
                    if(check(a,b,c))//检查合法
                    {
                        memset(use,0,sizeof use);
                        use[a]++;use[b]++;use[c]++;
                        long long tmp=1;
                        for(int i=1;i<8;i++)
                            if(use[i])
                                tmp*=C(cnt[i]+use[i]-1,use[i]);//组合数计算
                        if(tmp>0)
                            ans+=tmp;
                    }

        printf("%I64d\n",ans);
    }

    return 0;
}
