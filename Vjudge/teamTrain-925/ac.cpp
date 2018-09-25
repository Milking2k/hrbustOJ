#include <bits/stdc++.h>
using namespace std;

int stk[505],top;
int main()
{
    for(int i=1;;i++){
        int as=i*(i+1)/2;
        stk[++top]=as;
        if(as>1000)break;
    }
//    printf("test %d\n",top);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        bool ok=true;
        for(int i=1;i<=top&&stk[i]<=n&&ok;i++){
            for(int j=1;j<=top&&stk[j]<=n&&ok;j++){
                for(int k=1;k<=top&&stk[k]<=n&&ok;k++){
                    int as=stk[i]+stk[j]+stk[k];
                    if(as==n){
                        ok=false;break;
                    }
                }
            }
        }
        if(!ok)puts("1");
        else puts("0");
    }
    return 0;
}
