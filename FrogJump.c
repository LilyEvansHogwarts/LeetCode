#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, bool> dp;

bool canCross(vector<int>& stones, int begin, int k) {
    int key = begin | k << 11;
    if(dp.count(key) > 0)
	return dp[key];
    int n = stones.size();
    int gap;
    cout << begin << "\t" << stones[begin] << endl;
    if(begin >= n - 1)
	return true;
    for(int i = begin + 1;i < n;i++) {
	gap = stones[i] - stones[begin];
	if(gap < k - 1)
	    continue;
	if(gap > k + 1)
	    return dp[key] = false;
	if(canCross(stones, i, gap))
	    return dp[key] = true;
    }
    return dp[key] = (begin == n - 1);
}

int main() {
    vector<int> nums = {0,1,3,6,7};
    cout << canCross(nums, 0, 0) << endl;
    return 0;
}
