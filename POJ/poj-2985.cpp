// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
// #include <>
using namespace std;
#define maxn 1<<18
int father[maxn];
int flag[maxn];
int tree[maxn],n,m;
int findfa(int x)
{
    return father[x]==x ? x: father[x]=findfa(father[x]);
}
int lowbit(int x)//求二进制最小位
{
    return x&-x;
}
void update(int x,int change)//更新树状数组
{
    while(x<=n)
    {
        tree[x]+=change;
        x+=lowbit(x);
    }
}
void add(int x,int y,int &fk)//并查集合并，更新
{
    int xx=findfa(x);
    int yy=findfa(y);
    if(xx!=yy)
    {
        father[yy]=xx;//少个y超时n遍
        update(flag[xx],-1);
        update(flag[yy],-1);
        update(flag[xx]=flag[xx]+flag[yy],1);
        flag[yy]=0;
        fk--;
    }
}
int k_thsmall(int K)//求第k小
{
    int sum=0,i;//初始化
    for(i=18;i>=0;i--)
    {
        if(sum+(1<<i)<=n&&tree[sum+(1<<i)]<K)
        {
            K-=tree[sum+(1<<i)];
            sum+=1<<i;
        }
    }
    return sum+1;
}
int main()
{
    int x,y,z,i,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<=n;i++)
        father[i]=i;
        for(i=0;i<=n;i++)
        flag[i]=1;
        update(1,n);
        int fk=n;
        while(m--)
        {
            scanf("%d",&y);
            if(y)
            {
                scanf("%d",&z);
                printf("%d\n",k_thsmall(fk-z+1));//集团的数量需要改变，所以n要变
            }
            else
            {
                scanf("%d%d",&z,&t);
                add(z,t,fk);
            }
        }
    }
    return 0;
}