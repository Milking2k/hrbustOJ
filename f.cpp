//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;


int T,n,m;
int emt[100007];
int main()
{
    scanf("%d",&T);
    int cont=0;
    while(cont<T)
    {
        cont++;
        scanf("%d%d",&n,&m);
        int minans1=0x3f3f3f3f;
        int minans2=0x3f3f3f3f;
        int x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            minans1 = min(minans1, x);
        }
        for(int i=1;i<=nm;i++)
        {
            scanf("%d",&x);
            minans2 = min(minans2, x);
        }
        printf("Problem %d:\n",1000+cont);
        printf("Shortest judge solution: %d bytes.\n", minans1);
        if(minans2 == 0x3f3f3f3f)
            printf("Shortest team solution: N/A bytes.\n");
        else
            printf("Shortest team solution: %d bytes.\n", minans2);
    }
    return 0;
}
