#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for(int i=0;i<s.length()-3;i++)
    {
        if(s[i]=='.') continue;
        if(s[i] != s[i+1] && s[i]!=s[i+2] && s[i+1]!=s[i+2])
        {
            return !printf("Yes\n");
        }
    }
    return !printf("No\n");
}
