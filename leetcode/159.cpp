#include<bits/stdc++.h>
using namespace std;

int solve(string s)
{
	int i=0,j=0;
	int len = s.length();
	int mxLen = 0, mxPos = 0, cnt = 0;
	set<int> ops;	

	for(int i=0;i<len;++i){
		j = max(i,j);
		while(j<len && ops.size() < 2){
			ops.insert((int)s[j]);
			mxLen++;
			j++;
		}
        // printf("sss\n");
        if(j==len) break;
		else if(ops.size()>= 2){
			ops.erase(s[j]);
		}
	} 

	return mxLen;
}


int main()
{
    string s("eccea");
    cout << solve(s);

    return 0;
}
