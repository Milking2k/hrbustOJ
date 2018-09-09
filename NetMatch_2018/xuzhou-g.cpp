#include <bits/stdc++.h>
#define read(x) scanf("%d", &x)
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 4;
struct node
{
    int x, y;
    int id;
} a[maxn];
bool cmp(node a, node b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
int stk[maxn], top;
int numx[maxn];
int numy[maxn];
int b[maxn];
int main()
{
    int n;
    read(n);
    a[0].x = 0;
    a[0].y = 0;
    a[0].id = 0;
    for (int i = 1; i <= n; i++)
    {
        read(a[i].x);
        read(a[i].y);
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        b[i] = a[i].id;
    top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (stk[top - 1] < b[i] && top > 0)
            top--;
        stk[top++] = b[i];
        numx[i] = top;
    }
    reverse(b + 1, b + 1 + n);
    a[n + 1].x = 0;
    a[n + 1].y = 0;
    top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (stk[top - 1] < b[i] && top > 0)
            top--;
        stk[top++] = b[i];
        numy[i] = top;
    }

    ll ans = 0;
    ll cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        cnt = a[i].y - a[i + 1].y;
        ans += numx[i] * cnt;
    }

    cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        cnt = a[n - i + 1].x - a[n - i].x;
        ans += numy[i] * cnt;
    }
    printf("%lld\n", ans);

    return 0;
}
/*
4
1 4
4 1
2 3
3 2
*/