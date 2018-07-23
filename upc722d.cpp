#include <bits/stdc++.h>
using namespace std;
 
typedef double db;
typedef long long ll;
 
#define FI(n) FastIO::read(n)
namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf;

		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
}; 
const int N=1010,inf=0X3f3f3f3f;
const db eps=1e-8;
 
int n,W;
int w[N],t[N];
 
db f[N],now[N];
 
bool check(db x)
{
	register int i,j;
	for(i=1;i<=W;++i) f[i]=-inf;
	for(i=1;i<=n;++i) now[i]=t[i]-x*w[i];
	for(i=1;i<=n;++i)
	{
		for(j=W;j>=W-w[i] && ~j;--j)
			f[W]=max(f[W],f[j]+now[i]);
		for(j=W-1;j>=w[i];--j)
			f[j]=max(f[j],f[j-w[i]]+now[i]);
	}
	return f[W]>eps;
}
 
int main()
{
	n=read(),W=read();
	register int i;
	for(i=1;i<=n;++i) w[i]=read(),t[i]=read();
	db l(0),r(1e6),mid;
	while(r-l>eps)
	{
		mid=(l+r)*0.5;
		check(mid) ? l=mid : r=mid;
	}
	cout<<floor(r*1000)<<endl;
	return 0;
}
