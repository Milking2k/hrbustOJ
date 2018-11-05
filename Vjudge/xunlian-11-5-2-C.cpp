#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;++i)

const int N = 2e5+7;
int n,m;
char s[N];

int type[N];

bool vis[N];

int wei[N][2];

set<int> vc[N];

void add(int x, int y)
{
    int sz = vc[x].size();
    vc[x].insert(y);

    if(sz!=vc[x].size())
        wei[x][type[y]]++;// 0 is red
}

queue<int> Q;
bool topsort()
{
    int ans=0;
    rep(i,1,n+1)
    {
        if(wei[i][0]<=0 || wei[i][1]<=0){
            Q.push(i);
            vis[i]=1;
            ans++;
        }
    }

    while(Q.size()){
        int cur = Q.front();
        Q.pop();

        for(auto v:vc[cur]){
            wei[v][type[cur]]--;
            if(vis[v]) continue;
            if(wei[v][0]<=0 || wei[v][1]<=0){
                Q.push(v);
                vis[v]=1;
                ans++;
            }

        }
    }
    return ans!=n;
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    rep(i,0,n)
    {
        type[i+1]=(s[i]-'A');
    }
    rep(i,1,m+1)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    if(topsort())puts("Yes");
    else puts("No");

    return 0;
}