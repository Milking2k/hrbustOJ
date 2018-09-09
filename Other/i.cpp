#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long LL;



int n;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    LL ans=1;
    for(int i=1;i<=n;i++)
    {
        ans = (ans * 1ll * i)%MOD;
    }
    cout << ans << endl;
    return 0;
}




