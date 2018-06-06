#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    int len = s.size();
    bool flag = true;
    int cnt=0;
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(flag && s[i]=='A')
        {
            cnt=i;
            flag = false;
        }
        else if(!flag && s[i] == 'Z')
        {
            ans = max(ans,i-cnt+1);
        }
    }
    cout << ans << endl;
    return 0;
}


