#include<vector>
#include<iostream>
using namespace std;

void show(vector<int>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << "\t";
    cout << endl;
}

int maxProfit(vector<int>& nums) {
    int n = nums.size();
    int start = 0, end, count = 0;
    while(start < n - 1) {
	while(start < n - 1 && nums[start] > nums[start + 1])
	    start++;
	end = start;
	while(end < n - 1 && nums[end] <= nums[end + 1])
	    end++;
	cout << "start\t" << start << "\tend\t" << end << endl;
	count += (nums[end] - nums[start]);
	start = end + 1;
    }
    return count;
}

int main() {
    vector<int> nums = {3,4792,47204792,239,7293};
    show(nums);
    cout << maxProfit(nums) << endl;
    return 0;
}

