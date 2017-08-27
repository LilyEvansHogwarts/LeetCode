#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int maxCoinsDP(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    int N = nums.size();

    vector<vector<int> > dp(N, vector<int>(N, 0));
    for(int k = 2;k < N;k++) {
	for(int left = 0;left < N - k;left++) {
	    int right = left + k;
	    for(int i = left + 1;i < right;i++) 
		dp[left][right] = max(dp[left][right], nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
	}
    }
    return dp[0][N - 1];
}

int main() {
    vector<int> nums = {3,1,5,8};
    cout << maxCoinsDP(nums) << endl;
    return 0;
}
