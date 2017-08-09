#include<iostream>
#include<vector>
using namespace std;
/*
 Solution 1:
int uniquePaths(int m, int n) {
    vector<vector<int> > res(m, vector<int> (n, 1));
    for(int i = 1;i < m;i++) 
	for(int j = 1;j < n;j++) 
	    res[i][j] = res[i - 1][j] + res[i][j - 1];
    return res[m - 1][n - 1];
}
*/


// Solution 2:
int uniquePaths(int m, int n) {
    if(m > n) return uniquePaths(n, m);
    vector<int> res(m, 1);
    for(int i = 1;i < n;i++) 
	for(int j = 1;j < m;j++) 
	    res[j] += res[j - 1];
    return res[m - 1];
}



int main() {
    cout << uniquePaths(3, 7) << endl;
    return 0;
}
