#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
    int n3 = 0, n2 = 0, n1 = 0, n = 0;
    for(int i = 0;i < nums.size();i++) {
	n = max(max(n2, n3) + nums[i], n1);
	n3 = n2;
	n2 = n1;
	n1 = n;
    }
    return n;
}

int main() {
    vector<int> nums = {2,3,5,2,5,2,5,2,3,2,4,7};
    cout << rob(nums) << endl;
    return 0;
}
