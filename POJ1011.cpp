#include<bits/stdc++.h>
using namespace std;

int emt[100],v[100];
int n,cnt,len;

bool dfs(int stick,int cab,int last) // ����ƴ�ڼ���������ĵ�ǰ���ȣ���һ��Сľ������
{
    if(stick>cnt) return true;
    if(cab==len) return (dfs(stick+1,0,1));
    int fail=0;
    for(int i=last;i<=n;i++)
        if(!v[i] && cab+emt[i]<=len && fail!=emt[i]) //û�з��ʹ�������С�ڣ����ϴ�ʧ�ܵĳ��Ȳ���ȵ�
        {
            v[i] = 1;
            if(dfs(stick,cab+emt[i],i+1)) return true;
            fail=emt[i];
            v[i]=0;
            if(cab==0) return false;
        }
    return false;//���з�֧��ʧ��
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
