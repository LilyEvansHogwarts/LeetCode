#include<vector>
#include<iostream>
using namespace std;

/*
    Solution 1:
int solve(vector<int>& nums, int start, int end ) {
    cout << start << "\t" << end << endl;;
    if(nums.size() == 0 || start > end)
	return 0;
    if(start == end)
	return nums[start];
    int i = (end + start) / 2, j = (start + end) / 2 + 1;
    int k = i;
    int sum1 = -2147483648, sum2 = -2147483648, temp = 0;
    while(i >= start) {
	temp = nums[i] + temp;
	if(temp > sum1) 
	    sum1 = temp;
	i--;
    }
    temp = 0;
    while(j <= end) {
	temp = nums[j] + temp;
	if(temp > sum2) 
	    sum2 = temp;
	j++;
    }
    return max(sum1 + sum2, max(solve(nums, start, k), solve(nums, k + 1, end)));
}

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    return solve(nums, 0, n - 1);
}
*/

// Solution 2:

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0], sum = 0;
    for(int i = 0;i < n;i++) {
	sum += nums[i];
	ans = max(ans, sum);
	sum = max(sum, 0);
    }
    return ans;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    return 0;
}

