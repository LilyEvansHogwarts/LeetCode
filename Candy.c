#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void show(vector<int>& nums) {
    for(int i = 0;i < nums.size();i++)
	cout << nums[i] << "\t";
    cout << endl;
}

int candy(vector<int> ratings) {
    int n = ratings.size(), result = 0;
    if(n <= 1)
	return n;
    vector<int> nums(n, 1);
    for(int i = 1;i < n;i++) {
	if(ratings[i-1] < ratings[i])
	    nums[i] = nums[i-1] + 1;
    }
    for(int i = n - 1;i > 0;i--) {
	if(ratings[i-1] > ratings[i])
	    nums[i-1] = max(nums[i-1], nums[i] + 1);
	result += nums[i];
    }
    result += nums[0];
    return result;
}

int main() {
    vector<int> nums = {1,2,2};
    show(nums);
    int count = candy(nums);
    cout << count << endl;
    return 0;
}
