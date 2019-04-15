#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
ll n, m, k, mxnum, senum;
ll a[N];


int main()
{
    mxnum = 0;

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    cout << (k * a[n] + a[n - 1]) * (m / (k + 1)) + (m % (k + 1)) * a[n];
    return 0;
}