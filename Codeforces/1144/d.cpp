#include<bits/stdc++.h>
using namespace std;

int n, a[200007];
map<int, int> mp;
int main()
{
    scanf("%d", &n);
    int maxt = -1, maxn = -1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        mp[a[i]]++;
        if(mp[a[i]] > maxt) {
            maxt = mp[a[i]];
            maxn = a[i];
        }
    }
    int p = 0;
    while(a[p] != maxn)
        p++;

    int ans = n - maxt;
    int tp = p;
    printf("%d\n", ans);
    while(tp > 0){
        if(a[tp] != maxn) {
            printf("%d %d %d\n", a[tp] > maxn ? 2 : 1, tp, tp + 1);
        }
        tp--;
    }
    while(p <= n) {
        if(a[p] != maxn) {
            printf("%d %d %d\n", a[p] > maxn ? 2 : 1, p, p - 1);
        }
        p++;
    }


    return 0;
}