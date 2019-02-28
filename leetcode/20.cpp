#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
	stack<char> stc;
	int len = s.length();
	stc.push(s[0]);
	for(int i = 1; i < len; ++i) {
		char now = stc.top();
		if((now == '[' && s[i]==']') 
|| (now == '(' && s[i]==')')
|| (now == '{' && s[i]=='}')){
	stc.pop();
}
else stc.push(s[i]);
	}
	if(stc.size() > 0) return false;
	else return true;
}

int main()
{
	solve({0,1,2,3});


	return 0;
}
