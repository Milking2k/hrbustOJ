#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<iomanip>
#include<cstdlib>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define maxn 700005
const int mod=1000000007;
inline int ksm(int x,int k){int s=1;for(;k;k>>=1,x=1ll*x*x%mod)if(k&1)s=1ll*s*x%mod;return s;}
inline int del(int x){return x<0?x+mod:x;}
inline int add(int x){return x<mod?x:x-mod;}
struct NTT{
	int rev[maxn];
	void init(int n)
	{
		int k=0;while((1<<k)<n)k++;
		for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	}
	void Trans(int *a,int n,int f)
	{
		for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int l=2;l<=n;l*=2)
		{
			int m=l/2;int omega=ksm(3,mod-1+f*(mod-1)/l);
			for(int *p=a;p!=a+n;p+=l)
			{
				int w=1;
				for(int i=0;i<m;i++)
				{
					int t=1ll*p[i+m]*w%mod;
					p[i+m]=p[i]-t;p[i+m]=del(p[i+m]);
					p[i]=p[i]+t;p[i]=add(p[i]);
					w=1ll*w*omega%mod;
				}
			}
		}
	}
	void dft(int *a,int n){Trans(a,n,1);}
	void idft(int *a,int n)
	{
		Trans(a,n,-1); int inv=ksm(n,mod-2);
		for(int i=0;i<n;i++)a[i]=1ll*a[i]*inv%mod;
	}
}ntt;
typedef vector<int> vec;
int n,v,rev,fac[maxn],inv[maxn],mul[maxn];
int gd[maxn],g2d[maxn],fd[maxn],f2d[maxn],dlt[maxn];
int A[maxn],B[maxn],C[maxn];
int pre_[maxn],*pre=pre_+1,suf[maxn];
inline void calc(int *h,int *out,int d,int k)
{
	int off=k-d-1;mul[0]=1;
	for(int i=1;i<=2*d+3;i++)
	{
		int s=(i+off)%mod;s=del(s);
		mul[i]=1ll*mul[i-1]*s%mod;
	}
	int len=1;for(;len<3*d+5;len<<=1);ntt.init(len);
	for(int i=0;i<=d;i++)
	{
		A[i]=1ll*h[i]*inv[i]%mod*inv[d-i]%mod;
		if((d-i)&1)A[i]=mod-A[i];
	}
	for(int i=0;i<=2*d;i++)B[i]=ksm((i-d+k)%mod,mod-2),B[i]=del(B[i]);
	ntt.dft(A,len);ntt.dft(B,len);
	for(int i=0;i<len;i++)C[i]=1ll*A[i]*B[i]%mod,A[i]=B[i]=0;
	ntt.idft(C,len);
	for(int i=0;i<=d;i++)
	{
		out[i]=1ll*C[i+d]*mul[i+k-off]%mod*ksm(mul[i+k-d-off-1],mod-2)%mod;
		out[i]=del(out[i]);
	}
}
void solve(int x,int *G,int *F)
{
	if(x==0){G[0]=1;F[0]=0;return;}
	if(x&1)
	{
		solve(x-1,G,F);
		for(int i=0;i<x;i++)gd[i]=G[i];
		calc(gd,dlt,x-1,-1ll*(n+1)*rev%mod);
		for(int i=0;i<x;i++)G[i]=1ll*G[i]*(i*v+x)%mod;
		int p=1;
		for(int i=1;i<=x;i++)p=1ll*p*(v*x+i)%mod;G[x]=p;
		for(int i=0;i<x;i++)
		{
			if((x-1)&1)F[i]-=dlt[i],F[i]=del(F[i]);
			else F[i]+=dlt[i],F[i]=add(F[i]);
			F[i]=1ll*F[i]*(i*v+x)%mod;
		}
		suf[x+1]=1;for(int i=x;i>=0;i--)suf[i]=1ll*suf[i+1]*(v*x+i)%mod;
		pre[-1]=1;for(int i=0;i<=x;i++)pre[i]=1ll*pre[i-1]*(n-i-v*x)%mod,pre[i]=del(pre[i]);
		p=0;for(int i=0;i<x;i++)p=(p+1ll*suf[i+1]*pre[i-1])%mod;F[x]=p;
		return;
	}
	int d=x>>1;solve(d,G,F);
	for(int i=0;i<=d;i++)gd[i]=G[i];
	calc(gd,gd+d+1,d,d+1);
	calc(gd,g2d,2*d,1ll*d*rev%mod);
	calc(gd,dlt,2*d,-1ll*(n+1)*rev%mod);
	for(int i=0;i<=d;i++)fd[i]=F[i];
	calc(fd,fd+d+1,d,d+1);
	calc(fd,f2d,2*d,1ll*d*rev%mod);
	for(int i=0;i<=x;i++)
	{
		int s=1ll*dlt[i]*f2d[i]%mod;if(d&1)s=mod-s;
		F[i]=(1ll*g2d[i]*fd[i]+s)%mod;
	}
	for(int i=0;i<=x;i++)G[i]=1ll*gd[i]*g2d[i]%mod;
}
int m,F[maxn],G[maxn];
inline void Work()
{
	n=read();m=read();v=sqrt(n+0.5);rev=ksm(v,mod-2);
	solve(v,G,F);
	int fac=1;for(int i=0;i<v;i++)fac=1ll*fac*G[i]%mod;
	for(int i=v*v+1;i<=n;i++)fac=1ll*fac*i%mod;
	for(int i=0;i<=v;i++)gd[i]=G[i];
	calc(gd,dlt,v,-1ll*(n+1)*rev%mod);
	pre[-1]=1;for(int i=0;i<=v;i++)pre[i]=1ll*pre[i-1]*dlt[i]%mod;
	suf[v]=1;for(int i=v*v+1;i<=n;i++)suf[v]=1ll*suf[v]*i%mod;
	for(int i=v-1;i>=0;i--)suf[i]=1ll*suf[i+1]*G[i]%mod;
	int ans=0,cr=0;
	for(int i=0;i<v&&(i+1)*v-1<=m;i++)
	{
		int t=1ll*suf[i+1]*pre[i-1]%mod*F[i]%mod;if((i*v)&1)t=mod-t;
		ans+=t;ans=add(ans);cr=i+1;
	}
	ans=1ll*ans*ksm(fac,mod-2)%mod;
	int C=fac,Mg=1;
	for(int i=0;i<cr;i++)Mg=1ll*Mg*G[i]%mod;
	int s=n-cr*v,cp=0;
    for(int i=0;i<v&&(i+1)*v<=s;i++)Mg=1ll*Mg*G[i]%mod,cp=i+1;
    for(int i=cp*v+1;i<=s;i++)Mg=1ll*Mg*i%mod;
	C=1ll*C*ksm(Mg,mod-2)%mod;
	for(int i=cr*v;i<=m;i++)
	{
		if(i!=cr*v)C=1ll*C*ksm(i,mod-2)%mod*(n-i+1)%mod;
		ans+=C;ans=add(ans);
	}cout<<ans<<"\n";
	for(int i=0;i<=v;i++)F[i]=G[i]=0;
}
int main()
{
	int T=read();
	fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[maxn-1]=ksm(fac[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	while(T--)Work();
	return 0;
}
