#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1005;
struct node {
    int xx,yy;
    int data;
}c[maxn*maxn];
int a[maxn][maxn];
int b[maxn];
char s[10];
int d[maxn];
int num=0;
void get(int x) {
    num=0;
    for(int i=1;i<=sqrt(x);i++) {
        if(x%i==0) {
            d[++num]=i;
            d[++num]=x/i;
        }
    }
}


int main() {
    int T;
    read(T);
    int cas=0;
    while(T--) {
        int ccnt=0;
        int n,m;
        read(n),read(m);
        int cnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>s;
                if(s[0]=='?') {
                    a[i][j]=0;
                }
                else {
                    a[i][j]=atoi(s);
                    cnt++;
                    b[cnt]=a[i][j];
                    ccnt++;
                    c[ccnt].xx=i;
                    c[ccnt].yy=j;
                    c[ccnt].data=a[i][j];
                }
            }
        }
//        for(int i=1;i<=n;i++) {
//            for(int j=1;j<=m;j++) {
//                cout<<a[i][j]<<" ";
//            }
//            puts("");
//        }
//        cout<<cnt<<endl;
        printf("Case #%d: ",++cas);
        if(cnt==0) {
            puts("Yes");
        }
        else if(cnt==1) {
            get(b[1]);
            int maxx=-1;
            int f=0;
            int xx,yy;
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                    if(a[i][j]) {
                        xx=i;
                        yy=j;
                        break;
                    }
                }
            }
            for(int i=1;i<=num;i++) {
//                maxx=max(maxx,d[i]);
                if(d[i]>=xx && b[1]/d[i]>=yy)f=1;
            }
            if(f==1) {
                puts("Yes");
            }
            else puts("No");
        }
        else if(cnt==2) {
            get(b[1]);
            int f=0;
            for(int i=1;i<=num;i++) {
                int tx=d[i];
                int ty=b[1]/d[i];
                int dx=c[2].xx-c[1].xx;
                int dy=c[2].yy-c[1].yy;
                if((tx+dx)*(ty+dy) == b[2]) {
                    if((tx+dx >= c[2].xx) && (ty+dy >= c[2].yy) && tx>=c[1].xx && ty>=c[1].yy) {
                        f=1;
                        break;
                    }
                }
            }
            if(f==1) {
                puts("Yes");
            }
            else puts("No");
        }
        else {
            get(b[1]);
            int f=0;
            int px,py;
            for(int i=1;i<=num;i++) {
                int tx=d[i];
                int ty=b[1]/d[i];
                int dx1=c[2].xx-c[1].xx;
                int dy1=c[2].yy-c[1].yy;
                int dx2=c[3].xx-c[1].xx;
                int dy2=c[3].yy-c[1].yy;
                if((tx+dx1)*(ty+dy1) == b[2] && (tx+dx2)*(ty+dy2) == b[3]) {
                    px=tx;
                    py=ty;
                    f=1;
                    break;
                }
            }
//            cout<<px<<" "<<py<<" "<<f<<endl;
            if(f==0) {
                puts("No");
                continue;
            }
//            puts("");
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                    if(a[i][j]) {
                        int dxx=i-c[1].xx;
                        int dyy=j-c[1].yy;
//                        cout<<px<<" "<<py<<" "<<px+dxx<<" "<<py+dyy<<" "<<a[i][j]<<endl;
                        if((px+dxx)*(py+dyy) == a[i][j] && (px+dxx)>=i && (py+dyy)>=j) {
                            continue;
                        }
                        else {
//                            cout<<i<<" "<<j<<endl;
                            f=0;
                            break;
                        }
                    }
                }
            }
            if(f==0) {
                puts("No");
            }
            else puts("Yes");
//            cout<<px<<" "<<py<<endl;
        }
    }
}