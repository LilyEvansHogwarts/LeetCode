#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<pair<int, int> > pa, temp;

void show_pair(vector<pair<int, int> >& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i].first << "\t";
    cout << endl;
    for(int i = 0;i < l.size();i++)
	cout << l[i].second << "\t";
    cout << endl;
    return;
}

void show(vector<int>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << "\t";
    cout << endl;
}

void merge_sort(vector<int>& res, int left, int right) {
    if(left == right)
	return;
    int mid = (left + right) / 2;
    merge_sort(res, left, mid);
    merge_sort(res, mid+1, right);
    for(int i = left, j = mid+1, index = left, adder = 0;i <= mid || j <= right;index++) {
	if(j == right + 1 || (i <= mid && pa[i].second <= pa[j].second)) {
	    temp[index] = pa[i];
	    res[pa[i].first] += adder;
	    i++;
	} else {
	    temp[index] = pa[j];
	    j++;
	    adder++;
	}
    }
    for(int i = left;i <= right;i++)
	pa[i] = temp[i];
    return;
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    for(int i = 0;i < n;i++) 
	pa.push_back(make_pair(i, nums[i]));
    temp = pa;
    merge_sort(res, 0, n-1);
    return res;
}


int main() {
    vector<int> nums = {5,2,6,1,4,3,7,2,4};
    vector<int> res = countSmaller(nums);
    show(nums);
    show(res);
    return 0;
}
