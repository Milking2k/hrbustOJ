#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        map<int, int> mp;
        mp.clear();
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            mp[x]++;
        }
        int ans1 = -1, ans2 = -1;
        map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            int as = it->second;
            if (it->first == 0)
                continue;
            if (as == 1)
            {
                if (ans1 == -1)
                    ans1 = it->first;
                else
                    ans2 = it->first;
            }
        }
        if (ans1 < ans2)
            swap(ans1, ans2);
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}