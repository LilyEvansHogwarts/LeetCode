#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void solve(vector<vector<int> >& res, vector<int> temp, vector<int>& nums, int begin) {
    res.push_back(temp);
    for(int i = begin;i < nums.size();i++) {
	if(i > begin && nums[i] == nums[i - 1])
	    continue;
	temp.push_back(nums[i]);
	solve(res, temp, nums, i + 1);
	temp.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    vector<int> temp;
    solve(res, temp, nums, 0);
    return res;
}

void show(vector<vector<int> >& board) {
    for(int i = 0;i < board.size();i++) {
	for(int j = 0;j < board[i].size();j++) {
	    cout << board[i][j] << "\t";
	}
	cout << endl;
    }
}

int main() {
    vector<int> nums = {1,2,2,2,2};
    vector<vector<int> > res = subsets(nums);
    show(res);
    return 0;
}
