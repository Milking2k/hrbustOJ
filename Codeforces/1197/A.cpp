#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int T,n,k;
int a[N];
int main()
{
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (size_t i = 1; i <= n; ++i) {
            scanf("%d", a+i);
        }
        if (n <= 2) {
            printf("0\n");
            continue;
        }
        sort(a+1, a+1+n);
        int maxlen = min(n-2, min(a[n]-1, a[n-1]-1));
        printf("%d\n",maxlen);
    }

    return 0;
}