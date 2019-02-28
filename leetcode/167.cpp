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
const ll mod = 1000000007;
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
ll powmod(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head
const int N = 1e5 + 7;
int T, n, m;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        if(m==0) return 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i!=0 && j!=0){
                    grid[i][j] += min(grid[i][j-1],grid[i-1][j]);
                }
                else if(i==0&&j==0){
                    continue;
                }
                else if(i==0) {
                    grid[i][j] += grid[i][j-1];
                }
                else if(j==0) {
                    grid[i][j] += grid[i-1][j];
                }
            }
        }
        return grid[n-1][m-1];
    }
private:
    int dp[1000][1000];
};
/*
"abpcplea"
["a","b","c"]

*/
int main()
{
    Solution *solution = new Solution();
    // [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
    vector<vector<int>> xx;
    vector<int> cnt;

    cnt.push_back(1);
    cnt.push_back(3);
    cnt.push_back(1);
    xx.push_back(cnt);
    cnt.clear();
    cnt.push_back(1);
    cnt.push_back(5);
    cnt.push_back(1);
    xx.push_back(cnt);
    cnt.clear();
    cnt.push_back(4);
    cnt.push_back(2);
    cnt.push_back(1);
    xx.push_back(cnt);
    for(auto u:xx){
        for(auto v:u){
            printf("%d ", v);
        }
        puts("");
    }
    // int n = xx.size();
    // int m = xx[0].size();
    // printf("nm::%d %d\n", n, m);
    solution->minPathSum(xx);

    return 0;
}