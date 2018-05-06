#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE = 200007;
typedef struct {
    int max ;
    int left, right ;
} NODE ;

int num [MAXSIZE] ;
NODE tree[MAXSIZE * 20] ;

int build (int root, int left, int right)
{
    int mid ;
    tree[root].left     = left ;
    tree[root].right    = right ;
    if (left == right)
    {
        return tree[root].max = num[left] ;
    }
    mid = (left + right) / 2 ;
    int a, b ;
    a = build(2 * root, left, mid) ;
    b = build(2 * root + 1, mid + 1, right) ;
    return tree[root].max = max (a, b) ;
}
int findMax(int root, int left, int right)
{
    int mid ;
    if (tree[root].left > right || tree[root].right < left)
        return 0 ;
    if (left <= tree[root].left && tree[root].right <= right)
        return tree[root].max ;
    int a, b ;
    a = findMax(2 * root, left, right) ;
    b = findMax(2 * root + 1, left, right) ;

    return max (a, b) ;
}
int update (int root, int pos, int val)
{
    if (pos < tree[root].left || tree[root].right < pos)
        return tree[root].max ;
    if (tree[root].left == pos && tree[root].right == pos)
        return tree[root].max = val ;
    int a = update (2 * root, pos, val) ;
    int b = update (2 * root + 1, pos, val) ;
    tree[root].max = max (a, b) ;
    return tree[root].max ;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        build(1,1,n);
        while(m--)
        {
            char s[5];
            int x,y;
            scanf("%s %d %d",&s,&x,&y);
//            printf("sss:%s %d %d m:%d\n",s,x,y,m);
            if(strcmp(s,"Q"))
            {
                num[x] = y;
                update(1,x,y);
            }
            else
            {
                printf("%d\n",findMax(1,x,y));
            }
        }
    }
    return 0;
}
