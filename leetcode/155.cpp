MinStack() { 
this->bottom->next = top;
this->top->prev = bottom;
curVal=0x3f;
}

void push(int x) {
	node *cur = new node(x);
	top->prev->next = cur;
	cur->prev = top->prev;
	cur->next = top;
	top->prev = cur;
	curVal = cur->minVal;
}

void pop() {
top = top->prev;
curVal = top->prev->minVal ;
}

int top() {
if(top->prev == bottom) return -1;
else return top->prev->val;
}

int getMin() {
if(top->prev == bottom) return -1;
else return top->prev->minVal;
}
private:
	struct node
{
		int val;
		int minVal;
		node *prev, *next;
		node(int _val){
			this.val = _val;
			this.minVal = (_val < curVal ? _val:curVal);
		}
}*bottom, *top;
int curVal;
	
