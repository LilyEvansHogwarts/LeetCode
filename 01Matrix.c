#include<vector>
#include<iostream>
#define INT_MAX 2147483647
using namespace std;

void show(vector<vector<int> >& l) {
    for(int i = 0;i < l.size();i++) {
	for(int j = 0;j < l[0].size();j++) {
	    cout << l[i][j] << "\t";
	}
	cout << endl;
    }
    cout << endl;
}

vector<vector<int>> updateMatrix(vector<vector<int> >& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return matrix;
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<int> > dp(row, vector<int>(col, INT_MAX));
    for(int i = 0;i < row;i++) {
	for(int j = 0;j < col;j++) {
	    if(matrix[i][j] == 0)
		dp[i][j] = 0;
	    else {
		if(i && dp[i-1][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
		if(j && dp[i][j-1] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
	    }
	}
    }
    for(int i = row-1;i >= 0;i--) {
	for(int j = col-1;j >= 0;j--) {
	    if(matrix[i][j] == 0)
		dp[i][j] = 0;
	    else {
		if(i < row-1 && dp[i+1][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
		if(j < col-1 && dp[i][j+1] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
	    }
	}
    }
    return dp;
}

int main() {
    vector<vector<int> > nums = {{0,0,0},{0,1,0},{0,0,0}};
    show(nums);
    vector<vector<int> > res = updateMatrix(nums);
    show(res);
    return 0;
}
