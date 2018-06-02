#include<bits/stdc++.h>
using namespace std;

int emt[100],v[100];
int n,cnt,len;

bool dfs(int stick,int cab,int last) // 正在拼第几根，这根的当前长度，上一根小木棍长度
{
    if(stick>cnt) return true;
    if(cab==len) return (dfs(stick+1,0,1));
    int fail=0;
    for(int i=last;i<=n;i++)
        if(!v[i] && cab+emt[i]<=len && fail!=emt[i]) //没有访问过，长度小于，和上次失败的长度不相等的
        {
            v[i] = 1;
            if(dfs(stick,cab+emt[i],i+1)) return true;
            fail=emt[i];
            v[i]=0;
            if(cab==0) return false;
        }
    return false;//所有分支都失败
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n && n)
    {
        int sum=0,val=0;
        for(int i=1;i<=n;i++)
        {
            cin >> emt[i];
            sum += emt[i];
            val = max(val,emt[i]);
        }
        sort(emt+1,emt+1+n);
        reverse(emt+1,emt+1+n);
        for(len = val;len<=sum;len++)
        {
            if(sum%len) continue;
            cnt = sum/len;
            memset(v,0,sizeof(v));
            if(dfs(1,0,1))break;
        }
        cout << len << endl;
    }
    return 0;
}
