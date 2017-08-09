#include<vector>
#include<iostream>
using namespace std;
/*
 * Solution 1:
int uniquePathsWithObstacles(vector<vector<int> >& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int> > res(m, vector<int> (n, 0));
    int flag = 0;
    for(int i = 0;i < m;i++) {
	if(flag == 1 || board[i][0] == 1) {
	    flag = 1;
	    res[i][0] = 0;
	} else
	    res[i][0] = 1;
    }
    flag = 0;
    for(int i = 0;i < n;i++) {
	if(flag == 1 || board[0][i] == 1) {
	    flag = 1;
	    res[0][i] = 0;
	} else
	    res[0][i] = 1;
    }
    for(int i = 1;i < m;i++) {
	for(int j = 1;j < n;j++) {
	    if(board[i][j] == 1)
		res[i][j] = 0;
	    else
		res[i][j] = res[i - 1][j] + res[i][j - 1];
	}
    }
    return res[m - 1][n - 1];
}
*/

/*
 * Solution 2:
int uniquePathsWithObstacles(vector<vector<int> >& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int> > res(m + 1, vector<int> (n + 1, 0));
    res[0][1] = 1;
    for(int i = 1;i <= m;i++) {
	for(int j = 1;j <= n;j++) {
	    if(!board[i - 1][j - 1])
		res[i][j] = res[i - 1][j] + res[i][j - 1];
	}
    }
    return res[m][n];
}
*/


int uniquePathsWithObstacles(vector<vector<int> >& board) {
    int m = board.size(), n = board[0].size();
    vector<int> res(n, 0);
    res[0] = 1;
    for(int i = 0;i < m;i++) {
	for(int j = 0;j < n;j++) {
	    if(board[i][j] == 1)
		res[j] = 0;
	    else
		res[j] += res[j - 1];
	}
    }
    return res[n - 1];
}
int main() {
    vector<vector<int> > nums = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(nums) << endl;
    return 0;
}

