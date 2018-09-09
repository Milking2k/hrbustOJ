#include<bits/stdc++.h>
#define read(x) scanf("%lld",&x)
using namespace std;
typedef long long LL;
 
LL a,b,c;
LL ans;
void solve(int x)
{
    if(x>12){
        LL as=x/6;
        as--;
        LL qw=x%6;
        qw+=6;
        ans+=as*min(3*b,2*c);
        solve(qw);
    }
    else{
        LL minn=b*6*1LL;
        for(int i=0;i<=6;i++){
            for(int j=0;j<=6;j++){
                LL zx=2LL*i+3LL*j;
                if(zx>=x){
                    minn=min(minn,b*i*1LL+c*j*1LL);
                }
            }
        }
        ans+=minn;
        return ;
    }
 
}
int main() {
    read(a);
    read(b);
    read(c);
    solve(a);
    printf("%lld\n",ans);
}