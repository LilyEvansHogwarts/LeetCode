#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void show(vector<int>& nums) {
    for(int i = 0;i < nums.size();i++)
	cout << nums[i] << "\t";
    cout << endl;
}

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.begin() + k);
    int temp;
    for(int i = k;i < nums.size();i++) {
	if(nums[i] > nums[0]) {
	    nums[0] = nums[i];
	    for(int j = 0;j < k-1;j++) {
		if(nums[j] < nums[j + 1])
		    break;
		else {
		    temp = nums[j];
		    nums[j] = nums[j + 1];
		    nums[j + 1] = temp;
		}
	    }
	}
    }
    return nums[0];
}

int main() {
    vector<int> nums = {9,8,7,6,5,4,3,2,1};
    cout << findKthLargest(nums,4) << endl;
    return 0;
}

