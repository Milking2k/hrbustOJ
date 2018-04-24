#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn*maxn];
 
int main() {
    int t;
    int sum=0;
    for(int i=0;i<=9;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<=9;k++) {
                a[sum++]=k*1+j*10+i*100+i*1000+j*10000+k*100000;
            }
        }
    }
    scanf("%d",&t);
    while(t--) {
        int d;
        scanf("%d",&d);
        int maxx=maxn*maxn;
        int index;
        for(int i=0;i<sum;i++) {
            if(abs(a[i]-d) < maxx) {
                index=i;
                maxx=abs(a[i]-d);
            }
        }
        printf("%d\n",a[index]);
    }
}