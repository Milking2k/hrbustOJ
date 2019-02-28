#include<bits/stdc++.h>
using namespace std;

vector<string> sovle(int n, int tot)
{
vector<string> ret; 
	if(n==0) return ret;
	if(n==1) {
	ret.push_back("0"); 
	ret.push_back("1"); 
	ret.push_back("8");
	reutrn ret;
}

vector<string> s = solve(n-2, tot);
	for (auto u:s){
if(n!=tot) ret.push_back("0"+u+"0");
  	ret.push_back("1"+u+"1");
  	ret.push_back("6"+u+"9");
  	ret.push_back("8"+u+"8");
  	ret.push_back("9"+u+"6");
	}
	return ret;
}

int main()
{
	int n;
	// scanf;
	
	solve(n,n);
	return 0;
}
