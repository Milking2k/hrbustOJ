#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    pair<int, int> score[10007];

    cin >> n;
    score[0] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> score[i].first >> score[i].second;
    }

    int ans = 1;
    int pre1 = 1, pre2 = 1;
    for (int i = 1; i <= n; ++i) {
        while (pre1 <= score[i].first && pre2 <= score[i].second) {
            ans++;
            pre1++;
            pre2++;
        }
        {
            pre1 = max(pre1, score[i].first);
            pre2 = max(pre2, score[i].second);
        }

        if (pre1 > pre2) pre2 = pre1;
        else pre1 = pre2;
    }

    cout << ans << endl;
        return 0;
}