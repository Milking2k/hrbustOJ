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
const int MAXN = 5e5+7;
int t,n,m,cnt;
int head[MAXN], to[MAXN<<1], net[MAXN<<1], r[MAXN], vis[MAXN];
std::vector<int> q[MAXN];
inline void addedge(int u, int v){
    cnt++;
    to[cnt]=v;
    net[cnt] = head[u];
    head[u] = cnt;
}

struct node{
    int id;
    inline bool operator < (const node&a) const{
        return a.id < id;
    }
};
std :: priority_queue <node> dl;
inline void build(int mid){
    cnt = 0;
    memset(head,0,sizeof(head));
    memset(r,0,sizeof(r));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=mid;i++){
        for(int j=0;j<q[i].size()-1;j++){
            addedge(q[i][j], q[i][j+1]);
            r[q[i][j+1]]++;
        }
    }
}

inline bool topsort(int f){
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(!r[i]){
            sum++;
            dl.push((node){i});
            vis[i]=1;
        }
    }
    while(!dl.empty()){
        node now = dl.top();
        if(f) printf("%d ", now.id);
        dl.pop();
        for(int i=head[now.id];i;i=net[i]){
            r[to[i]]--;
            if(!r[to[i]] && !vis[to[i]]){
                dl.push((node){to[i]});
                sum++;
                vis[to[i]]=1;
            }
        }
    }
    return sum==n;
}

int main()
{
//    while(~scanf("%d %d",&n,&m)){
//        freopen("in.txt","r",stdin);
//        freopen("out.txt","w",stdout);
        FI(n),FI(m);
        for(int i=1;i<=m;i++){
            int s,x;
//            scanf("%d",&s);
            FI(s);
            for(int j=1;j<=s;j++){
//                scanf("%d",&x);
                FI(x);
                q[i].push_back(x);
            }
        }
        int l=0,r=m+1;
        int ans=0;
        while(l<=r){
            int mid = (l+r)>>1;
            build(mid);
            if(topsort(0)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        build(ans);
        topsort(1);
//    }
    return 0;
}
