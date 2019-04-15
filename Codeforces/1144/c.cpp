#include<bits/stdc++.h>
using namespace std;

int n,a[200007];
map<int, int> mp;
int main()
{
    scanf("%d",&n);
    vector<int> ans1, ans2;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
    for (auto m:mp) {
        ans1.push_back(m.first);
        if(m.second == 2) {
            ans2.push_back(m.first);
        }
        else if(m.second > 2) {
            printf("NO");
            return 0;
        }
    }
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end(), [](int a, int b) { return a > b; });

    printf("YES\n%d\n", ans1.size());
    for(auto ans:ans1){
        printf("%d ", ans);
    }
    printf("\n%d\n", ans2.size());
    for(auto ans:ans2){
        printf("%d ", ans);
    }
    return 0;
}