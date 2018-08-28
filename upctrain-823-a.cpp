<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+7;
int a[maxn];
int n;

int main()
{
    int n;
    while(~scanf("%d",&n)){
        if(n==0)break;
        double sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i]*1.0;
        }
        sum/=n*1.0;
        int ans=0;
//        printf("test %f\n",sum);
        for(int i=1;i<=n;i++){
            if(a[i]<=sum)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+7;
int a[maxn];
int n;

int main()
{
    int n;
    while(~scanf("%d",&n)){
        if(n==0)break;
        double sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i]*1.0;
        }
        sum/=n*1.0;
        int ans=0;
//        printf("test %f\n",sum);
        for(int i=1;i<=n;i++){
            if(a[i]<=sum)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
