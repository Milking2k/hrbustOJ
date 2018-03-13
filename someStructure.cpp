#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct queue
{
	int data[100];
	int head;
	int tail;
};

struct stack
{
	int data[100];
	int top;
};

struct node
{
	int data;
	struct node *next;
};

int main(int argc, char const *argv[])
{
	// ==================queue init===========================
	struct queue queue;
	queue.head = 1;
	queue.tail = 1;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		cin >> queue.data[i];
		queue.tail++;
	}
	//出队并输出
	printf("%d\n", queue.data[queue.head++]);

	// =========================stack init=====================
	struct stack a;
	a.top = 0;

	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a.data[i];
		a.top++;
	}
	// 出栈并输出
	printf("%d\n", a.data[--a.top]);


	// ======================chain init==========================
	struct node *head,*p,*q,*t;	
	int num, cnt;
	head = NULL;

	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> cnt;
		p = (struct node*)malloc(sizeof(struct node));
		p->data = cnt;
		p->next = NULL;
		if (head==NULL)
		{
			head = p;
		}else{
			q->next = p;
		}
		q = p;
	}
	// 插入数据
	cin >> cnt;
	while(t != NULL)
	{
		if (t->next == NULL || t->next->data > cnt)
		{
			p = (struct node*)malloc(sizeof(struct node));
			p->data = cnt;
			p->next = t->next;
			t->next = p;
			break;
		}
		t = t->next;
	}
	// 输出数据
	t = head;
	while(t!=NULL)
	{
		printf("%d\n", t->data);
		t=t->next;
	}
	return 0;
}