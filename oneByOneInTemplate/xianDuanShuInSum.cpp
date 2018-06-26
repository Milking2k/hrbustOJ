/*===================================================
线段树
	区间维护区间和
	2018.6.26
	jelech
===================================================*/
#include <cstdio>

struct node
{
	int l,r,w,f;	// 左右孩子、和、懒标记
}tree[4*10007 + 7];
int x,val;


/*===================================================
	建树操作
	输入：当前位置，左孩子，右孩子		(1,1,n)
	返回：无
===================================================*/
void build(int pos, int l, int r)
{
	tree[pos].l = l, tree[pos].r = r;
	if(l == r)
	{
		scanf("%d ", tree[pos].w);	// 可以换为一个数组输入
		return ;
	}

	int mid = (l+r)/2;
	build(2*pos, l, mid);
	build(2*pos+1, mid, r);
}

/*===================================================
	单点询问
	输入：询问位置 x(全局)
	返回：询问位置的值
===================================================*/
int ask(int pos)
{
	if(tree[pos].l == tree[pos].r)
		return tree[pos].w;

	int mid = (tree[pos].l + tree[pos].r)/2;
	if(x < mid) ask(2*pos);
	else 		ask(2*pos+1);
}

/*===================================================
	单点修改
	输入：修改位置 x，修改的值val(全局)
	返回：无
===================================================*/
void add(int pos)
{
	if(tree[pos].l == tree[pos].r)
	{
		tree[pos].w = val;
		return ;
	}

	int mid = (tree[pos].l + tree[pos].r)/2;
	if(x < mid) ask(2*pos);
	else 		ask(2*pos+1);
}

/*===================================================
	区间查询
	输入：查询区间 x,y(全局)
	返回：区间和
===================================================*/
int sum(int pos)
{
	if(x <= tree[pos].l && tree[pos].r <= y)
		return tree[pos].w;

	int mid = (tree[pos].l + tree[pos].r)/2;
	if(y <= mid)		return sum(2*pos);
	else if(mid <= x)	return sum(2*pos+1);
	else				return sum(2*pos) + sum(2*pos+1);
}

/*===================================================
	区间修改
	输入：修改的区间 x,y(全局)
	返回：区间和

	附属：	down() 懒标记更新
			f:记录着区间之前的多次更新状况
===================================================*/



int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << "hello world\n";
	return 0;
}	