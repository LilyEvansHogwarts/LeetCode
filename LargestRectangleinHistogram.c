#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int n = heights.size(), ret = 0;
    vector<int> index;
    for(int i = 0;i < n;i++) {
	while(index.size() > 0 && heights[index.back()] >= heights[i]) {
	    int h = heights[index.back()];
	    int sidx = index.size() > 1? index.back():0;
	    ret = max(h * (i - sidx), ret);
	    index.pop_back();
	}
	index.push_back(i);
    }
    return ret;
}

int main() {
    vector<int> nums = {2,1,5,6,2,3};
    cout << largestRectangleArea(nums) << endl;
    return 0;
}

