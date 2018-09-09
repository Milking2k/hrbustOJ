#include <iostream>
#include <cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

int T;
int n;
char str[1000007];
int ans[1000007];
int main()
{
    scanf("%d",&T);
    while(T--)
    {

        scanf("%d",&n);
        scanf("%s",str+1);

        for(int i = n-1; i >= 1 ; i--)
        {
            if(str[i]<str[i+1]) ans[i] = 1;
            else if(str[i]==str[i+1]) ans[i] = ans[i+1];
            else ans[i] = 0;
        }
        for(int i=1;i<n;i++)
            if(ans[i]==1)
                printf("<");
            else
                printf(">");
        printf("\n");
    }
    return 0;
}
//<><<<<><<><<<><<>
//<><<<<><<><<<><<
//<><<<<><<><<<><<
