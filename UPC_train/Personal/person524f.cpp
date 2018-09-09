#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        LL ans1 = 1, ans2 = 1;
        for (int i = 0; i < n; ++i) {
            LL emt1,emt2,cnt=1,cnt2;
            scanf("%lld%lld",&emt1,&emt2);
            if (emt1 < ans1)
            {
                cnt = ans1 / emt1;
                if (ans1 % emt1 != 0) cnt++;
            }
            if (emt2 < ans2)
            {
                cnt2 = ans2 / emt2;
                if (ans2 % emt2 != 0) cnt2++;
                cnt = max(cnt, cnt2);
            }
            ans1 = emt1 * cnt,ans2 = emt2 * cnt;
        }
        printf("%lld\n",ans1+ans2);
    }
    return 0;
}
