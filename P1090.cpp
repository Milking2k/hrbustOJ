#include<bits/stdc++.h>
using namespace std;
//-----------------------------
int n;
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
//        scanf("%d",&emt[i]);
        q.push(x);
    }
    long long sum=0;
    while(q.size()>1)
    {
        int cnt1 = q.top();
        q.pop();
        int cnt2 = q.top();
        q.pop();
        sum+=cnt1+cnt2;
        q.push(cnt1+cnt2);
    }
    printf("%d\n",sum);
    return 0;
}
