#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> odd, even;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(x&1)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int len1 = odd.size();
    int len2 = even.size();
    if(len1 < len2){
        swap(odd, even);
        swap(len1, len2);
    }

    long long sum = 0;
    for (int i = 0; i < len1 - len2 - 1; ++i) {
        sum += odd[i];
    }

    printf("%d\n", sum);

    return 0;
}