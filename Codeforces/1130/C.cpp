#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 57;

int n;
int st[2], ed[2];
char grid[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool vis[N][N];

vector<PII> ve[2];

bool check(int x, int y) 
{
    return (x >= 1 && x <= n && y >= 1 && y <= n && grid[x][y] == '0');
}

bool flag = false;
void bfs(int x, int y, int f)
{
    queue<PII> q;
    q.push({x, y});
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        ve[f].push_back(q.front());
        grid[x][y] = '2';
        q.pop();

        if(x == ed[0] && y == ed[1]) {
            flag = true;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(check(nx, ny)) {
                // printf("debug:%d %d %d\n", ve[0].size(), nx, ny);
                grid[nx][ny] = '2';
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> st[0] >> st[1];
    cin >> ed[0] >> ed[1];
    for (int i = 1; i <= n; ++i) {
        scanf("%s", grid[i] + 1);
    }

    bfs(st[0], st[1], 0);
    if(flag) return 0 * puts("0");

    bfs(ed[0], ed[1], 1);

    int minAns = 0x3f3f3f3f;
    // cout << ve[0].size() << " " << ve[1].size() << endl;
    for (auto &s : ve[0]) {
        for (auto &e : ve[1]) {
            // cout << s.first << " " << s.second << "_+_" << e.first << " " << e.second << endl;
            minAns = min(minAns, (s.first - e.first) * (s.first - e.first) + (s.second - e.second) * (s.second - e.second));
        }
    }

    cout << (minAns) << endl;

    return 0;
}