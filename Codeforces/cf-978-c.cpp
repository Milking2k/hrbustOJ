#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,m;
LL emt[200007];
LL sum[200007];
int main()
{
    cin>>n>>m;
    emt[0]=0;
    sum[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin >> emt[i];
        sum[i] = emt[i]+sum[i-1];
    }
    int pos=1;
    LL x;
    for(int i=1; i<=m; i++)
    {
        cin >> x;
        while   (x>sum[pos]) pos++;
//            printf("%d %LLd\n",pos,x-sum[pos-1]);
        cout << pos <<" "<< x-sum[pos-1] << endl;
    }
}