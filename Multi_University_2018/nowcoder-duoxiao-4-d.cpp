#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        if(n%2==0){
            int c=0;
            int f=1;
            puts("possible");
            for(int i=1;i<=n;i++) {
                if(i&1) {
                    for(int j=1;j<=c;j++){
                        if(j==1) {
                            printf("0");
                        }
                        else printf(" 0");
                    }
                    for(int j=c+1;j<=n;j++) {
                        if(j==1) {
                            printf("-1");
                        }
                        else printf(" -1");
                    }
                    c++;
                }
                else {
                    for(int j=1;j<=n-f;j++) {
                        if(j==1) {
                            printf("1");
                        }
                        else printf(" 1");
                    }
                    for(int j=n-f+1;j<=n;j++){
                        if(j==1) {
                            printf("0");
                        }
                        else printf(" 0");
                    }
                    f++;
                }
                puts("");
            }
        }
        else{
            puts("impossible");
        }
    }
    return 0;
}
