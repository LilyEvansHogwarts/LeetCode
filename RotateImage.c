#include<vector>
#include<iostream>
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

void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size(), c1, c2, c3;
    for(int i = 0;i < n/2 + n%2;i++) {
	for(int j = 0;j < n/2;j++) {
	    c1 = matrix[i][j];
	    c2 = matrix[j][n-i-1];
	    c3 = matrix[n-i-1][n-j-1];
	    matrix[i][j] = matrix[n-j-1][i];
	    matrix[j][n-i-1] = c1;
	    matrix[n-i-1][n-j-1] = c2;
	    matrix[n-j-1][i] = c3;
	}
    }
}

int main() {
    //vector<vector<int> > nums = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int> > nums = {{1,2,3,10},{4,5,6,11},{7,8,9,12},{13,14,15,16}};
    show(nums);
    rotate(nums);
    show(nums);
    return 0;
}
