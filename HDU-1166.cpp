#include<cstdio>
#include <string.h>
using namespace std;
int n,p,a,b,m,x,y,ans;
struct node
{
    int l,r,w,f;
}tree[400001];
inline void build(int k,int ll,int rr)//����
{
    tree[k].l=ll,tree[k].r=rr;
    if(tree[k].l==tree[k].r)
    {
        scanf("%d",&tree[k].w);
        return;
    }
    int m=(ll+rr)/2;
    build(k*2,ll,m);
    build(k*2+1,m+1,rr);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
inline void down(int k)//����´�
{
    tree[k*2].f+=tree[k].f;
    tree[k*2+1].f+=tree[k].f;
    tree[k*2].w+=tree[k].f*(tree[k*2].r-tree[k*2].l+1);
    tree[k*2+1].w+=tree[k].f*(tree[k*2+1].r-tree[k*2+1].l+1);
    tree[k].f=0;
}
inline void ask_point(int k)//�����ѯ
{
    if(tree[k].l==tree[k].r)
    {
        ans=tree[k].w;
        return ;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(x<=m) ask_point(k*2);
    else ask_point(k*2+1);
}
inline void change_point(int k)//�����޸�
{
    if(tree[k].l==tree[k].r)
    {
        tree[k].w+=y;
        return;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(x<=m) change_point(k*2);
    else change_point(k*2+1);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
inline void ask_interval(int k)//�����ѯ
{
    if(tree[k].l>=a&&tree[k].r<=b)
    {
        ans+=tree[k].w;
        return;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(a<=m) ask_interval(k*2);
    if(b>m) ask_interval(k*2+1);
}
inline void change_interval(int k)//�����޸�
{
    if(tree[k].l>=a&&tree[k].r<=b)
    {
        tree[k].w+=(tree[k].r-tree[k].l+1)*y;
        tree[k].f+=y;
        return;
    }
    if(tree[k].f) down(k);
    int m=(tree[k].l+tree[k].r)/2;
    if(a<=m) change_interval(k*2);
    if(b>m) change_interval(k*2+1);
    tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
int main()
{
	int t,cnt=1;
	scanf("%d",&t);
	while(cnt <= t)
	{
		printf("Case %d:\n", cnt);
		cnt++;

		char ch[10];
	    scanf("%d",&n);//n���ڵ�
	    build(1,1,n);//����

	    while(scanf("%s",&ch) && strcmp(ch, "End") != 0){
	        ans=0;
	        if(strcmp(ch, "Add") == 0)
	        {
	        	scanf("%d%d",&x,&y);
	            change_point(1);//�����޸�
	        }
	        else if(strcmp(ch, "Query") == 0)
	        {
	            scanf("%d%d",&a,&b);//�����ѯ
	            ask_interval(1);
	            printf("%d\n",ans);
	        }
	        else
	        {
	            scanf("%d%d",&x,&y);
	            y = -y;
	            change_point(1);//�����޸�
	        }
	    }
	}

}
