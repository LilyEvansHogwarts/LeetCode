#include<vector>
#include<string>
#include<iostream>
using namespace std;

void show1(vector<string>& board) {
    for(int i = 0;i < board.size();i++) 
	cout << board[i] << endl;
}

void show2(vector<vector<string> >& board) {
    for(int i = 0;i < board.size();i++) {
	for(int j = 0;j < board[i].size();j++) {
	    cout << board[i][j] << endl;
	}
	cout << endl;
    }
}

bool isValid(vector<int>& temp, int k) {
    int N = temp.size();
    for(int i = 0;i < N;i++) {
	if(k == temp[i] || k + N == temp[i] + i || k - temp[i] == N - i)
	    return false;
    }
    return true;
}

void solve(vector<vector<string> >& res, vector<string>& board, vector<int> temp, int n, int begin) {
    if(begin == n) {
	vector<string> solution;
	for(int i = 0;i < n;i++) 
	    solution.push_back(board[temp[i]]);
	res.push_back(solution);
	return;
    }

    for(int i = 0;i < n;i++) {
	if(isValid(temp,i)) {
	    temp.push_back(i);
	    solve(res, board, temp, n, begin + 1);
	    temp.pop_back();
	}
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<string> board;
    for(int i = 0;i < n;i++) {
	string s = "";
	for(int j = 0;j < n;j++) {
	    if(j == i)
		s += "Q";
	    else
		s += ".";
	}
	board.push_back(s);
    }
    vector<int> temp;
    solve(res, board, temp, n, 0);
    return res;
}


int main() {
    int n = 8;
    vector<vector<string> > res = solveNQueens(n);
 //   show2(res);
    cout << res.size() << endl;
    cout << endl;
    for(int i = 0;i < 12;i++) {
	res = solveNQueens(i);
	cout << i << "\t" << res.size() << endl;
    }
    return 0;
}


