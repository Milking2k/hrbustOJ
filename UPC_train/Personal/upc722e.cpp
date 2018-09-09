#include<bits/stdc++.h>
using namespace std;

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

struct node
{
    int val,p;
}emt[100007];
int t,n,m;
bool vis[100007];
bool cmp(node a, node b){
    if(a.val==b.val) return a.p<b.p;
    return a.val < b.val;
}
int main()
{
//    while(~scanf("%d",&n)){
//        freopen("in.txt","r",stdin);
//        freopen("out.txt","w",stdout);
        FI(n);
        for(int i=1;i<=n;i++){
//            scanf("%d",&emt[i].val);
            int a;
            FI(a);
            emt[i].val = a;
            emt[i].p=i;
        }

        sort(emt+1,emt+1+n,cmp);
        int ans=1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(emt[i].p > i)++cnt;
            if(vis[i])--cnt;
            vis[emt[i].p] = true;
            ans=max(ans,cnt);
        }
        printf("%d\n",ans);
//}
    return 0;
}
