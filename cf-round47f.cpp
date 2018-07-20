#include <bits/stdc++.h>
using namespace std;
int n, par[1000005], ans[1000005], at[1000005];
vector<int> v[1000005], vv[1000005];
int ta, tb;

int find(int a) {
	return par[a] == a ? a : par[a] = find(par[a]); // 并查集查共同祖先
}

void merge(int a, int b) {
	if (vv[a].size() < vv[b].size()) // 保持函数参数ab大小确定
		swap(a, b);
	for (int i = 0, j = vv[a].size() - vv[b].size(); i < vv[b].size(); i++, j++) {
		vv[a][j] += vv[b][i]; // 交换
		if (vv[a][j] >= vv[a][at[a]])
			at[a] = j;
	}
	par[b] = a;
}

void dfs(int a, int b) {
	par[a] = a;
	vv[a].push_back(1);
	at[a] = 0;
	for (int i : v[a])
		if (i != b) {
			dfs(i, a);
			vv[find(i)].push_back(0);
			merge(par[i], find(a));
		}
	ta = find(a);
	ans[a] = vv[ta].size() - 1 - at[ta];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &ta, &tb);
		v[ta].push_back(tb);
		v[tb].push_back(ta);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
}