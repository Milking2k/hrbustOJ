#include<bits/stdc++.h>
using namespace std;

const int  maxn=1008611;
int a[maxn],r[maxn],ans=0,n;
void msort(int s, int t)
{
    if(s==t) return;
    int mid=(s+t)/2;
    msort(s,mid);
    msort(mid+1,t);
    int i=s,j=mid+1,k=s;
    while(i<=mid &&j<=t)
    {
        if(a[i]<=a[j])
            r[k]=a[i],k++,i++;
        else{
            r[k]=a[j],k++,j++;
            ans+=mid-i+1;
        }
    }
    while(i<=mid)
        r[k]=a[i],k++,i++;
    while(j<=t)
        r[k]=a[j],k++,j++;
    for(int i=s;i<=t;i++)
        a[i]=r[i];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    msort(1,n);

    printf("%d\n",ans);
    return 0;
}
