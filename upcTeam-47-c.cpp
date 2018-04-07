#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	node *next;
};

struct stack_lb
{
	node *bottom;
	node *top;
};

stack_lb head[300005];

int jia(int s,int v)
{
	node *q = (node*)malloc(sizeof(node));
	q->val = v;
	q->next= NULL;
	head[s]->tail = q;

}
int jian(int s)
{

}
int bing(int s,int t)
{

}


int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	int n,q;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if (op==1)
		{
			int s,v;
			scanf("%d%d",&s,&v);
			jia(s,v);
		}else if(op==2){
			int s;
			scanf("%d",&s);
			jian(s);
		}else if(op==3){
			int s,t;
			scanf("%d%d",&s,&t);
			bing(s,t);
		}
	}
	
	return 0;
}