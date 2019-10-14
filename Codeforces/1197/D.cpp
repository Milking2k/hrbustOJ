#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
typedef long long ll;
int n, m, k;
int a[N];
long long tot = 0;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (size_t i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }

    
    ll ans = 0;
    
    for (size_t i = 1; i <= m; ++i) {
        ll tot = 0, temp = 0;
        for(size_t j = i; j <= n; ++j) {
            if ((i == m && j % m == 0) || j % m == i) {
                temp = min(temp, tot);
                tot -= k;
            }
            tot += a[j];
            ans = max(ans, tot - temp);
        }
    }

    printf("%lld\n", ans);

    return 0;
}