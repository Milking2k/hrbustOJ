#include<bits/stdc++.h>
using namespace std;

int n;
int ans[20];
int emt1[10]={100,50,20,10,5,2,1};
int emt2[10]={50,20,10,5,2,1};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int cnt = a;
        for(int j=0;j<7;j++){
            ans[j] = cnt/emt1[j];
            if(ans[j]!=0){
                cnt = cnt%emt1[j];
            }
        }
        cnt = b;
        for(int j=0;j<6;j++){
            ans[j+7] = cnt/emt2[j];
            if(ans[j+7]!=0){
                cnt = cnt%emt2[j];
            }
        }
        for(int i=0;i<13;i++){
            printf(i==12?"%d\n":"%d ",ans[i]);
        }
    }

    return 0;
}
