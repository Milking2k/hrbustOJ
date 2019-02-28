#include<bits/stdc++.h>
using namespace std;
const int N = 1007;

int n,m;
char a[N][N];

int fa[N + N], ans[N + N], deg[N + N];
vector<int> G[N + N], eg[N + N];

int getFa(int i) {
    return i == fa[i] ? i : fa[i] = getFa(fa[i]); 
}

bool topsort()
{
    queue<int> q;
    for (int i = 1; i <= n + m; ++i) {
        int x = getFa(i);
        if(deg[x] + ans[x] == 0) {
            q.push(x);
            ans[x] = 1;
        }
    }

    while(q.size()) {
        int now = q.front();
        q.pop();
        // printf("%d ", now);
        for (auto &to : G[now]) {
            ans[to] = max(ans[to], ans[now] + 1);
            if(--deg[to] == 0)
                q.push(to);
        }
    }

    for (int i = 1; i <= n + m; ++i) {
        if(deg[getFa(i)] != 0) {
            // puts("x2x");
            return false;
        }
    }

    return true;
}

bool solve()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '=') {
                fa[getFa(i)] = getFa(n + j);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != '=') {
                int x = getFa(i), y = getFa(n + j);
                if (x == y){
                    // puts("x1x");
                    return false;
                }
                if (a[i][j] == '<')
                    G[x].push_back(y), deg[y]++;
                else
                    G[y].push_back(x), deg[x]++;
            }
        }
    }
    return topsort();
}

int main()
{
    cin >> n >> m;
    fill(ans, ans + n + m + 2, 0);
    for (int i = 0; i <= n + m; ++i) fa[i] = i;
    for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);

    if (solve()) {
        cout << "Yes\n";
        for (int i = 1; i <= n; ++i) {
            cout << ans[getFa(i)] << " ";
        }
        cout << endl;
        for (int i = 1; i <= m; ++i) {
            cout << ans[getFa(n + i)] << " ";
        }
    }
    else {
        cout << "No";
    }
    cout << endl;

    return 0;
}