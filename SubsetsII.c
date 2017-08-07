#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*
 Solution 1:
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
*/
void show(vector<vector<int> >& board) {
    for(int i = 0;i < board.size();i++) {
	for(int j = 0;j < board[i].size();j++) {
	    cout << board[i][j] << "\t";
	}
	cout << endl;
    }
}

//Solution 2:
vector<vector<int> > subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > res(1);
    vector<int> temp;
    int N = nums.size();
    int prez, count;
    for(int i = 0;i < N;) {
	prez = res.size();
	count = 0;
	while(count + i < N && nums[i + count] == nums[i])
	    count++;
	for(int j = 0;j < prez;j++) {
	    temp = res[j];
	    for(int k = 0;k < count;k++) {
		temp.push_back(nums[i]);
	        res.push_back(temp);
	    }
	}
	i += count;
    }
    return res;
}


int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int> > res = subsets(nums);
    show(res);
    return 0;
}
