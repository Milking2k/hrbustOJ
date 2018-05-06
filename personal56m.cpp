#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int emt[200007];
int emtgo[200007];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&emt[i]);
        }
        emtgo[0] = emt[0];
        int ans=1;
        for(int i=1;i<n;i++)
        {
            bool flag = true;
            for(int j=0;j<ans;j++)
            {
                if(emtgo[j]>=emt[i])
                {
                    emtgo[j] = emt[i];
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ans++;
                emtgo[ans-1] = emt[i];
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

