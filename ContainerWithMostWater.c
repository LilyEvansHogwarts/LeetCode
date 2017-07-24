#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int N = height.size();
    int l = 0,r = N - 1;
    int area = 0;
    while(l < r) {
	if(height[l] < height[r]) {
	    area = max(area,height[l] * (r - l));
	    l++;
	} else {
	    area = max(area,height[r] * (r - l));
	    r--;
	}
    }
    return area;
}


int main() {
    vector<int> height;
    //height.push_back(245);
    //height.push_back(638);
    //height.push_back(147);
    //height.push_back(258);
    height.push_back(8);
    height.push_back(10);
    height.push_back(14);
    height.push_back(0);
    height.push_back(13);
    height.push_back(10);
    height.push_back(9);
    height.push_back(9);
    height.push_back(11);
    height.push_back(11);
    cout << maxArea(height) << endl;
    return 0;
}



