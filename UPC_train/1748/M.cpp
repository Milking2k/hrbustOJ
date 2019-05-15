#include <bits/stdc++.h>
using namespace std;
const int N = 107;
int a[N];
int b[1000007];

map<int, int> mm;
bool v[1000007];
void init()
{
    memset(v, 0, sizeof(v));
    int tot = 0;
    int n = 1e6 + 7;
    for (int i = 2; i <= n; ++i)
    {
        if (v[i])
            continue;
        mm[i] = ++tot;
        for (int j = i; j <= n / i; ++j)
            v[i * j] = 1;
    }
}

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int getpri(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0 && isPrime(i))
        {
            return i;
        }
    }
}

int main()
{
    //    int x;
    //    while(~scanf("%d",&x)){
    //        printf("%d\n",getpri(x));
    //    }

    int T;
    scanf("%d", &T);
    init();
    //    for (int i = 1; i <= 10; ++i) {
    //        printf("%d::\n",mm[i]);
    //    }
    while (T--)
    {
        int n;
        scanf("%d", &n);

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", a + i);
            if (a[i] == 1)
                ans ^= 1, b[1] = 0;
            else if (isPrime(a[i]))
                ans ^= (mm[a[i]] + 1), b[i] = mm[a[i]] + 1;
            else
            {
                int cur = getpri(a[i]);
                b[i] = cur;
                ans ^= cur;
            }
            //            printf("%d_",b[i]);
        }
        //        printf("%d\n",ans);
        printf("%s\n", ans != 0 ? "Subconscious is our king!" : "Long live with King Johann!");
    }

    return 0;
}
