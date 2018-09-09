#include<bits/stdc++.h>
using namespace std;

struct node
{
    int pos,val;
};
int n;
int emt[100007];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    memset(emt,0,sizeof(emt));
    int maxnum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        maxnum=max(maxnum,x);
        emt[x]++;
    }
    int cnt1=0,cnt2=0;
    int sum=0;

//        cout << maxnum << ".--." << endl;
    for(int i=1;i<=max(n,maxnum);i++)
    {
        if(emt[i]>1 && emt[i]%2==0) cnt1++;
        if(emt[i]>0) sum++;
    }
    int ans = cnt1%2;
//        cout << sum << ".." << endl;
//        cout << cnt1 << ".-." << endl;
    cout << sum-ans << endl;


    return 0;
}
