#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 2e5+7;

ll a[MAX_N];
int main() {
    int n;
    while(~scanf("%d",&n)) {
        for(int i=0; i<=n; i++)
            scanf("%d",&a[i]);
        int ans;
        ll sum=0;
        for(int i=n;i>=0;i--)
        {
            ans = i;
            sum += a[i];
            if(sum>=i)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}