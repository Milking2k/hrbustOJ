#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> b(N+1,0);
    for (int i = 1; i <= N; ++i)
    {
        ll a;
        cin >> a;
        b[a] = i;
    }
    set<ll> s;
    s.insert(0);
    s.insert(N+1);
    ll ans=0;
    for (int i = 1; i <= N; ++i)
    {
        auto it = s.lower_bound(b[i]);
        ans += i*(*it-b[i]) * (b[i] - *(--it));
        s.insert(b[i]);
    }
    cout << ans << endl;
    return 0;
}