#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void show(vector<vector<int> >& board) {
    for(int i = 0;i < board.size();i++) {
	for(int j = 0;j < board[i].size();j++) {
	    cout << board[i][j] << "\t";
	}
	cout << endl;
    }
}

void permuteGetRes(vector<int>& nums, vector<vector<int> >& res, int begin) {
    if(begin == nums.size() - 1) {
	res.push_back(nums);
	return;
    }
    for(int i = begin;i < nums.size();i++) {
	swap(nums[begin], nums[i]);
	permuteGetRes(nums, res, begin + 1);
	swap(nums[begin], nums[i]);
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > res;
    vector<int> temp;
    permuteGetRes(nums, res, 0);
    return res;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int> > res = permute(nums);
    show(res);
    cout << res.size() << endl;
    return 0;
}
