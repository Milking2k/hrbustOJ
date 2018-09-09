#include <bits/stdc++.h>
using namespace std;

int n,m;
int main()
{
//    ios::sync_with_stdio(false);
    string s;
    cin >> n >> m;
    cin >> s;
    bool flag = false;
    for(int i=0;i+m<n;i++)
    {
        if(s[i]=='.' && s[i+m]=='.')
        {
            s[i] = '0', s[i+m] = '1';
            flag = true;
            break;
        }
        else if(s[i]=='.')
        {
            s[i] = (1-1*((int)s[i+m]-'0'))+'0';
            flag = true;
            break;
        }
        else if(s[i+m]=='.')
        {
            s[i+m] = (1-1*((int)s[i]-'0'))+'0';
            flag = true;
            break;
        }
    }
    if(flag)
        for(int j=0;j<n;j++)
            printf(s[j]=='.' ? "0":"%c",s[j]);
    else printf("No\n");
    return 0;
}

