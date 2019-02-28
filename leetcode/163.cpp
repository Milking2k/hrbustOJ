#include<bits/stdc++.h>
using namespace std;
string getString(int lower, int upper){
    return lower == upper ? to_string(lower) : to_string(lower).append("->").append(to_string(upper));
}


vector<string> solve(vector<int>& nums, int lower, int upper)
{
	int len = nums.size();
	vector<string> ret;
	if(len==0) ret.push_back(getString(lower,upper));
	else{
		for(int i=0;i<=len;++i) {
			if(i==len){
				if(lower<upper) ret.push_back(getString(lower,upper));
			}
			if(nums[i]>lower){
				ret.push_back(getString(lower, nums[i]-1));
				lower = nums[i]+1;
			}
			
		}
    }
    for(auto re:ret){
        cout << re << endl;
    }
    return ret;
}



int main()
{
    vector<int> nums = {0,1,3,50,75};
    vector<string> ret = solve(nums,0,99);
    

	return 0;
}
