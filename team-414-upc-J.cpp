#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
char str[maxn];
int a[2][maxn];
 
int main()
{
    while(~scanf("%s",str+1)){
        memset(a,0,sizeof(a));
        int len=strlen(str+1);
        str[0] = '0';
        str[len] = '0';
        // printf("%c\n", str[1]);
        int point1,point2,point3;
        for (int i = 0; i < len; ++i)
        {
            if (str[i] == '0')
            {
                point1 = i;
                int flag=0;
                for (int j=i;j<=len;j++)
                {
                    if(str[j]=='2'){
                        point2 = j;
                        flag = 1;
                    }
                    if(str[j]=='0' && flag==1) point3 = j;
                }
            }
        }
    }
    return 0;
}