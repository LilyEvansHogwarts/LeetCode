#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums) {
    int start = 0,step = 0;
    int n = nums.size();
    int temp = 0,temp_start = 0;
    if(n <= 1)
	return 0;
    while(start < n - 1) {
	step++;
	if(start + nums[start] >= n - 1)
	    return step;
	for(int i = start + 1;i <= start + nums[start];i++) {
	    if(i + nums[i] > temp) {
		temp = i + nums[i];
		temp_start = i;
	    }
	}
	start = temp_start;
    }
    return step;
}

int main() {
    vector<int> res;
    //res.push_back(2);
    //res.push_back(3);
    //res.push_back(1);
    //res.push_back(1);
    //res.push_back(4);
    cout << jump(res) << endl;
    return 0;
}



