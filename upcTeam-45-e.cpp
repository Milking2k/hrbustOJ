#include <bits/stdc++.h>
using namespace std;
 
const int maxn=1e5+7;
int a[maxn],n,m;
int stk[maxn];
int top;
 
int main()
{
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        a[0]=0;
        sort(a+1,a+1+n);
        int l=1;
        int r=maxn*10;
        int ans;
        int mid;
        while(l<=r) {
            mid=(l+r)/2;
            int temp=1;
            int sum=1;
            for(int i=1;i<=n;i++) {
                if(a[i]-a[temp] >= mid) {
                    temp=i;
                    sum++;
                }
            }
            //cout<<l<<" "<<r<<" "<<mid<<endl;
            if(sum >= m) {
                l=mid+1;
            }
            else {
                r=mid-1;
            }
 
        }
        printf("%d\n",r);
    }
    return 0;
}
 