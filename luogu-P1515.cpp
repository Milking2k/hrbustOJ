#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	 int n, A, B;
    cin >>A>>B>> n;
    n += 14;
    int a[34] = { 0,990,1010,1970, 2030, 2940,3060 ,3930, 4060, 4970, 5030,5990, 6010, 7000 };
    int ans[34] = { 0 };
    for (int i = 14; i < n; i++)
        cin>>a[i];
    sort(a, a + n);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0 && a[i] - a[j] <= B; j--)
        {
            if (a[i] - a[j] < A)continue;
            else ans[i] += ans[j];
        }
    cout << ans[n - 1];
	return 0;
}