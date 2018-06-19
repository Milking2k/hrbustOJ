#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int emt[1007];
int gcd(int a,int b){
    if(a%b) return gcd(b, a%b);
    return b;
}
int main()
{
//    while(~scanf("%d %d",&n,&m))
//        printf("%d\n",gcd(n,m));
// 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&emt[i]);
        }

        int ans=0;
        for(int i=1; i<=n;i++)
        {
            int len=0;
            int cntpos=i;

            for(int j=i+1;j<=n;j++)
            {
                if(gcd(emt[cntpos],emt[j]) == 1 || emt[cntpos]==1 || emt[j] ==1)
                {
                    len++;
                    cntpos=j;
                }
            }
            ans = max(ans, len);
        }
        printf("%d\n",ans+2);
    }
    return 0;
}

