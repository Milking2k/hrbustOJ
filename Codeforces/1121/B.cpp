#include<bits/stdc++.h>
using namespace std;
const int N = 1007;

int n;
int a[N];
map<int, int> counts;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i ) {
        for (int j = i + 1; j <= n; ++j) {
            int temp = a[i] + a[j];
            counts[temp]++;
            ans = max(ans, counts[temp]);
        }
    }

    cout << ans << endl;
    return 0;
}