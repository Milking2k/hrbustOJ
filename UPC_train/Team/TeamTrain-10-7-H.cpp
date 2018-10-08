#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e6+4;
int a[maxn];
int vis1[maxn];
int stk[maxn];
int top=0;
int pre[maxn];


int dp1[maxn][20];
int mm[maxn];
void RMQ_init(int n)
{
    mm[0]=-1;
    for(int i=1;i<=n;i++){
       mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
       dp1[i][0]=pre[i];
    }
    for(int j=1;j<=mm[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp1[i][j]=min(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQ_Min(int L,int R)
{
    int k=mm[R-L+1];
    return min(dp1[L][k],dp1[R-(1<<k)+1][k]);
}

int main() {
    int n,m,q;
    read(n),read(m),read(q);
    for(int i=1;i<=n;i++) {
        read(a[i]);
    }
    for(int i=1;i<=n;i++){
        if(top==0){
            stk[++top]=i;
            continue;
        }
        if(a[i]&1){
            int as=a[i]-1;
            if(a[stk[top]]==as){
                vis1[stk[top]]=1;
                vis1[i]=-1;
                top--;
            }
            else {
                vis1[i]=-99999999;
            }
        }
        else{
            stk[++top]=i;
        }
    }
    for(int i=1;i<=top;i++){
        vis1[stk[i]]=-99999999;
    }
    pre[0]=0;
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+vis1[i];
    RMQ_init(n);
    for(int i=1;i<=q;i++){
        int l,r;
        read(l),read(r);
        int as=pre[r]-pre[l-1];
        int qw=RMQ_Min(l,r)-pre[l-1];
        if(as==0&&qw>=0)puts("Yes");
        else puts("No");
    }
    return 0;
}
