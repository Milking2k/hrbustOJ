#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

struct node{
    int l,r;
}c[maxn];
bool cmp(node a,node b) {
    if(a.l!=b.l) return a.l<b.l;
    return a.r<b.r;
}
int ans[maxn];
int T,n,m;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) {
            scanf("%d%d",&c[i].l,&c[i].r);
        }
        sort(c+1,c+1+m,cmp);

        for(int i=1;i<=n;i++){
            ans[i]=1;
        }

        node tocnt = c[1];
        int maxnum=1;
        int addpos=0;
        for(int i=tocnt.l;i<=tocnt.r;i++){
            ans[i]=maxnum;
            maxnum++;
            addpos = i+1;
        }

        for(int i=2;i<=m;i++){
            if(c[i].r <= tocnt.r){
                continue;
            }
            if(c[i].l > tocnt.r){
                tocnt = c[i];
                maxnum=1;
                for(int j=tocnt.l;j<=tocnt.r;j++){
                    ans[j] = maxnum;
//                    printf("sss:%d\n",i);
                    maxnum++;
                    addpos = j+1;
                }
            }
            else{
                for(int j = tocnt.l; j<c[i].l;j++){
//                    trans[pos] = ans[j];
//                    printf("%d\n",ans[j]);
                    q.push(ans[j]);
                }

                for(int j=tocnt.r+1;j<=c[i].r && !q.empty();j++){
//                    ans[j] = trans[j-tocnt[i].r-1+1];
                    ans[j] = q.top();
                    q.pop();
                    addpos=j+1;
                }
//                for(int k=1;k<=n;k++){
//                    printf(k<n?"%d_":"%d\n",ans[k]);
//                }
                for(int j=addpos;q.empty()&&j<=c[i].r;j++){
                    ans[j] = maxnum;
                    maxnum++;
                    addpos = j+1;
                }
                tocnt = c[i];
            }
        }
        for(int i=1;i<=n;i++){
            printf(i<n?"%d ":"%d\n",ans[i]);
        }
    }
}