#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int> >& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> res(n, 0);
    res[0] = grid[0][0];
    for(int i = 1;i < n;i++)
	res[i] = res[i - 1] + grid[0][i];
    for(int i = 1;i < m;i++) {
	res[0] = res[0] + grid[i][0];
	for(int j = 1;j < n;j++) 
	    res[j] = min(res[j-1], res[j]) + grid[i][j]; 
    }

    return res[n - 1];
}

int main() {
    vector<vector<int> > res = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(res) << endl;
    return 0;
}
