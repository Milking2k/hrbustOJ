#include <bits/stdc++.h>
using namespace std;

struct node
{
	char val;
	node *rc,*lc;
};


node* buildTree(string pre,string mid)
{
	node *head = new node();
	head->val = pre[0];
	int mdLen = mid.length();
	for (int i = 0; i < mdLen; ++i)
	{
		if (pre[0] == mid[i])
		{
			if (i!=0)
			{
				head->lc = buildTree(pre.substr(1,i), mid.substr(0,i));
			}else{
				head->lc = NULL;
			}
			if (i!=mdLen-1)
			{
				head->rc = buildTree(pre.substr(1+i,mdLen-i-1), mid.substr(i+1,mdLen-i-1));
			}else{
				head->rc = NULL;
			}
		}
	}
	return head;
}
void afterTS(node *head)
{
	if (head==NULL)
	{
		return;
	}else{
		if (head->lc!=NULL)
		{
			afterTS(head->lc);
		}
		if (head->rc != NULL)
		{
			afterTS(head->rc);
		}
		cout << head->val;
	}
}
int main(int argc, char const *argv[])
{
	string pre,mid;
	node *head = NULL;
	while(cin >> pre >> mid)
	{
		node *head;
		head = buildTree(pre,mid);
		afterTS(head);
		printf("\n");
	}
	return 0;
}