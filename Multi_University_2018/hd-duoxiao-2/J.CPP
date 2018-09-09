#include <iostream>
#include <cstdio>
using namespace std;

const long long MOD=1e9+7;
long long num[500005];
long long temp[500005];
int n;
long long ans;

void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (num[i] <= num[j])
        {
            temp[k++] = num[i++];
        }
        else
        {
            ans += j - k ;    //统计逆序
            temp[k++] = num[j++];
        }
    }
    while (i <= mid) temp[k++] = num[i++];
    while (j <= high) temp[k++] = num[j++];
    for (i = low; i <= high; ++i)
    {
        num[i] = temp[i];
    }
}

void mergeSort(int a, int b)
{
    if (a < b)
    {
        int mid = (a + b) / 2;
        mergeSort(a, mid);
        mergeSort(mid + 1, b);
        merge(a, mid, b);
    }
}


int main()
{
    while (scanf("%d", &n) != EOF && n > 0)
    {
        ans = 0;
        long long x,y;
        scanf("%lld%lld",&x,&y);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &num[i]);
            num[i]+=MOD;
        }
        mergeSort(0, n - 1);
        printf("%lld\n", ans*min(x,y)*1LL);
    }
    return 0;
}