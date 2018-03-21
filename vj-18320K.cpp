// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
const int MAX_N = 1005;

struct Point {
    int x;
    int y;
};

int n, d;
int par[MAX_N], rank[MAX_N];
Point p[MAX_N];
bool status[MAX_N];

void init(int n) {
    for(int i=0; i<n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if(par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unit(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)  return;

    if(rank[x] < rank[y])
        par[x] = y;
    else {
        par[y] = x;
        if(rank[x] == rank[y])  rank[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {

    // freopen("in.txt", "r", stdin);

    scanf("%d%d", &n, &d);
    for(int i=0; i<n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);

    init(n);

    char ch[2];
    int x, y;
    while(~scanf("%s", ch)) {
        if(ch[0] == 'O') {
            scanf("%d", &x);
            status[x-1] = true;
            for(int i=0; i<n; i++) {
                if(i == x-1)    continue;

                if(status[i] && dist(p[i], p[x-1]) <= d * d)
                    unit(i, x-1);
            }
        } else if(ch[0] == 'S') {
            scanf("%d%d", &x, &y);
            if(same(x-1, y-1))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }

    // fclose(stdin);

    return 0;
}