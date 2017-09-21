#include<vector>
#include<algorithm>
#include<iostream>
#define xlength 5
#define ylength 6
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

bool operator< (const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) {
    return p1.first < p2.first || (p1.first == p2.first && p1.second.first < p2.second.first);
}

void dfs(vector<vector<int>>& visited, vector<vector<int>>& degree, int x, int y, int num, int& solutions, vector<vector<vector<int>>>& res) {
    num++;
    visited[x][y] = num;
    auto comp = [](const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) {
	return p1.first < p2.first;
    };
    if(num < xlength * ylength) {
	vector<pair<int, pair<int, int>>> q;
	if(isValid(visited, x+1, y+2) && degree[x+1][y+2]) 
	    q.push_back(make_pair(degree[x+1][y+2], make_pair(x+1, y+2)));
	if(isValid(visited, x+1, y-2) && degree[x+1][y-2]) 
	    q.push_back(make_pair(degree[x+1][y-2], make_pair(x+1, y-2)));
	if(isValid(visited, x-1, y+2) && degree[x-1][y+2]) 
	    q.push_back(make_pair(degree[x-1][y+2], make_pair(x-1, y+2)));
	if(isValid(visited, x-1, y-2) && degree[x-1][y-2]) 
	    q.push_back(make_pair(degree[x-1][y-2], make_pair(x-1, y-2)));
	if(isValid(visited, x+2, y+1) && degree[x+2][y+1]) 
	    q.push_back(make_pair(degree[x+2][y+1], make_pair(x+2, y+1)));
	if(isValid(visited, x+2, y-1) && degree[x+2][y-1]) 
	    q.push_back(make_pair(degree[x+2][y-1], make_pair(x+2, y-1)));
	if(isValid(visited, x-2, y+1) && degree[x-2][y+1]) 
	    q.push_back(make_pair(degree[x-2][y+1], make_pair(x-2, y+1)));
	if(isValid(visited, x-2, y-1) && degree[x-2][y-1]) 
	    q.push_back(make_pair(degree[x-2][y-1], make_pair(x-2, y-1)));
	sort(q.begin(), q.end(), comp);
	for(auto qq:q) 
	    dfs(visited, degree, qq.second.first, qq.second.second, num, solutions, res);
    } else if((abs(x - start_x) == 2 && abs(y - start_y) == 1) || (abs(x - start_x) == 1 && abs(y - start_y) == 2)) {
	res.push_back(visited);
	show_vector_vector(visited);
	solutions++;
    } 
    visited[x][y] = 0;
}

void findDegree(vector<vector<int>>& degree) {
    auto valid = [](const int& x, const int& y) {
	return x >= 0 && y >= 0 && x < xlength && y < ylength;
    };
    for(int i = 0;i <= xlength/2;i++) {
	for(int j = 0;j <= ylength/2;j++) {
	    int n = 0;
	    n += valid(i+1, j+2);
	    n += valid(i+1, j-2);
	    n += valid(i-1, j+2);
	    n += valid(i-1, j-2);
	    n += valid(i+2, j+1);
	    n += valid(i+2, j-1);
	    n += valid(i-2, j+1);
	    n += valid(i-2, j-1);
	    degree[i][j] = n;
	    degree[xlength-i-1][ylength-j-1] = n;
	    degree[xlength-i-1][j] = n;
	    degree[i][ylength-j-1] = n;
	}
    }
}

int main() {
    vector<vector<int>> visited(xlength,vector<int>(ylength, 0));
    int solutions = 0;
    int states = 0;
    vector<vector<vector<int>>> res;
    vector<vector<int>> degree(xlength, vector<int>(ylength, 0));
    findDegree(degree);
    dfs(visited, degree, start_x, start_y, 0, solutions, res);
    cout << solutions << endl;
    return 0;
}


