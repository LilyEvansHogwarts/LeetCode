#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

double findMedianNumber(vector<int> &nums) {
    int N = nums.size();
    if (N % 2) {
	return nums[(N - 1) / 2];
    }
    else {
	double a = nums[N/2], b = nums[N/2 - 1];
	double sum = (a + b)/2;
	return sum;
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    vector<int> res;
    if (N1 == 0) return findMedianNumber(nums2);
    else if (N2 == 0) return findMedianNumber(nums1);
    else {
	int i1 = 0, i2 = 0;
	while (i1 < N1 || i2 < N2) {
	    if (i2 >= N2 || (i1 < N1 && nums1[i1] <= nums2[i2])) {
		res.push_back(nums1[i1]);
		i1++;
	    }
	    else {
		res.push_back(nums2[i2]);
		i2++;
	    }
	}
	return findMedianNumber(res);
    }
}

int main() {
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(4);
    double result;
    result = findMedianSortedArrays(nums1,nums2);
    cout << result << endl;
    return 0;
}

