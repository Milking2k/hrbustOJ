#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    int a[107];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i += 2) {
        cout << a[i] << " ";
    }

    if (n%2) { // odd
        n--;
    }

    for (int i = n; i > 0; i -= 2) {
        cout << a[i] << " ";
    }

}


int main()
{
    solve();

    return 0;
}