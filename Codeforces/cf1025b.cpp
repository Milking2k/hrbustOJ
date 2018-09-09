#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=2e6+3;

struct node{
    int x,y;
}c[maxn];
int main() {
    int n;
    read(n);
    int ans=0;
    for(int i=1;i<=n;i++) {
        read(c[i].x);
        read(c[i].y);
    }
    int xx=c[1].x;
    int yy=c[1].y;
    set<int> v;
    v.insert(xx);
    v.insert(yy);
    for(int i=2;i<=sqrt(xx);i++) {
        if(xx%i==0)v.insert(i),v.insert(xx/i)/*,cout<<i<<" "<<xx/i<<endl;*/;

    }
    for(int i=2;i<=sqrt(yy);i++) {
        if(yy%i==0)v.insert(i),v.insert(yy/i)/*,cout<<i<<" "<<yy/i<<endl;*/;

    }
    set<int>::iterator it;
    for(it=v.begin();it!=v.end();it++) {
        int mm=*it;
        int cnt=0;
        for(int i=2;i<=n;i++) {
            if(c[i].x%mm==0 || c[i].y%mm==0)cnt++;
        }
        if(cnt==n-1) {
            ans=mm;
            break;
        }
    }
    if(ans==0)puts("-1");
    else cout<<ans<<endl;
}