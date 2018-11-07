#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e6+8;
typedef long long LL;
char s1[maxn];
char s2[maxn];
int main() {
    int T;
    read(T);
    while(T--) {
        int n;
        read(n);
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        int i1=0,i2=0,i3=0,i4=0;
        int i5=0;
//        cout<<n<<endl;
        for(int i=1;i<=n;i++) {
//            printf("%d %d %d %d %d %d\n",i1,i2,i3,i4,i5,i);
            if(s1[i]!=s2[i] && i3) {
//                puts("#@%");
                i5=i;
                break;
            }
            if(s1[i] != s2[i] && i1==0) {
                i1=i;
                int j;
                for(j=i;j<=n;j++) {
                    if(s1[j] != s2[j]) {
                        i2=j;
                        continue;
                    }
                    else break;
                }
                i=j-1;
                continue;
            }
            if(s1[i] != s2[i] && i1) {
                i3=i;
                int j;
                for(j=i;j<=n;j++) {
                    if(s1[j] != s2[j]) {
                        i4=j;
                        continue;
                    }
                    else break;
                }
                i=j-1;
//                cout<<i<<" "<<n<<endl;
            }
        }
        if(i1==0) {
            LL ans=0;
            for(int i=1;i<=n;i++) {
                ans+=(n-i+1);
            }
            printf("%lld\n",ans);
            continue;
        }
        if(i5) {
            puts("0");
            continue;
        }
//        cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<endl;
        if(i3==0) {
            int ans=0;
            ans+=(i1-1);
            ans+=(n-i2);
            ans+=(i2-i1);
            printf("%d\n",ans*2);
        }
        else  {
            int ans=0;
            ans+=3;
            printf("%d\n",ans*2);
        }
    }
}