#include <bits/stdc++.h>
#define read(x) scanf("%d", &x)
using namespace std;

int main()
{
    int T;
    read(T);
    while (T--)
    {
        int n;
        char cc;
        cin >> n;
        cin >> cc;
        long long ans = 0;
        string s = "";
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;
            int t = abs(c - cc);
            if (t < 10)
            {
                s += "0";
                s += t + '0';
                continue;
            }
            else
            {
                int a = t % 10, b = t / 10;
                s += b + '0';
                s += a + '0';
            }
        }
        int f = 1;
        int k = 0;
        int len = s.size();
        for (int i = 0; i < len && k < len - 1; i++)
        {
            k = i;
            if (s[i] == '0')
            {
            }
            else
            {
                break;
            }
        }
        printf("%d\n", len - k);
    }
    return 0;
}
/*
10
3 z
oMl
6 Y
YJSNPI
*/