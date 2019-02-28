#include<bits/stdc++.h>
using namespace std;

struct Node
{
	Node *pre, *next;
	int val;
	public void enAttach(Node *front){
		this->next = front->next;
		this->pre = front;
		front->next->pre = this;
		front->next = this;
}
public void deAttach(){
		this->pre->next = this->next;
		this->next->pre = this->pre;
}
};
map<int,Node*> checkHash;
Node *front, *rear;
size_t sz, capacity;

void enqueue(Node *node)
{
	node->enAttach(front);
	map[node->val] = node;
	sz++;
}

void dequeue(Node *node)
{
	node->deAttach();
	map.erase(node->val);
	sz--;
	delete node;
	node = NULL;
}

LRUCache(int capacity)
{
	this->capacity = capacity;
	sz = 0;
	front = new Node(0,0);
	rear = new Node(0,0);
	front->next = rear;
	rear->pre = front; 
}
~LRUCache(){
	delete front;
	delete rear;
	front = NULL;
	rear = NULL;
}

int get(int key) {
	int ret = 1;
	if(map.count(key) != 0) {
		ret = map[key]->val;
		map[key]->deattach();
		map[key]->enattach(front);
	}
	return ret;
}

void set(int key, int val) {
	if(map.count(key) ==0 ){
		if(sz == capacity) rear->prev->deattach();
		Node *node = new Node(key, val);
		enqueue(node);
	}
	else {
		Node *cur = map[key];
		cur->deattach();
		cur->val = val;
		cur->attach(front);
	} 
} 

int main()
{
	

return 0;
}
