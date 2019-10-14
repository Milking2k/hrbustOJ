#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int main()
{
    int n, m = 0, j = 1;
    int a[N];
    scanf("%d",&n);
    for (size_t i = 1; i <= n; ++i) {
        scanf("%d",a+i);
        if (a[i] > m) {
            m = a[i];
            j = i;
        }
    }
    bool bflag = 1, bans = 0;
    for (size_t i = 1; i <= n; ++i) {
        if (i == j + 1) 
            bflag = 0;
        if (bflag && a[i-1] > a[i]) {
            bflag = 0;
            bans = 1;
        }
        if (!bflag && a[i-1] < a[i]) {
            bans = 1;
            break;
        }
    }
    if (bans)
        printf("NO\n");
    else 
        printf("YES\n");
    return 0;
}