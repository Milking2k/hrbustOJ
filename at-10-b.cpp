
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
 
LL a[maxn];
LL stk[maxn];
int top=0;
 
int main()
{
    int n;
    scanf("%d",&n);
    bool flag=true;
    LL cnt=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        cnt+=a[i];
    }

    LL sum;
    top=0;

    if(n&1)sum=(n+1)/2*n;
    else sum=n/2*(n+1);
    LL k=cnt/sum;
    if((cnt%sum)!=0){
        return puts("NO"), 0;
    }

    for(int i=1;i<n;i++){
        stk[i-1]=a[i]-a[i-1];
    }
    stk[n-1]=a[0]-a[n-1];

    bool ok=true;
    for(int i=0;i<n;i++){
        if(stk[i]>k||(stk[i]-k)%n){
            ok=false;
            break;
        }
    }
    if(ok)puts("YES");
    else puts("NO");
    return 0;
}