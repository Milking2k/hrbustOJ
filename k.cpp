#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;

ll n;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    ll ans=1;
    ans = 2*(n/11);
    if(n%11>=7) cout << ans+2;
    else if(n%11<7 && n%11>0) cout << ans+1;
    else cout << ans;
    cout << endl;

    return 0;
}





