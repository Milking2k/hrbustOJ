#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int maxn=1e5+7;
LL a[maxn];
LL stk[maxn],top;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        top=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(i==1)stk[top++]=a[i];
            else {
                if(a[i]!=stk[top-1])stk[top++]=a[i];
            }
        }
//        puts("");
//        for(int i=0;i<top;i++){
//            printf("%lld ",stk[i]);
//        }
//        puts("");
        stk[top++]=0;
        LL sum=0;
        LL cnt=0;
        for(int i=1;i<top;i++){
            if(stk[i]>stk[i-1]){
                sum+=stk[i]-stk[i-1];
                if(stk[i+1]<=stk[i])cnt++;
            }
        }
        printf("%lld %lld\n",sum,cnt*2);
    }
    return 0;
}