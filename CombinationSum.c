#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combinationGetRes(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& combination, int begin) {
    if(!target) {
	res.push_back(combination);
	return;
    }
    for(int i = begin;i < candidates.size() && target >= candidates[i];i++) {
	combination.push_back(candidates[i]);
	combinationGetRes(candidates, target - candidates[i], res, combination, i);
	combination.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> combination;
    vector<vector<int> > res;
    int i = 0;
    combinationGetRes(candidates,target,res,combination,i);
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
    vector<int> candidates = {9,8,7,6,5,4,3,2,1};
    int target = 5;
    vector<vector<int> > res = combinationSum(candidates, target);
    show(res);
    return 0;
}
    
