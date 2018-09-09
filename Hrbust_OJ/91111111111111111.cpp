#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
int n;
struct node
{
    int num,val;
}a[maxn];
bool cmp(node a,node b) {
    return a.val<b.val;
}
int vis[maxn];
int b[maxn*maxn];
int c[maxn];
int main()
{
    while(~scanf("%d",&n)){
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].val);
            a[i].num=i;
            c[i]=a[i].val;
            vis[i]=i-1;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++) {
            b[a[i].val]=a[i].num;
        }
        int j=1;
        int f=0;
        int ff=0;
        int index;
        for(int i=1;i<=((1+n)*n)/2;i++) {
            if(b[i]) {
                if(vis[b[i]]!=0) ff=1;
                continue;
            }
            index=a[j].num;
            if(vis[j]==0) j++;
            else vis[j]--;
        }
        if(ff==1)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}