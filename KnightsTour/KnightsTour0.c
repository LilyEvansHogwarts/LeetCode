#include<vector>
#include<iostream>
#define xlength 8
#define ylength 8
#define start_x 1
#define start_y 2
using namespace std;

void show_vector_vector(vector<vector<int>>& l) {
    for(int i = 0;i < l.size();i++) {
	for(int j = 0;j < l[i].size();j++) {
	    cout << l[i][j] << "\t";
	}
	cout << endl;
    }
    cout << endl;
}

bool isValid(vector<vector<int>>& visited, int x, int y) {
    return x >= 0 && y >= 0 && x < xlength && y < ylength && visited[x][y] == 0;
}

void dfs(vector<vector<int>>& visited, int x, int y, int num, int& solutions) {
    num++;
    visited[x][y] = num;
    if(num < xlength * ylength) {
	if(isValid(visited, x + 2, y + 1)) 
	    dfs(visited, x + 2, y + 1, num, solutions);
	if(isValid(visited, x + 2, y - 1)) 
	    dfs(visited, x + 2, y - 1, num, solutions);
	if(isValid(visited, x - 2, y + 1)) 
	    dfs(visited, x - 2, y + 1, num, solutions);
	if(isValid(visited, x - 2, y - 1)) 
	    dfs(visited, x - 2, y - 1, num, solutions);
	if(isValid(visited, x + 1, y + 2)) 
	    dfs(visited, x + 1, y + 2, num, solutions);
	if(isValid(visited, x + 1, y - 2)) 
	    dfs(visited, x + 1, y - 2, num, solutions);
	if(isValid(visited, x - 1, y + 2)) 
	    dfs(visited, x - 1, y + 2, num, solutions);
	if(isValid(visited, x - 1, y - 2)) 
	    dfs(visited, x - 1, y - 2, num, solutions);
    } else if((abs(x - start_x) == 2 && abs(y - start_y) == 1) || (abs(x - start_x) == 1 && abs(y - start_y) == 2)) {
	show_vector_vector(visited);
	solutions++;
    } 
    visited[x][y] = 0;
}

int main() {
    vector<vector<int>> visited(xlength,vector<int>(ylength, 0));
    int solutions = 0;
    int states = 0;
    dfs(visited, start_x, start_y, 0, solutions);
    cout << solutions << endl;
    return 0;
}


