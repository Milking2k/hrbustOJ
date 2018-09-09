#include<bits/stdc++.h>
using namespace std;

int n,sum=0;
int check[3][28]={0},ans[17];
void dfs(int line)
{
    if(line>n)
    {
        sum++;
        if(sum>3) return;
        for(int i=1;i<=n;i++)
            i==n? cout<<ans[i]<<endl : cout<<ans[i]<<" ";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(check[0][i]==0 && check[1][line+i]==0 && check[2][line-i+n]==0)
        {
            ans[line]=i;
            check[0][i]=1 , check[1][line+i]=1 , check[2][line-i+n]=1;
            dfs(line+1);
            check[0][i]=0 , check[1][line+i]=0 , check[2][line-i+n]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    dfs(1);
    cout << sum << endl;
    return 0;
}
