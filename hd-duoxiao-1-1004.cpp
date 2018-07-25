#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;


int T,n,m,pre[maxn],ret[maxn],l,r;
int main() {
    scanf("%d",&T);
    while(T--) {
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++) pre[i]=i;
    	for(int i=1;i<=m;i++){
    		scanf("%d %d",&l,&r);
    		pre[r] = min(pre[r], l);
    	}
    	for(int i=n-1;i>=1;i--) pre[i] = min(pre[i], pre[i+1]);
    	int pl=1;
    	set<int> val;
    	for(int i=1;i<=n;i++) val.insert(i);
    	for(int i=1;i<=n;i++){
    		while(pl < pre[i]) {
    			val.insert(ret[pl]);
    			pl++;
    		}
    		ret[i] = *val.begin();
    		val.erase(ret[i]);
    	}
    	for(int i=1;i<=n;i++)
    		printf(i==n?"%d\n":"%d ", ret[i]);
    }
}