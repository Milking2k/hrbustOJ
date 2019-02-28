#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        tempHead = new ListNode(-1);
		tempHead->next = head;
		head = tempHead;
		while(head&&head->next) {
			if(head->val > head->next->val) {
				ListNode* now = head;
				attach(detach(now));
			}
			head = head->next;
}
return tempHead->next;
}
private:
ListNode *tempHead, *temp;
	ListNode* detach(ListNode* curPre){
		ListNode* ret = curPre->next;
		curPre->next = ret->next;
		return ret; 
	}
	void attach(ListNode* cur){
		temp = tempHead->next;
		while(temp && temp != cur) {
			if(temp->val < cur->val)
temp = temp->next;
		}
	}
};
int main()
{
	solve({0,1,2,3});


	return 0;
}
