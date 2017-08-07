#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int> >& res, vector<int>& temp, int begin, int n, int k) {
    if(temp.size() == k) {
	res.push_back(temp);
	return;
    }
    for(int i = begin;i <= n;i++) {
	temp.push_back(i);
	solve(res, temp, i + 1, n, k);
	temp.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res;
    vector<int> temp;
    solve(res, temp, 1, n, k);
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
    vector<vector<int> > res = combine(8,5);
    show(res);
    return 0;
}

