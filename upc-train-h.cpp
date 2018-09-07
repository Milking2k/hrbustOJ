#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(), (now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1e18 + 7;
inline int read(int &n)
{
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return n = x * f;
}
inline void read(int &a, int &b) { read(a), read(b); }
inline void read(int &a, int &b, int &c) { read(a, b), read(c); };
ll powmod(ll a, ll b)
{
    ll res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head

const int N = 1e6 + 7;
ll n;
ll ans = 0;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // while (cin >> n)
    // {
        cin >> n;
        bool ok = false;
        rep(i, 3, 57)
        {
            ans = 0;
            rep(j, 1, 350000)
            {
                ans += powmod(j, i - 1);
                if (ans == n)
                {
                    ok = true;
                    cout << i << " " << j << endl;
                    break;
                }
                if (ans > n)
                    break;
            }
            if (ok)
                break;
        }
        if (!ok)
            cout << "impossible" << endl;
    // }
    return 0;
}

/*
1152921504606846976

10000000000000000
18014398509481984

72057594037927936
144115188075855872
288230376151711744

215443.46900318837217592935665194
*/