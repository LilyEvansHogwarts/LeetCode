#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if(m == 0 || matrix[0].size() == 0) return false;
    int n = matrix[0].size(), i = 0, j = n-1;
    while(i < m && i >= 0 && j >= 0 && j < n) {
	cout << "i " << i << " j " << j << " matrix[i][j] " << matrix[i][j] <<endl;
	if(matrix[i][j] < target)
	    i++;
	else if(matrix[i][j] > target)
	    j--;
	else
	    return true;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout << searchMatrix(matrix, 3) << endl;
    return 0;
}
	

