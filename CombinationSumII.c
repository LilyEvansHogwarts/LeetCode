#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

/*
 Solution 1:

bool unique(vector<vector<int> >& res, vector<int>& combination) {
    for(int i = 0;i < res.size();i++) {
	if(res[i].size() == combination.size()) {
	    int j = 0;
	    for(;j < combination.size();j++) {
		if(res[i][j] != combination[j])
		    break;
	    }
	    if(j == combination.size())
		return false;
	}
    }
    return true;
}

void combinationGetRes(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& combination, int begin) {
    if(!target && unique(res, combination)) {
	res.push_back(combination);
	return;
    }
    for(int i = begin;i < candidates.size() && target >= candidates[i];i++) {
	combination.push_back(candidates[i]);
	combinationGetRes(candidates, target - candidates[i], res, combination, i+1);
	combination.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > res;
    vector<int> combination;
    int begin = 0;
    combinationGetRes(candidates, target, res, combination, begin);
    return res;
}

*/

//Solution 2:

void combinationGetRes(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& combination, int begin) {
    if(!target) {
	res.push_back(combination);
	return;
    }
    for(int i = begin;i < candidates.size() && target >= candidates[i];i++) {
	if(i > begin && candidates[i] == candidates[i - 1])
	    continue;
	combination.push_back(candidates[i]);
	combinationGetRes(candidates, target - candidates[i], res, combination, i+1);
	combination.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > res;
    vector<int> combination;
    int begin = 0;
    combinationGetRes(candidates, target, res, combination, begin);
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
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int> > res = combinationSum2(candidates, target);
    show(res);
    return 0;
}
