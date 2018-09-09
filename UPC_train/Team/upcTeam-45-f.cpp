#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
struct node
{
    int x,y;
    node(){};
    node(int _x,int _y){
        x=_x,y=_y;
    }
}a[1005],b[1005];
 
int rr[1005];
 
LL dist(node aa,node bb)
{
    return (LL)(aa.x-bb.x)*(aa.x-bb.x)+(LL)(aa.y-bb.y)*(aa.y-bb.y);
}
int solve(node x,int r)
{
    int cnt=0;
    for(int i=1;i<=n;i++){
        LL dis=dist(x,a[i]);
        if((LL)r*r>=dis){
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        for(int i=1;i<=n;i++){
            int t1,t2;
            char ch;
            cin>>ch;
            scanf("%d",&t1);
            cin>>ch;
            scanf("%d",&t2);
            cin>>ch;
            a[i]=node(t1,t2);
        }
//        printf("test\n");
        for(int i=1;i<=m;i++){
            int t1,t2;
            char ch;
            cin>>ch;
            scanf("%d",&t1);
            cin>>ch;
            scanf("%d",&t2);
            cin>>ch;
            b[i]=node(t1,t2);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&rr[i]);
        }
        for(int i=1;i<=m;i++){
            if(i>1)printf(" ");
            printf("%d",solve(b[i],rr[i]));
        }
        puts("");
    }
	return 0;
}