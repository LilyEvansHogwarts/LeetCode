#include<vector>
#include<iostream>
using namespace std;

/* Solution 1:
bool solve(vector<vector<int>>& matrix, int target, int left, int right, int up, int down) {
    cout << "left\t" << left << "\tright\t" << right << "\tup\t" << up << "\tdown\t" << down << endl;
    int i = left, j = up;
    if(matrix[up][left] > target || matrix[down][right] < target)
	return false;
    while(matrix[j][i] < target) {
	if(i == right) 
	    return solve(matrix, target, right, left, j+1, down);
	else if(j == down)
	    return solve(matrix, target, i+1, right, up, down);
	else {
	    i++;
	    j++;
	}
    }
    if(matrix[j][i] == target)
	return true;
    return solve(matrix, target, left, i-1, j, down) | solve(matrix, target, i, right, up, j-1);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    return solve(matrix, target, 0, n-1, 0, m-1);
}

*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty())
	return false;
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n-1;
    while(i >= 0 && i < m && j >= 0 && j < n) {
	if(matrix[i][j] < target)
	    i++;
	else if(matrix[i][j] == target)
	    return true;
	else
	    j--;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    vector<vector<int>> nums = {{1,1}};
    cout << searchMatrix(matrix, 23) << endl;
    cout << searchMatrix(nums, 1) << endl;
    return 0;
}
