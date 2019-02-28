#include <bits/stdc++.h>
using namespace std;
const int N = 200007;

int n;
pair<int, int> a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        // printf(":%d %d\n", a[i].first, a[i].second);
    }
    sort(a + 1, a + 2 * n + 1);

    int x1 = a[1].second;
    int y1 = a[2].second;
    long long ans = x1 - 1 + y1 - 1;

    for (int i = 3; i <= 2 * n; i += 2) {
        int x2 = a[i].second;
        int y2 = a[i + 1].second;
        int ans1 = abs(x1 - x2) + abs(y1 - y2);
        int ans2 = abs(x1 - y2) + abs(y1 - x2);
        if (ans1 < ans2) {
            ans += ans1;
            x1 = x2, y1 = y2;
        }
        else {
            ans += ans2;
            x1 = y2, y1 = x2;
        }

    }
    cout << ans;
    return 0;
}