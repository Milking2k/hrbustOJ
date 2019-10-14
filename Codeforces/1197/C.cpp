#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;

int n,k;
int a[N];

int main()
{
    scanf("%d%d",&n,&k);
    for (size_t i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    sort(a+1, a+1+n);
    int tot = a[n] - a[1];
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(0);
    pq.push(0);
    for (size_t i = 2; i <= n; ++i) {
        pq.push(a[i-1] - a[i]);
    }
    for (size_t i = 1; i <= k - 1; ++i) {
        // printf("debug:%d\n",pq.top());
        tot += pq.top();
        pq.pop();
    }

    printf("%d\n",tot);
    return 0;
}