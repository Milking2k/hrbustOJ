#include <bits/stdc++.h>
using namespace std;

const int maxn = 407;
int a[maxn][maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%1d", &a[i][j]);
            }
        }
        int ans = 0;
        for (int i = m; i >= 1; i--)
        {
            bool ok = true;
            int k = -1;
            for (int j = 1; j <= n; j++)
            {
                if (a[j][i] == 0 && k == -1)
                {
                    ok = false;
                    k = j;
                }
            }
            if (!ok)
            {
                ans++;
                for (int j = 1; j <= n; j++)
                    a[j][i] = 1;
                for (int j = 1; j <= m; j++)
                    a[k][j] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
