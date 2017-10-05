#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    if(nums.size() > 1) {
	int slow = nums[0], fast = nums[nums[0]];
	while(slow != fast) {
	    slow = nums[slow];
	    fast = nums[nums[fast]];
	    cout << "cycle1 " << "slow " << slow << " fast " << fast << endl;
	}
	fast = 0;
	while(fast != slow) {
	    fast = nums[fast];
	    slow = nums[slow];
	    cout << "cycle2 " << "slow " << slow << " fast " << fast << endl;
	}
	return slow;
    } 
    return -1;
}

void show(vector<int>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {5,3,1,4,2,3};
    show(nums);
    cout << findDuplicate(nums) << endl;
    return 0;
}
