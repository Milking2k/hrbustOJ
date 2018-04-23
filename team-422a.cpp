// // #include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// #define rd(x) scanf("%d",&x)
// #define INF 0x3f3f3f3f
// #define pb push_back
// int n,m,x,y;
// int countnum[1005];
// int vis[1005];
// bool flag;
// std::vector<int> e[1005];

// void dfs(int cur, int col) {
//     for (int i = first[cur]; i && flag; i = e[i].tonext) {
//         int v = e[i].v;
//         if (vis[v]) {
//             if (arr[v] == col) {
//                 flag = false;
//                 return;
//             }
//         }
//         if (vis[v]) continue;
//         vis[v] = true;
//         if (arr[v] == -1) {
//             arr[v] = !col;
//             dfs(v, !col);
//         } else {
//             if (arr[v] == col) {
//                 flag = false;
//                 return;
//             } else {
//                 dfs(v, !col);
//             }
//         }
//     }
// }

// int main()
// {
// 	freopen("in.txt","r",stdin);

// 	while(~scanf("%d%d%d%d",&n,&m,&x,&y))
// 	{
// 		//init
// 		memset(e,0,sizeof(e));
// 		memset(countnum,0,sizeof(countnum));
// 		fill(vis,vis+n,INF);
// 		countnum=0;
// 		for (int i = 0; i < 1005; ++i)
// 		{
// 			e[i].clear();
// 		}
// 		flag = false;


// 		for (int i = 1; i <= m; ++i)
// 		{
// 			int cnt1,cnt2;
// 			scanf("%d%d",&cnt1,&cnt2);
// 			e[cnt1].pb(cnt2);
// 			e[cnt2].pb(cnt1);
// 			countnum[cnt1]=countnum[cnt2]=1;
// 		}
// 		//============================
// 		for (int i = 1; i <= x; ++i){
// 			scanf("%d",&cnt);
// 			countnum[cnt]=1;
// 			vis[cnt] = 1;// good
// 			for (std::vector<int>::iterator j = e[cnt].begin(); j != e[cnt].end() && !flag; ++j)
// 			{
// 				if(vis[j] == 1) {flag=true;break;}
// 				else vis[j] = -1;
// 			}
// 		}
// 		for (int i = 1; i <= y; ++i){
// 			scanf("%d",&cnt);
// 			countnum[cnt]=1;
// 			vis[cnt] = -1;// bad
// 			for (std::vector<int>::iterator j = e[cnt].begin(); j != e[cnt].end() && !flag; ++j)
// 			{
// 				if(vis[j] == -1) {flag=true;break;}
// 				else vis[j] = 1;
// 			}
// 		}
// 		for (int i = 1; i <= n; ++i) {
// 	        if (countnum[i] == 0 && vis[i] == INF) {
// 	            flag=true;
// 	            break;
//         	}
//     	}

// 		if(flag) printf("NO\n"),continue;
// 		//============================
		
// 		int cntele = e[1].front();
// 		if(vis[1] == INF) vis[1] = 1;

// 		memset(vis, 0, sizeof vis);
// 	    for (int i = 1; i <= n; ++i) {
// 	        if (vis[i]) continue;
// 	        if (ca[i] == -1) continue;
// 	        vis[i] = 1;
// 	        arr[i] = ca[i];
// 	        dfs(i, ca[i]);
// 	    }
// 	    for (int i = 1; i <= n; ++i) {
// 	        if (vis[i]) continue;
// 	        arr[i] = black;
// 	        dfs(i, black);
// 	    }
// 	    if (flag == false) {
// 	        cout << "NO" << endl;
// 	        return;
// 	    }
// 	    cout << "YES" << endl;
// 		}
// 	return 0;
// }1



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define IOS ios::sync_with_stdio(false)
using namespace std;
#define inf (0x3f3f3f3f)
typedef long long int LL;

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
int n, m, x, y;
const int maxn = 1000 + 20;
struct node {
    int u, v, w;
    int tonext;
} e[2 * 10000 + 20];
int first[maxn];
bool vis[maxn];
int black = 1;
int white = 0;
int arr[maxn];
int ca[maxn];
bool in[maxn];
bool flag;
int num;
void add(int u, int v, int w) {
    ++num;
    e[num].u = u;
    e[num].v = v;
    e[num].w = w;
    e[num].tonext = first[u];
    first[u] = num;
}
void dfs(int cur, int col) {
    for (int i = first[cur]; i && flag; i = e[i].tonext) {
        int v = e[i].v;
        if (vis[v]) {
            if (arr[v] == col) {
                flag = false;
                return;
            }
        }
        if (vis[v]) continue;
        vis[v] = true;
        if (arr[v] == -1) {
            arr[v] = !col;
            dfs(v, !col);
        } else {
            if (arr[v] == col) {
                flag = false;
                return;
            } else {
                dfs(v, !col);
            }
        }
    }
}
void work() {
    num = 0;
    memset(arr, -1, sizeof arr);
    memset(ca, -1, sizeof ca);
    memset(in, 0, sizeof in);
    memset(first, 0, sizeof first);
    flag = true;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v, 1);
        add(v, u, 1);
        in[v] = in[u] = 1;
    }
    for (int i = 1; i <= x; ++i) {
        int val;
        cin >> val;
        ca[val] = black;
        arr[val] = black;
    }
    for (int i = 1; i <= y; ++i) {
        int val;
        cin >> val;
        ca[val] = white;
        arr[val] = white;
    }
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0 && ca[i] == -1) {
            cout << "NO" << endl;
            return;
        }
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (ca[i] == -1) continue;
        vis[i] = 1;
        arr[i] = ca[i];
        dfs(i, ca[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        arr[i] = black;
        dfs(i, black);
    }
    if (flag == false) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}
int main() {
    freopen("in.txt","r",stdin);
    IOS;
    while (cin >> n >> m >> x >> y) {
        work();
    }
    return 0;
}