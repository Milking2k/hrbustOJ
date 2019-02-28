#include <bits/stdc++.h>
using namespace std;
const int N = 150007;

int n, x, y;
list<int> li[N];
int fa[N];

int getFa(int x){
    return x == fa[x] ? x : fa[x] = getFa(fa[x]);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) fa[i] = i, li[i].push_back(i);
    for (int i = 1; i <= n - 1; ++i) {
        cin >> x >> y;
        int cur1 = getFa(x), cur2 = getFa(y);
        li[cur1].splice(li[cur1].end(), li[cur2]);
        fa[cur2] = cur1;
    }
    for (auto &e : li[getFa(x)]) {
        cout << e << " ";
    }
    return 0;
}