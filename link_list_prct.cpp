#include <bits/stdc++.h>
using namespace std;
#define read1(x) scanf("%d",&x)
#define read2(x,y) scanf("%d%d",&x,&y)
struct node
{
	int x;
	node *next;
}*head[1000];

int main(int argc, char const *argv[])
{
	int p;// p is num of *head;
	read1(p);
	node *p1,*p2;
	for (int i = 0; i < p; ++i)
	{
		int n=0;
		head[i]=p1=p2=new node;
		// cin >> p1->x;
		read1(p1->x);
		head[i]=NULL;
		while(p1->x!=0)
		{
			if(n==0)
			{
				head[i]=p1;
			}
			else
				p2->next=p1;
				p2=p1;
				p1=new node;
				read1(p1->x);
				// cin >> p1->x;
				n++;
		}
		p2->next=NULL;
	}
	delete p1,p2;
	p2=NULL;
	p1=NULL;
	node *ptCnt=head[2];

	while(ptCnt!=NULL)
	{
		printf("%d_", ptCnt->x);
		ptCnt = ptCnt->next;
	}
	delete ptCnt;
	ptCnt=NULL;
	return 0;
}