#include <bits/stdc++.h>
using namespace std;


string str[20];
int use[27],length=0,n;

int canlink(string a,string b)
{
    for(int i=1;i<min(a.length(),b.length());i++)
    {
        int flag = 1;
        for(int j=0;j<i;j++)
            if(a[a.length()-i+j]!=b[j])
                flag = 0;
        if(flag) return i;
    }
    return 0;
}
int solve(string strnow, int lennow)
{
    length = max(lennow,length);
    for(int i=0;i<n;i++)
    {
        if(use[i] >= 2)continue;
        int c = canlink(strnow, str[i]);
        if(c>0)
        {
            use[i]++;
            solve(str[i],lennow+str[i].length()-c);
            use[i]--;
        }
    }
}
int main()
{
    cin >> n;
    for(int i=0;i<=n;i++)
        use[i] = 0,cin>>str[i];

    solve(' '+str[n],1);

    cout << length;
    return 0;
}
