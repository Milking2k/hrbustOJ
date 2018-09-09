#include<stdio.h>
#include<algorithm>
using namespace std;
int f[1005],ff[1005],a[1005];
int solve(int aa,int bb)
{
    return (aa-bb)*(aa-bb);
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int i,j;
        f[0]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            f[i]=f[i-1]+a[i];
        }
        ff[0]=0;
        ff[1]=solve(f[1],m);
        for(i=2;i<=n;i++)
        {
            ff[i]=ff[i-1]+solve(f[i]-f[i-1],m);
            for(j=1;j<i;j++)
            {
                ff[i]=min(ff[i],ff[j-1]+solve(f[i]-f[j-1],m));
            }
        }
        printf("%d\n",ff[n]);
    }

}
