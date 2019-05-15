#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5e5 + 7;
int l[maxn], r[maxn];
int stk[maxn];
int top;
LL pre[maxn];
int a[maxn];
LL maxe[maxn << 2], minn[maxn << 2];
int n;
void build(int i, int l, int r)
{
    if (l == r)
    {
        maxe[i] = minn[i] = pre[l - 1];
        return;
    }
    //    minn[i] = 0x3f3f3f3f; maxe[i] = -0x3f3f3f3f;
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    minn[i] = min(minn[i << 1], minn[i << 1 | 1]);
    maxe[i] = max(maxe[i << 1], maxe[i << 1 | 1]);
}

LL query1(int i, int L, int R, int l, int r)
{
    //    printf("test i == %d L == %d R == %d l == %d r == %d\n",i, L, R, l, r);
    if (l <= L && R <= r)
    {
        return minn[i];
    }
    int mid = (L + R) >> 1;
    LL res = 0x3f3f3f3f3f3f3f3fLL;
    //    if(l <= mid) res = min(res, query1(i << 1, L, mid, l, r));
    //    if(mid < r) res = min(res, query1(i << 1 | 1, mid + 1, R, l, r));
    if (r <= mid)
        return query1(i << 1, L, mid, l, r);
    else if (l > mid)
        return query1(i << 1 | 1, mid + 1, R, l, r);
    else
        return min(query1(i << 1, L, mid, l, r),
                   query1(i << 1 | 1, mid + 1, R, l, r));
    //    return res;
}
LL query2(int i, int L, int R, int l, int r)
{
    if (l <= L && R <= r)
    {
        return maxe[i];
    }
    int mid = (L + R) >> 1;
    LL res = -0x3f3f3f3f3f3f3f3fLL;
    if (l <= mid)
        res = max(res, query2(i << 1, L, mid, l, r));
    if (mid < r)
        res = max(res, query2(i << 1 | 1, mid + 1, R, l, r));
    return res;
}
int main()
{
    while (~scanf("%d", &n))
    {
        //        memset(minn, 0x3f,sizeof(minn));
        //        memset(maxe, -0x3f,sizeof(maxe));
        pre[0] = 0;
        top = 0;
        a[0] = -0x3f3f3f3f;
        a[n + 1] = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            pre[i] = pre[i - 1] + a[i];
            //            l[i] = i; r[i] = i;
        }
        build(1, 1, n + 1);
        top = 0;
        //        stk[++top] = a[1];
        for (int i = 1; i <= n; i++)
        {
            while (a[i] <= a[stk[top]] && top)
                top--;
            if (top == 0)
                l[i] = 0;
            else
                l[i] = stk[top];
            stk[++top] = i;
        }
        //        for (int i = 1; i <= n;i ++) {
        //            printf("%d ",l[i]);
        //        }
        //        puts("");
        top = 0;
        for (int i = n; i; i--)
        {
            while (a[i] <= a[stk[top]] && top)
                top--;
            if (top == 0)
                r[i] = n;
            else
                r[i] = stk[top] - 1;
            stk[++top] = i;
        }
        //        for (int i = 1; i <= n; i++) {
        //            printf("%d ",r[i]);
        //        }
        //        puts("");
        //        RMQ();
        //        for (int i = 1; i <= n; i++) {
        //            printf("%lld ", pre[i]);
        //        }
        //        puts("");
        long long ans = 0;
        int x, y;
        int k;
        for (int i = 1; i <= n; i++)
        {
            LL as, qw;
            if (a[i] < 0)
            {
                x = l[i], y = i - 1;
                //            LL as = min(minn[x][k],minn[y-(1<<k)+1][k]);
                as = query2(1, 1, n + 1, x + 1, y + 1);
                //                printf("test");
                x = i, y = r[i];
                //            LL qw = max(maxe[x][k],maxe[y-(1<<k)+1][k]);
                qw = query1(1, 1, n, x + 1, y + 1);
            }
            else
            {

                x = l[i], y = i - 1;
                as = query1(1, 1, n + 1, x + 1, y + 1);
                //                printf("test");
                x = i, y = r[i];
                //            LL qw = max(maxe[x][k],maxe[y-(1<<k)+1][k]);
                qw = query2(1, 1, n, x + 1, y + 1);
            }
                       printf("%d x == %d r == %d as == %lld qw == %lld %lld res == %lld\n", a[i], x, y, as, qw, qw - as, a[i] * (qw - as));
            ans = max(ans, 1LL * a[i] * (qw - as));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
1
-5
2
-5 -5
8
1 1 9 -1 -10 -1 -1 -1

8
-1 -1 -9 1 10 1 1 1
*/