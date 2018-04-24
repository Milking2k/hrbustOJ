/*
P1563 玩具谜题
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MAX_M 100000

int main()
{
    char er_dir[MAX_N] = {0};       // 存储朝向
    long n, m, i, cur = 0, a, s;
    char er_occ[MAX_N][11] = {{0}};     // 存储职业
    scanf("%ld%ld", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%ld%s", er_dir+i, er_occ[i]);
    }
    for (i = 0; i < m; ++i) {
        scanf("%ld%ld", &a, &s);        // 获取左右和序数
        if (er_dir[cur] == a)       // 向外朝左与向内朝右是一致的，反之亦然
        {
            s *= -1;
        }
        cur = (cur + n + s) % n;
    }
    printf("%s", er_occ[cur]);
    return 0;
}