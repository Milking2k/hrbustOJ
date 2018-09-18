#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;

LL get(LL num) {
    int sum=0;
    while(num!=0) {
        num/=2;
        sum++;
    }
    return sum;
}
int s1[105];
int s2[105];
int main() {
    int T;
    read(T);
    while(T--) {
        LL a,b;
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        scanf("%lld%lld",&a,&b);
        LL c1=get(a),c2=get(b);
        if(c1 != c2) {
            LL ans1=pow(2,max(c1,c2)-1);
//            cout<<ans1<<endl;
            cout<<(LL)(ans1|(ans1-1))<<endl;
        }
        else {
            int cnt=0;
            while(a!=0) {
                int tt=a%2;
                s1[cnt++]=tt;
                a/=2;
            }
            cnt=0;
            while(b!=0) {
                int dd=b%2;
                s2[cnt++]=dd;
                b/=2;
            }
            LL ans=0;
            LL val=pow(2,cnt-1);

            int f=0;
            /*for(int i=cnt-1;i>=0;i--)cout<<s1[i];
            puts("");
            for(int i=cnt-1;i>=0;i--)cout<<s2[i];
            puts("");*/
            for(int i=cnt-1;i>=0;i--) {
//                cout<<s[i];
//                cout<<val<<endl;
                if(s1[i] != s2[i])f=1;
                if(f==1) s1[i]=1;
                ans+=val*s1[i];
                val/=2;
            }
//            puts("$%");
//            puts("^#$%");
            cout<<ans<<endl;
        }
    }
}