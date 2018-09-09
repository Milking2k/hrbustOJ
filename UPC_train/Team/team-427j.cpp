#include<bits/stdc++.h>
using namespace std;
 
int h,w,n;
int k;
int emt[107][107];
 
int main()
{
    freopen("kotlin.in","r",stdin);
	freopen("kotlin.out","w",stdout);
    while(~scanf("%d%d%d",&h,&w,&n))
    {
        memset(emt,0,sizeof(emt));
        bool flag = true;
        int lenx=0,leny=0;
        for(int i=1;i<=(h+1)/2;i++)
        {
            if(n%i==0 && (n/i)<=((w+1)/2)){
                lenx = i;
                leny = n/i;
                flag = false;
                break;
            }
        }
        if(flag)
        {
            printf("Impossible\n");
            continue;
        }
        for(int i=0;i<lenx-1;i++){
            for(int j=0;j<w;j++)
                emt[2*i+1][j]=1;
        }
        for(int i=0;i<leny-1;i++){
            for(int j=0;j<h;j++){
                emt[j][2*i+1]=1;
            }
        }
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(emt[i][j]) printf("#");
                else printf(".");
            }
            puts("");
        }
 
 
    }
 
 
    return 0;
}