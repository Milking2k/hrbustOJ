#include <bits/stdc++.h>
using namespace std;
const int maxn=60;
const int inf=1e9;
int ma[maxn][maxn];
int s,t;
int main(int argc, char const *argv[])
{
	int m;
    while(scanf("%d",&m) != EOF) {
        scanf("%d%d",&s,&t);
        for(int i=0;i<maxn;i++) {
            for(int j=0;j<maxn;j++) {
                ma[i][j]=inf;
            }
        }
        int a,b,c;
        while(scanf("%d",&a) != EOF && a) {
            scanf("%d%d",&b,&c);
            ma[a][b]=c;
            ma[b][a]=c;
        }
		for(int k=1;k<=m;k++) {
			for(int i=1;i<=m;i++) {
			    for(int j=1;j<=m;j++) {
			        ma[i][j] = min(ma[i][j],ma[i][k]+ma[k][j]);
			    }
			}
		}
        printf("%d\n",ma[s][t]);
    }
	return 0;
}