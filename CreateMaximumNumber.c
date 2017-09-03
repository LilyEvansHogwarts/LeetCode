#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void show(vector<int>& res) {
    for(int i = 0;i < res.size();i++) 
	cout << res[i] << "\t";
    cout << endl;
}

vector<int> getMax(vector<int>& nums, int k) {
    int n = nums.size(), drop = n - k, i = 0;
    if(n == k || n == 0)
	return nums;
    vector<int> res;
    for(auto num:nums) {
	while(drop && res.size() && res.back() < num) {
	    res.pop_back();
	    drop--;
	}
	res.push_back(num);
    }
    res.resize(k);
    return res;
}

vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int i = 0, j = 0, k1 = nums1.size(), k2 = nums2.size();
    if(k1 == 0)
	return nums2;
    if(k2 == 0)
	return nums1;
    while(nums1.size() + nums2.size()) {
	vector<int>& now = (nums1 > nums2? nums1:nums2);
	res.push_back(now[0]);
	now.erase(now.begin());
    }
    return res;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res1, res2, res, best;
    int k1 = nums1.size(), k2 = nums2.size();
    for(int i = 0;i <= k;i++) {
	if(i > k1 || k - i > k2)
	    continue;
	res1 = getMax(nums1, i);
	res2 = getMax(nums2, k - i);
	best = max(best, merge(res1, res2));
    }
    return best;
}

int main() {
    vector<int> nums1 = {6,7};
    vector<int> nums2 = {6,0,4};
    vector<int> res = maxNumber(nums1, nums2, 5);
    show(res);
    return 0;
}

