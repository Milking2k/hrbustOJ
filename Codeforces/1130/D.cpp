#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
const int M = 20007;

int n, m;
int last[N];
vector<int> G[N];

int dis(int x, int y)
{
    // return x >= y ? x - y : x - y + n;
    return (x - y + n) % n;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }

    for (int i = 1; i <= n; ++i) {
        last[i] = n - 1;
        for (int j = 0; j < (int)G[i].size(); ++j) {
            last[i] = min(last[i], dis(G[i][j], i));
        }
    }

    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 1; j <= n; ++j) {
            if(G[j].size()){
                ans = max(ans, dis(j, i) + n * ((int)G[j].size() - 1) + last[j]);
            }
        }
        cout << ans << " ";
    }

        return 0;
}