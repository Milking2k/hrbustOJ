#include<bits/stdc++.h>
using namespace std;

bool solve(vector<double> array)
{
	if(array.size() == 0 ) return 0;
	if(array.size() == 1) return (array[0] == 24); 

	for (int i=0; i<array.size(); ++i) {
	for (int j=0; j<array.size(); ++j) {
	if(i!=j) {
		vector<double> nums;
		for (int k = 0; k < 4; ++k) {
			if(k != i && k != j) {
				nums.push_back(array[k]);
			}
		}
		for (int k = 0; k < 4; ++k) {
			if(k==0) nums.push_back(array[i] + array[j]);
			else if(k==1) nums.push_back(array[i] - array[j]);
			else if(k==2) nums.push_back(array[i] * array[j]);
			else if(j==0) continue;
			else if(k==3) nums.push_back(array[i] / array[j]); 
			if( solve(nums) )
				return true;
			nums.pop_back();	
		}
}
}
} 
	return 0;
}

int main()
{
	int nums[4];
	vector<double> array;
	for (auto i: nums) {
		array.push_back( (double)i );
	}
	solve(array);

	return 0;
}
