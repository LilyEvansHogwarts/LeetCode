#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if(n < 3)
	return 0;
    vector<int> maxleft(n,0);
    vector<int> maxright(n,0);
    maxleft[0] = height[0];
    maxright[n - 1] = height[n - 1];
    for(int i = 1;i < n - 1;i++) {
	maxleft[i] = max(maxleft[i - 1],height[i]);
	maxright[n - i - 1] = max(maxright[n - i],height[n - i - 1]);
    }
    int sum = 0;
    for(int i = 1;i < height.size() - 1;i++) {
	cout << "maxleft\t" << maxleft[i] << "\tmaxright\t" << maxright[i] << "\theight\t" << height[i] << endl;
	sum = sum + min(maxleft[i],maxright[i]) - height[i];
    }
    return sum;


}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    vector<int> height1;
    cout << trap(height1) << endl;
    return 0;
}
