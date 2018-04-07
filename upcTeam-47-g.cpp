#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node{
    int x,y;
    int t;
    int time;
}a[maxn];
int n,m;
int sx,sy,ex,ey;
int vis[maxn];
int bfs(){
    memset(vis,0,sizeof(vis));
    int st=(sx-1)*m+sy;
    int ed=(ex-1)*m+ey;
    queue<node> q;
    node fir;
    fir.x=sx,fir.y=sy,fir.t=a[st].t,fir.time=0;
    q.push(fir);
    vis[st]=0;
    while(!q.empty()) {
        node temp=q.front();
        q.pop();
        int nowx=temp.x,nowy=temp.y,nowt=temp.t,time=temp.time;
        //cout<<nowx<<" "<<nowy<<" "<<time<<endl;
        if((nowx-1)*m+nowy==ed) {
            return 1;
        }
        if((time+nowt)%2==0) {
            //cout<<"1111"<<endl;
            int nx1=nowx+1,nx2=nowx-1;
            if(nx1>=1&&nx1<=n&&!vis[(nx1-1)*m+nowy]) {
                node tt;
                tt.x=nx1;
                tt.y=nowy;
                vis[(nx1-1)*m+nowy]=vis[(nowx-1)*m+nowy]+1;
                tt.time=time+1;
                tt.t=a[(nx1-1)*m+nowy].t;
                q.push(tt);
            }
            if(nx2>=1&&nx2<=n&&!vis[(nx2-1)*m+nowy]) {
                node tt;
                tt.x=nx2;
                tt.y=nowy;
                vis[(nx2-1)*m+nowy]=vis[(nowx-1)*m+nowy]+1;
                tt.time=time+1;
                tt.t=a[(nx2-1)*m+nowy].t;
                q.push(tt);
            }
        }
        else {
            //cout<<"2222"<<endl;
            int ny1=nowy+1,ny2=nowy-1;
            if(ny1>=1&&ny1<=m&&!vis[(nowx-1)*m+ny1]) {
                node tt;
                tt.x=nowx;
                tt.y=ny1;
                vis[(nowx-1)*m+ny1]=vis[(nowx-1)*m+nowy]+1;
                tt.time=time+1;
                tt.t=a[(nowx-1)*m+ny1].t;
                q.push(tt);
            }
            if(ny2>=1&&ny2<=m&&!vis[(nowx-1)*m+ny2]) {
                node tt;
                tt.x=nowx;
                tt.y=ny2;
                vis[(nowx-1)*m+ny2]=vis[(nowx-1)*m+nowy]+1;
                tt.time=time+1;
                tt.t=a[(nowx-1)*m+ny2].t;
                q.push(tt);
            }
        }
    }
    return 0;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int t;
                scanf("%d",&t);
                a[(i-1)*m+j].t=t;
                a[(i-1)*m+j].x=i;
                a[(i-1)*m+j].y=j;
                a[(i-1)*m+j].time=0;
            }
        }
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        int ans=bfs();
        if(ans) {
            printf("%d\n",vis[(ex-1)*m+ey]);
        }
        else {
            printf("-1\n");
        }
    }

}