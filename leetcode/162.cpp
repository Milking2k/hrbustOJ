#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums)
{
	int len = nums.size();
    if(len==1)
        return 0;
    if(nums[0] > nums[1])
        return 0;
    if(nums[len-1]>nums[len-2])
        return len - 1;

    for (int i = 1; i < len - 1; ++i){
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
			return i;
		}
	} 
	return -1;
}

int solve2(vector<int> &nums) // binary search;
{
	int left=0,right = nums.size()-1;
	if(right==1) return 0;
	if(right==2) return nums[0]<nums[1]?1:0;

	while(left<right) {
		int mid = left + (right-left)/2;
		if(nums[mid]<nums[mid+1]){
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}
	return right;
}

int main()
{
    vector<int> nums = {1,2,3,1};
    cout << solve(nums);


	return 0;
}
