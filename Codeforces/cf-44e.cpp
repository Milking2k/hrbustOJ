#include<bits/stdc++.h>
using namespace std;

const int N = 500*1000+13;

int f[N];

//数状数组
void add(int x)
{
    for(int i=x;i<N;i |= i+1) ++f[i];
}
int sum(int x)
{
    int res=0;
    for(int i=x;i>=0;i=(i&(i+1))-1) res += f[i];
    return res;
}
int get(int l,int r)
{
    return (l>r?0:sum(r)-sum(l-1));
}

int main()
{
    int n,k,d;
    scanf("%d%d%d",&n,&k,&d);
    vector<int> a(n);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a.begin(),a.end());

    vector<int> dp(n+1,0);

    dp[0]=1;
    add(0);

    int l=0;
    for(int i=0;i<n;i++)
    {
        while(l<i&&a[i]-a[l]>d) ++l;
        dp[i+1]=(get(l,i-k+1) >= 1);
        if(dp[i+1]) add(i+1);
    }
    puts(dp[n]?"YES":"NO");
    return 0;
}