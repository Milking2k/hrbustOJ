#include <bits/stdc++.h>
using namespace std;

#define read(x) scanf("%d",&x)
int ma[2][10005];
int main() {
    int T;
    read(T);
    while(T--) {
        int n;
        int a0=0,a1=0,a2=0;
        read(n);
        int t=0;
        for(int i=1;i<=2*n;i++) {
            int d;
            read(d);
            d%=3;
            if(d==0)a0++;
            if(d==1)a1++;
            if(d==2)a2++;
        }
        if(a1==0 || a2==0) {
            if(a0<=n){
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
            continue;
        }
        if(a0==2 && a2%2==1){
            printf("YES\n");
            continue;
        }
        if(a0>2 && a0<=n) {
            printf("YES\n");
            continue;
        }
        else {
            printf("NO\n");
        }
    }
}