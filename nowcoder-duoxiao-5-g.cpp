#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main()
{
    LL c,n;
    while(~scanf("%lld%lld",&c,&n)){
        if(c>n){
            puts("-1");
        }
        else{
            n/=c;
            LL as=n;
            if(as<=1){
                printf("%lld\n",c*c*1LL);
            }
            else{
                printf("%lld\n",as*(as-1)*c*c*1LL);
            }
        }
    }
    return 0;
}