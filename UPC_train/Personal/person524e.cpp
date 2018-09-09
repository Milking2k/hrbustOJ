#include<bits/stdc++.h>
using namespace std;
char s[100007];
int main()
{
    while(~scanf("%s",&s))
    {
        int pos1,pos2;
        pos1=0,pos2=(strlen(s)-1);
        char lc=s[0],rc=s[pos2];
        int ans=0;
        while(pos1<pos2-1)
        {
//            printf("test111\n");

//            printf("ST::pos1:%d pos2:%d\n",pos1,pos2);
            while(s[pos1]==lc && pos1<pos2-1)pos1++;
            if(lc!=s[pos1])
            {
                lc=s[pos1];
                ans++;
            }
            while(s[pos2]==rc && pos1<pos2-1)pos2--;
            if(rc!=s[pos2])
            {
                rc=s[pos2];
                ans++;
            }
//            printf("ED::pos1:%d pos2:%d\n",pos1,pos2);
        }
        if(lc!=rc)ans++;
        printf("%d\n",ans);
    }
    return 0;
}


