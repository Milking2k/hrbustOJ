#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=1e5+7;
LL sum[maxn<<2],sumv[maxn<<2],lazy[maxn<<2];
LL a[maxn];

void build(int i,int l,int r)
{
    lazy[i]=0;
    if(l==r){
        sum[i]=a[l];
        sumv[i]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    int len=r-l+1;
    sum[i]=sum[i<<1]+sum[i<<1|1];
    sumv[i]=sumv[i<<1]+sum[i<<1|1]*(len-(len>>1))+sumv[i<<1|1];
}

void update(int i,int l,int r,int L,int R,LL val){
    if(L<=l&&r<=R){
		lazy[i]+=1ll*val;
		sum[i]+=1ll*val*(r-l+1);
		sumv[i]+=1ll*val*(r-l+2)*(r-l+1)/2;
		return;
	}

    int len=r-l+1;
	if(lazy[i]){
		LL as=len-(len>>1);
		LL qw=(len>>1);
		lazy[i<<1]+=1ll*lazy[i];
		lazy[i<<1|1]+=1ll*lazy[i];
		sum[i<<1]+=1ll*lazy[i]*as;
		sum[i<<1|1]+=1ll*lazy[i]*qw;
		sumv[i<<1]+=1ll*(1+as)*as/2*lazy[i];
		sumv[i<<1|1]+=1ll*(1+qw)*qw/2*lazy[i];
		lazy[i]=0;
	}

	int mid=(l+r)>>1;
	if(L<=mid)update(i<<1,l,mid,L,R,val);
	if(R>mid)update(i<<1|1,mid+1,r,L,R,val);
	sum[i]=sum[i<<1]+sum[i<<1|1];
    sumv[i]=sumv[i<<1]+1ll*sum[i<<1|1]*(len-(len>>1))+sumv[i<<1|1];
}

LL query(int i,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return sum[i]*(l-L)+sumv[i];
	}
	int x=r-l+1;
	if(lazy[i]){
		LL as=x-(x>>1);
		LL qw=(x>>1);
		lazy[i<<1]+=1ll*lazy[i];
		lazy[i<<1|1]+=1ll*lazy[i];
		sum[i<<1]+=1ll*lazy[i]*as;
		sum[i<<1|1]+=1ll*lazy[i]*qw;
		sumv[i<<1]+=1ll*(1+as)*as/2*lazy[i];
		sumv[i<<1|1]+=1ll*(1+qw)*qw/2*lazy[i];
		lazy[i]=0;
	}
	int mid=(l+r)>>1;
	LL ans=0;
	if(L<=mid)ans+=query(i<<1,l,mid,L,R);
	if(R>mid)ans+=query(i<<1|1,mid+1,r,L,R);
	return ans;
}
int n,m;
int rev(int x){return n-x+1;}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        memset(sum,0,sizeof(sum));
        memset(sumv,0,sizeof(sumv));
        memset(lazy,0,sizeof(lazy));
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n/2;i++){
            swap(a[i],a[n-i+1]);
        }
//        reverse(a+1,a+1+n);
        build(1,1,n);
        while(m--){
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if(op==1){
                l=rev(l);r=rev(r);
                swap(l,r);
                //printf("fuck %d %d\n",l,r);
                LL ans=query(1,1,n,l,r);
                printf("%lld\n",ans);
            }
            else{
                int as=rev(l);
                LL tmp=query(1,1,n,as,as);
                update(1,1,n,as,as,-tmp);
                update(1,1,n,as,as,r);
                //printf("test as==%d  == %d\n",as,query(1,1,n,as,as));
            }
        }
    }
    return 0;
}
/*
5 10
1 2 3 4 5
2 5 0
2 4 0
*/