#include <bits/stdc++.h>
using namespace std;
int len[300005];


struct node
{
	int val;
	node *next;
};

typedef struct node st_lb;
typedef st_lb* stlb;
stlb bottom[300005];


int free_lb(node *&t)
{
	node *cnt;
    while (NULL != t)
    {
        cnt = t;
        t = t->next;  // 下一个节点
        free(cnt);
    }

    return 1;
}

int jia(int s,int v)
{
	if(len[s] == 0) bottom[s] = NULL;
	node *q = (node*)malloc(sizeof(node));
	q->val = v;
	q->next= NULL;
	(bottom[s]+len[s])->next = q;
	len[s]++;
	free(q);
	q->next = NULL;
}
int jian(int s)
{
	node *q = (node*)malloc(sizeof(node));
	q = (bottom[s]+len[s]-1)->next;
	len[s]--;
	free(q);
	q->next;
}
int bing(int s,int t)
{
	node *p = (node*)malloc(sizeof(node));
	node *q = (node*)malloc(sizeof(node));
	(bottom[s]+len[s])->next = bottom[t];
	len[s] += len[t];
	len[t];
	free_lb(bottom[t]);
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