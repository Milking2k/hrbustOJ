#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;
const int mod = 1000000007;

int n, cnt;
int a[maxn], b[maxn], c[maxn], dp[maxn];

int bin_search(int num)
{
    int l = 0, r = cnt - 1, m;
    while(l <= r)
    {
        m = (l+r) >> 1;
        if(b[m] > num) r = m - 1;
        else if(b[m] < num) l = m + 1;
        else return m;
    }
    return -1;
}

int lowbit(int t)
{
    return t & (-t);
}

int getsum(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans = (ans + c[x]) % mod;
        x -= lowbit(x);
    }
    return ans;
}

void update(int x, int val)
{
    while(x <= cnt)
    {
        c[x] = (c[x] + val) % mod;
        x += lowbit(x);
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        cnt = 1;
        sort(b, b+n);
        for(int i = 1; i < n; i++)
            if(b[i] != b[i-1])
                b[cnt++] = b[i];
        memset(c, 0, sizeof(c));
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int pos = bin_search(a[i]);
            dp[i] = (getsum(pos) + 1) % mod;
            ans = (ans + dp[i]) % mod;
            update(pos + 1, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
