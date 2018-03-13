//right answer

#include<cstdio>  
#include<algorithm>  
using namespace std;  
struct point  
{  
    int x,y;  
}a[200001];  
inline bool cmp1(point x,point y)  
{  
    if(x.x<y.x)  
        return true;  
    return false;  
}  
inline bool cmp2(point x,point y)  
{  
    if(x.y>y.y)  
        return true;  
    return false;  
}  
point q1[200001],q2[200001];  
inline int find(int x,int lim)  
{  
    int l=1,r=lim;  
    int mid;  
    while(l<=r)  
    {  
        mid=(l+r)/2;  
        if(q1[mid].y<=x)  
            r=mid-1;  
        else  
            l=mid+1;  
    }  
    return r;  
}  
long long ans;  
inline void solve(int l,int r)  
{  
    if(l>=r)  
        return ;  
    int mid=(l+r)/2;  
    solve(l,mid);  
    sort(a+l,a+mid+1,cmp2);  
    sort(a+mid+1,a+1+r,cmp2);  
    int i;  
    int top1=0,top2=0,p=mid+1;  
    int ll,rr;  
    q1[0].y=q2[0].y=2100000000;  
    for(i=l;i<=mid;i++)  
    {  
        while(p<=r&&a[p].y>a[i].y)  
        {  
            while(top1!=0&&a[p].x<q1[top1].x)  
                top1--;  
            top1++;  
            q1[top1]=a[p];  
            p++;  
        }  
        while(top2!=0&&a[i].x>q2[top2].x)  
            top2--;  
        top2++;  
        q2[top2]=a[i];  
        ll=find(q2[top2-1].y,top1)+1;  
        rr=find(q2[top2].y,top1);  
        if(ll<=rr)  
            ans+=(long long)(rr-ll+1);  
    }  
    sort(a+l,a+mid+1,cmp1);  
    sort(a+mid+1,a+1+r,cmp1);  
    solve(mid+1,r);  
}  
int main()  
{  
    //freopen("03-05.txt","r",stdin);  
    //freopen("03-05.out","w",stdout);  
    int n;  
    while(~scanf("%d",&n))
    {

	    int i;  
	    ans = 0;
	    for(i=1;i<=n;i++)  
	        scanf("%d%d",&a[i].x,&a[i].y);  
	    sort(a+1,a+1+n,cmp1);  
	    solve(1,n);  
	    printf("%lld\n",ans);  
    }
    return 0;  
}  