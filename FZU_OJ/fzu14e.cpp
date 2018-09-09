#include <cstdio>
#include <cstring>
#include <algorithm>
int const INF = 0x3fffffff;
int const MAX = 805;
using namespace std;
int fa[MAX], ans, num;

struct DATA
{
    int x, y, val;
}d[MAX * MAX];
bool cmp(DATA a, DATA b){return a.val < b.val;}
void UF_set(){for(int i = 0; i < MAX; i++)fa[i] = i;}
int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}

void Union(int a, int b, int val)
{   
    int r1 = Find(a);
    int r2 = Find(b);
    if(r1 != r2)
    {
        if(num >= 2)
        {
            fa[r2] = r1;
            num --;
        }
        else
            ans = min(ans, val);
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        UF_set();
        ans = INF, num = n - 1;
        int cnt = 0, tmp;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%d", &tmp);
                if(j > i)
                {
                    d[cnt].x = i;
                    d[cnt].y = j;
                    d[cnt++].val = tmp;
                }
            }
        }
        sort(d, d + cnt, cmp);
        for(int i = 0; i < cnt; i++)
            Union(d[i].x, d[i].y, d[i].val);
        printf("%d\n", ans);
    }
}