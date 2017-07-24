#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    if(nums.size() == 0)
	return 1;
    sort(nums.begin(),nums.end());
    int i = 0;
    while(nums[i] <= 0)
	i++;
    if(nums[i++] != 1)
	return 1;
    while(i < nums.size() && (nums[i] == nums[i - 1] || nums[i] - nums[i - 1] == 1))
	i++;
    return nums[i-1] + 1;
}

int main() {
    vector<int> res;
    res.push_back(0);
    res.push_back(2);
    res.push_back(2);
    res.push_back(1);
    res.push_back(1);
    res.push_back(1);
    cout << firstMissingPositive(res) << endl;
    return 0;
}
