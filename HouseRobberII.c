#include<vector>
#include<iostream>
using namespace std;

int solve(vector<int>& nums, int start, int end) {
    if(start > end)
	return 0;
    int n3 = 0, n2 = 0, n1 = 0, n = 0;
    for(int i = start;i <= end;i++) {
	n = max(n1, max(n2, n3) + nums[i]);
	n3 = n2;
	n2 = n1;
	n1 = n;
    }
    return n;
}

int rob(vector<int>& nums) {
    if(nums.size() == 0)
	return 0;
    if(nums.size() == 1)
	return nums[0];
    return max(solve(nums, 0, nums.size() - 2), solve(nums, 1, nums.size() - 1));
}

int main() {
    vector<int> nums = {1,2,3,4,5,1,2,3,4,5};
    cout << rob(nums) << endl;
    return 0;
}

