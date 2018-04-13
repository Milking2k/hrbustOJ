#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int a[100005];
    cin >> n;
    int max1Pos=-1;
    int max2Pos=-1;
    for (int i = 1 ; i <= n; ++i)
    {
        int cnt;
        cin >> cnt;
        if(cnt > max1Pos)
        {
            max2Pos = max1Pos;
            max1Pos = cnt;
            a[max1Pos] = -1;
        }
        else if(cnt > max2Pos)
        {
            a[max1Pos]++;
            max2Pos = cnt;
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = a[ans] < a[i] ? i : ans;

    printf("%d\n", ans);
    return 0;
}