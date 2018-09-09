//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

int n;
int rk,prob;
char strname[20];
char str[20];
int len;
int main()
{
    scanf("%d",&n);
    for(int m=1;m<=n;m++)
    {
        scanf("%d %s %d %s",&rk,strname, &prob, str);

        printf("%3d|%s",rk,strname);
        for(int i=1;i<=16-strlen(strname);i++) printf(" ");
        printf("|%d|[",prob);
        if(strcmp(str,"Running") == 0)
        {
            scanf("%d",&len);
            for(int i=1;i<=len;i++)
            {
                printf("X");
            }
            for(int i=len+1;i<=10;i++)
            {
                printf(" ");
            }
            printf("]\n");
        }
        else if(strcmp(str, "FB")==0)
        {
            printf("    AC*   ]\n");
        }
        else
        {
            printf("    %s", str);
            for(int i=0;i<6-strlen(str);i++)
                printf(" ");
            printf("]\n");

        }
    }
    return 0;
}
