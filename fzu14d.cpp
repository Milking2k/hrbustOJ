#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int const MAX = 105;
int mp[MAX][MAX];
int cx[MAX], cy[MAX];
bool vis[MAX];
int n;

struct DATA
{
    int atk, hp;
}me[MAX], em[MAX];

int DFS(int x)
{
    for(int y = 0; y < n; y++)
    {
        if(!vis[y] && mp[x][y])
        {
            vis[y] = true;
            if(cy[y] == -1 || DFS(cy[y]))
            {
                cx[x] = y;
                cy[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch()
{
    int ans = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for(int i = 0; i < n; i++)
    {
        if(cx[i] == -1)
        {
            memset(vis, false, sizeof(vis));
            ans += DFS(i);
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        memset(mp, 0, sizeof(mp));
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &me[i].hp, &me[i].atk);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &em[i].hp, &em[i].atk);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(me[i].hp > em[j].atk && me[i].atk >= em[j].hp)
                    mp[i][j] = 1;
        int ans = MaxMatch();
        printf("%s\n", ans == n ? "Yes" : "No");
    }
}