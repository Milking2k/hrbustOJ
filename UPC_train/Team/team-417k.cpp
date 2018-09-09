#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int T;
int n,m;
char ma[10][10];
 
int main () {
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>ma[i][j];
            }
        }
        int f=0;
        int x=1,y=1;
        if(ma[x][y]!='#') {
            f=1;
        }
        while(1 && f==0) {
           //cout<<x<<" "<<y<<" "<<f<<endl;
            if(x==n&&y==m&&ma[x][y]=='#') {
                ma[x][y]='*';
                break;
            }
            if(ma[x][y+1]=='#' && ma[x+1][y]=='#') {
                f=1;
                break;
            }
            if(ma[x][y+1]=='#') {
                ma[x][y]='*';
                y=y+1;
                continue;
            }
            if(ma[x+1][y]=='#') {
                ma[x][y]='*';
                x=x+1;
                continue;
            }
            if(x==n) {
                if(ma[x][y+1]!='#') {
                    f=1;
                    break;
                }
                if(ma[x][y+1]=='#') {
                    ma[x][y]='*';
                    y=y+1;
                    continue;
                }
            }
            if(y==m) {
                if(ma[x+1][y]!='#') {
                    f=1;
                    break;
                }
                if(ma[x+1][y]=='#') {
                    ma[x][y]='*';
                    x=x+1;
                    continue;
                }
            }
 
            if(x==n && y==m ) {
                if(ma[x][y] != '#') {
                    f=1;
                    break;
                }
                else {
                    ma[x][y]='*';
                    break;
                }
            }
            if(ma[x+1][y]!='#' && ma[x][y+1]!='#') {
                f=1;
                break;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                //cout<<ma[i][j];
                if(ma[i][j]=='#') {
                    f=1;
                }
            }
            //cout<<endl;
        }
        if(f==1) {
            printf("Impossible\n");
        }
        else{
            printf("Possible\n");
        }
    }
 
}