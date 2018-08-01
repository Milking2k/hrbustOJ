#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main() {
    int T;
    read(T);
    while(T--) {
        int n;
        read(n);
        for(int i=1;i<=n;i++) {
            read(a[i]);
        }
        int d=abs(a[1]-a[n]);
        //cout<<d<<endl;
        d=sqrt(d);
        printf("%d\n",d);
    }
}
