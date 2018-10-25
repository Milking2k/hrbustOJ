#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    int T=read();
    int cas=1;
    while(T--){
        double ans=0.0;
        int n=read(),m=read(),K=read();
        int as=n,k=n-m,x=m;
        for(int i=1;i<=K;i++){
            double k=(n-m)*1.0;
            double x=m*1.0;
            double as=k+x;
            ans+=as/x;
            m--;n--;
        }
        printf("Case #%d: %.7f\n",cas++,ans);
    }
    return 0;
}
