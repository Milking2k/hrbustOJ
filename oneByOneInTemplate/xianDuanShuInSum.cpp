/*===================================================
	线段树动态维护区间和
	2018.6.26
	jelech
===================================================*/
#include <cstdio>
#include <string.h>
const int MAXN = 4*100007+7;
struct node
{
	int l,r,w,f;	// 左右孩子、和、懒标记
}tree[MAXN];
int x,y,val,ans;

/*===================================================
	建树操作
	输入：当前位置，左孩子，右孩子		(1,1,n)
	返回：无
===================================================*/
inline void build(int pos, int l, int r)
{
	tree[pos].l = l, tree[pos].r = r;
	if(l == r)
	{
		scanf("%d", &tree[pos].w);	// 可以换为一个数组输入
		return ;
	}

	int mid = (l+r)/2;
	build(2*pos, l, mid);
	build(2*pos+1, mid+1, r);
	tree[pos].w = tree[2*pos].w + tree[2*pos + 1].w;
}

/*===================================================
	懒标记更新：向下更新之前的所有改变量
	输入：更新位置
	返回：无
	f：记录着之前所有的更新值合
===================================================*/
inline void _downUpdate(int pos)
{
	tree[2*pos].f 		+= tree[pos].f;
	tree[2*pos+1].f 	+= tree[pos].f;
	tree[2*pos].w 		+= tree[pos].f * (tree[2*pos].r - tree[2*pos].l + 1);
	tree[2*pos+1].w 	+= tree[pos].f * (tree[2*pos+1].r - tree[2*pos+1].l + 1);

	tree[pos].f = 0;
}

/*===================================================
	单点询问
	输入：询问位置 x(全局)
	返回：询问位置的值
===================================================*/
inline int ask(int pos)
{
	if(tree[pos].l == tree[pos].r)
		return tree[pos].w;

	if(tree[pos].f != 0) 
		_downUpdate(pos);

	int mid = (tree[pos].l + tree[pos].r) / 2;

	x <= mid ? ask(2*pos) : ask(2*pos+1);
}

/*===================================================
	单点修改
	输入：修改位置 x，修改的值val(全局)
	返回：无
===================================================*/
inline void add(int pos)
{
	if(tree[pos].l == tree[pos].r)
	{
		tree[pos].w += val;
		return ;
	}

	if(tree[pos].f != 0) 
		_downUpdate(pos);

	int mid = (tree[pos].l + tree[pos].r)/2;
	if(x <= mid) ask(2*pos);
	else 		ask(2*pos+1);
	tree[pos].w = tree[2*pos].w + tree[2*pos+1].w;
}

/*===================================================
	区间查询
	输入：查询区间 x,y(全局)
	返回：区间和
===================================================*/
inline void sum(int pos)
{
	if(tree[pos].l>=x&&tree[pos].r<=y) 
    {
        ans+=tree[pos].w;
        return;
    }
    if(tree[pos].f) _downUpdate(pos);
    int m=(tree[pos].l+tree[pos].r)/2;
    if(x<=m) sum(pos*2);
    if(y>m) sum(pos*2+1);
}

/*===================================================
	区间修改
	输入：修改的区间 x,y 修改值val(全局) 
	返回：无
===================================================*/


inline void update(int pos)
{
	if(x <= tree[pos].l && tree[pos].r <= y)
	{
		tree[pos].f += val;
		tree[pos].w += val * (tree[pos].r - tree[pos].l + 1);
		return ;
	}

	if(tree[pos].f != 0)_downUpdate(pos);

	int m = (tree[pos].l + tree[pos].r) / 2;

	if(x<=m) update(pos*2);
    if(y>m) update(pos*2+1);
    tree[pos].w = tree[pos*2].w + tree[pos*2+1].w;
}

int main(int argc, char const *argv[])
{
	int t,cnt=1,n;
	scanf("%d",&t);
	while(cnt <= t)
	{
		printf("Case %d:\n", cnt);
		cnt++;

		char ch[10];
	    scanf("%d",&n);//n个节点 
	    build(1,1,n);//建树 

	    while(scanf("%s",&ch) && strcmp(ch, "End") != 0){
	        ans=0;
	        if(strcmp(ch, "Add") == 0)
	        {
	        	scanf("%d%d",&x,&val);
	            add(1);//单点修改 
	        }
	        else if(strcmp(ch, "Query") == 0)
	        {
	            scanf("%d%d",&x,&y);//区间查询 
	            sum(1);
	            printf("%d\n",ans);
	        }
	        else
	        {
	            scanf("%d%d",&x,&y);
	            y = -y;
	            add(1);//单点修改 
	        }
	    }
	}
	return 0;
}	