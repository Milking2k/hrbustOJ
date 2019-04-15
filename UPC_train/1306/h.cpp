#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x, y;
} a[35];
double cross(point a, point b, point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &a[i].x, &a[i].y);
        }
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            double as = cross(a[(i - 1 + n) % n], a[i], a[(i + 1) % n]);
            if (as < 0)
                ok = false;
        }
        if (ok)
            puts("fight");
        else
            puts("run");
    }
    return 0;
}
