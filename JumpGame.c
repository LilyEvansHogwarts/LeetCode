#include<vector>
#include<iostream>
using namespace std;

  

bool solve(vector<int>& nums, int start) {
    if(start >= nums.size() - 1)
	return true;
    if(nums[start] == 0)
	return false;
    for(int j = 1;j <= nums[start];j++) {
	if(solve(nums, start + j))
	    return true;
    }
    return false;
}

bool canJump(vector<int>& nums) {
    if(nums.size() == 0)
	return true;
    return solve(nums, 0);
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    
    cout << canJump(nums) << endl;
    return 0;
}
