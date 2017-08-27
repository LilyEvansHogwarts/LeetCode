#include<vector>
#include<iostream>
#define HALF_INT_MAX 1073741823
using namespace std;

vector<int> s;

void show(vector<int>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << "\t";
    cout << endl;
}

int merge_sort(vector<int>& nums, int l, int r) {
    if(l == r)
	return 0;
    int mid = (l + r) / 2;
    int count = merge_sort(nums, l, mid) + merge_sort(nums, mid + 1, r);
    for(int i = l, index = l, j = mid + 1, k = mid + 1;i <= mid;i++) {
	while(j <= r && nums[i] / 2.0 > nums[j])
	    j++;
	count += (j - mid - 1);
	while(k <= r && nums[k] < nums[i])
	    s[index++] = nums[k++];
	s[index++] = nums[i];
    }
    for(int i = l;i <= r;i++)
	nums[i] = s[i];
    cout << "left\t" << l << "\tright\t" << r << "\tcount\t" << count << endl;
    show(nums);
    return count;
}

int reversePairs(vector<int>& nums) {
    if(nums.size() == 0)
	return 0;
    s = nums;
    return merge_sort(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647};
    cout << reversePairs(nums) << endl;
    return 0;
}
