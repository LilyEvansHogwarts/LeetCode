#include<vector>
#include<iostream>
using namespace std;

void show(vector<int>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << "\t";
    cout << endl;
}

int minPatches(vector<int>& nums, int n) {
    int i = 0, k = nums.size(), add = 0;
    long miss = 1;
    while(miss <= n) {
	if(i < k && nums[i] <= miss) 
	    miss += nums[i++];
	else {
	//    nums.push_back(miss);
	    cout << miss << "\t";
	    miss += miss;
	    add++;
	}
    }
    show(nums);
    return add;
}

int main() {
    vector<int> nums = {1,2,31,33};
    cout << minPatches(nums, 2147483647) << endl;
    return 0;
}

