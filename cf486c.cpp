/*======================================
    codeforces contest#486 problem C
    2018.6.4    jelech  writing
======================================*/
#include <bits/stdc++.h>
using namespace std;

#define FOR1(i,n) for(int i=1;i<=n;i++)

typedef long long ll;

int n;
string emt[107];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> emt[i];

    sort(emt+1,emt+1+n,[](string a, string b){return a.size()<b.size();});
    for(int i=2;i<=n;i++)
    {
        if(emt[i].find(emt[i-1]) == -1)
            return !(cout << "NO" << endl);
    }

    cout << "YES" << endl;
    for(int i=1;i<=n;i++)
        cout << emt[i] << endl;

    return 0;
}

