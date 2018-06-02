#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if(n>(m/2))
        cout << m/2 << endl;
    else
        cout << (m-2*n)/4+n << endl;
    return 0;
}



