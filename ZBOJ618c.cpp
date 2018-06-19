#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int emt[1007];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&emt[i]);

        int leftnum=n;
        for(int i=1;i<=n;i++)
        {
            int minnum = 0x3f3f3f3f;
            int relspos = 0;
            int pos1,pos2;

            bool flag = false;
            bool cgflag = false;

            for(pos1=1;pos1+1<=n;)
            {
                while(pos1<=n && emt[pos1]==0) pos1++;
                pos2 = pos1+1;
                while(pos2<=n && emt[pos2]==0) pos2++;

                if(pos1>n || pos2>n) break;

                if(emt[pos1] < emt[pos2])
                    emt[pos1]--,emt[pos2]++;
                else if (emt[pos1] > emt[pos2])
                    emt[pos1]++,emt[pos2]--;
                else
                    emt[pos1]=0,emt[pos2]=0,leftnum -= 2,flag = true;

                minnum = min(minnum, min(emt[pos1], emt[pos2]));
                if(minnum == emt[pos1])
                    relspos = pos1, cgflag = true;
                if(minnum == emt[pos2])
                    relspos = pos2, cgflag = true;
                pos1 = pos2+1;
            }

//            for(int i=1;i<=n;i++)
//                printf("%d ",emt[i]);
//            printf("\n\n");

            //right
            for(pos1=1;pos1+1<=n;)
            {
                while(pos1<=n && emt[pos1]==0) pos1++;
                pos1++;
                while(pos1<=n && emt[pos1]==0) pos1++;

                pos2 = pos1+1;
                while(pos2<=n && emt[pos2]==0) pos2++;

                if(pos1>n ||pos2>n) break;

                if(emt[pos1] < emt[pos2])
                    emt[pos1]--,emt[pos2]++;
                else if(emt[pos1] > emt[pos2])
                    emt[pos1]++,emt[pos2]--;
                else
                    emt[pos1]=0,emt[pos2]=0,leftnum -= 2,flag = true;

                minnum = min(minnum, min(emt[pos1], emt[pos2]));
                if(minnum == emt[pos1])
                    relspos = pos1, cgflag = true;

                if(minnum == emt[pos2])
                    relspos = pos2, cgflag = true;

                pos1 = pos2+1;
            }
            emt[relspos] = 0;
            if(!flag)
                leftnum--;

//            for(int i=1;i<=n;i++)
//                printf("%d ",emt[i]);
//            printf("\n");

            if(leftnum<=2) break;
        }
        int ans[10007],top=0;
        for(int i=1;i<=n;i++)
        {
            if(emt[i] != 0) ans[top++]=i;
        }
        if(top<=1) printf("impossible\n");
        else printf("%d %d\n",ans[0],ans[1]);
    }
    return 0;
}
