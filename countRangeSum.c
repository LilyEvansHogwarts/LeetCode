#include<vector>
#include<iostream>
using namespace std;

vector<long> s, sum;

void show_vector(vector<long>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << "\t";
    cout << endl;
}

int merge_sort(int l, int r, int lower, int upper) {
    if(l == r)
	return 0;
    int mid = (l + r) / 2;
    int count = merge_sort(l, mid, lower, upper) + merge_sort(mid + 1, r, lower, upper);
    for(int i = l,index = l, j, start = mid + 1, k = mid + 1;i <= mid;i++) {
	while(start <= r && sum[start] - sum[i] < lower)
	    start++;
	j = start;
	while(j <= r && sum[j] - sum[i] <= upper)
	    j++;
	while(k <= r && sum[k] < sum[i])
	    s[index++] = sum[k++];
	s[index++] = sum[i];
	count += (j - start);
    }
    for(int i = l;i <= r;i++)
	sum[i] = s[i];
    return count;
}


int countRangeSum(vector<int>& nums, int lower, int upper) {
    long temp = 0;
    sum.push_back(0);
    for(int i = 0;i < nums.size();i++) {
	temp += nums[i];
	sum.push_back(temp);
    }
    s = sum;
    show_vector(sum);
    return merge_sort(0, sum.size() - 1, lower, upper);
}

int main() {
    vector<int> nums = {-2147483647, 0, -2147483647, 2147483647};
    cout << countRangeSum(nums, -2, 2) << endl;
    return 0;
}
