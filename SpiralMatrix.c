#include<vector>
#include<iostream>
using namespace std;

void show_vector(vector<int>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << "\t";
    cout << endl;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.size() == 0 || matrix[0].size() == 0)
	return res;
    vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
    int x = 0, y = -1, line = 0, n = matrix[0].size(), m = matrix.size()-1;
    vector<int> nsteps{n, m};
    while(nsteps[line%2]) {
	for(int i = 0;i < nsteps[line%2];i++) {
	    x += dirs[line][0];
	    y += dirs[line][1];
	    res.push_back(matrix[x][y]);
	}
	nsteps[line%2]--;
	line = (line + 1)%4;
    }
    return res;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> res = spiralOrder(matrix);
    show_vector(res);
    return 0;
}
