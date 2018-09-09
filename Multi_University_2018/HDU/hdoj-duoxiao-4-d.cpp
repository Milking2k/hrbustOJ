
#include<bits/stdc++.h>
#define read(x) scanf("%lld",&x)
using namespace std;
struct node{
    long long x,y;
}c[5005];
bool cmp(node a,node b) {
    return (a.x*1.0/a.y) > (b.x*1.0/b.y);
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        long long n,m;
        read(n);
        read(m);
        for(long long i=1;i<=n;i++) {
            read(c[i].x);
            read(c[i].y);
        }
        sort(c+1,c+1+n,cmp);
        long long temp=1;
        long long ans;
        long long f=0;
        for(long long i=1;i<=n;i++) {
            long long xx=c[i].x+c[i].y;
            temp*=xx;
            //cout<<temp<<endl;;
            if(temp>m){
                ans=i-1;
                break;
            }
            else {
                ans=i;
            }
        }
        printf("%lld\n",ans);
    }
}
