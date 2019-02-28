#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; --i)
            if (nums[i-1] < nums[i]) {
                int j = i;
                while(j + 1 < nums.size() && nums[i-1] < nums[j + 1]) ++j;
                swap(nums[i-1], nums[j]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        reverse(nums.begin(), nums.end());
    }
};
int main()
{

}