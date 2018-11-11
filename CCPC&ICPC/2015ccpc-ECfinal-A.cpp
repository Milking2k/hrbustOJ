#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;

LL n;
bool check(LL x)
{
    LL as;
    if(x&1)as=(x+1)/2*x;
    else as=x/2*(x+1);
    if(as<=n)return true;
    else return false;
}
int main() {
    int T;
    read(T);
    int cas=1;
    while(T--) {
        cin>>n;
        LL l=1,r=2e9;
        LL mid=0;
        LL ans=1;
        while(l<=r) {
            mid=(l+r)/2;
            if(check(mid)){
                l=mid+1;ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        LL as;
        if(ans&1)as=(ans+1)/2*ans;
        else as=ans/2*(ans+1);
        printf("Case #%d: %lld\n",cas++,as);
    }
    return 0;
}