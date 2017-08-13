#include<vector>
#include<iostream>
using namespace std;

int minimumTotal(vector<vector<int> >& triangle) {
    int n = triangle.size();
    if(n == 0)
	return 0;
    vector<int> nums(n + 1, 0);
    for(int i = n - 1;i >= 0;i--) 
	for(int j = 0;j <= i;j++)
	    nums[j] = triangle[i][j] + min(nums[j], nums[j + 1]);
    return nums[0];
}

int main() {
    vector<vector<int> > nums = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(nums) << endl;
    return 0;
}
