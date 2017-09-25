#include<vector>
#include<algorithm>
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

bool isValid(vector<vector<int>>& visited, int x, int y, int level) {
    return x >= 0 && y >= 0 && x < xlength && y < ylength && visited[x][y] == 0;
}

int dfs_iter(vector<vector<int>>& visited, vector<vector<int>>& degree, int x, int y) {
    vector<pair<int, pair<int, int>>> res;
    vector<pair<int, int>> ll;
    int level = 1, solutions = 0;
    res.push_back(make_pair(level, make_pair(x, y)));
    auto comp = [](const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) {
	return p1.first < p2.first;
    };
    while(!res.empty()) {
	pair<int, pair<int, int>> temp = res.back();
	res.pop_back();
	x = temp.second.first;
	y = temp.second.second;
	level = temp.first;
	//用ll来记录已经被visited到的点，每次都去便利这个ll，把level大于等于level的点对应visit赋值为0，这对应于dfs里backtrack的时候把visit恢复为0,也可以每次去便利visit将level大于等于level的点赋0
/*	while(!ll.empty() && visited[ll.back().first][ll.back().second] >= level) {
	    visited[ll.back().first][ll.back().second] = 0;
	    ll.pop_back();
	}
	ll.push_back(temp.second);
	*/

	for(int i = 0;i < xlength;i++) 
	    for(int j = 0;j < ylength;j++)
		if(visited[i][j] >= level)
		    visited[i][j] = 0;
	visited[x][y] = level;
//	cout << level <<"\t" << x << "\t" << y << "\t" << solutions << endl;
//	show_vector_vector(visited);
	if(level < xlength * ylength) {
	    vector<pair<int, pair<int, int>>> q;
	    if(isValid(visited, x+1, y+2, level) && degree[x+1][y+2]) 
		q.push_back(make_pair(degree[x+1][y+2], make_pair(x+1, y+2)));
	    if(isValid(visited, x+1, y-2, level) && degree[x+1][y-2]) 
		q.push_back(make_pair(degree[x+1][y-2], make_pair(x+1, y-2)));
	    if(isValid(visited, x-1, y+2, level) && degree[x-1][y+2]) 
		q.push_back(make_pair(degree[x-1][y+2], make_pair(x-1, y+2)));
	    if(isValid(visited, x-1, y-2, level) && degree[x-1][y-2]) 
		q.push_back(make_pair(degree[x-1][y-2], make_pair(x-1, y-2)));
	    if(isValid(visited, x+2, y+1, level) && degree[x+2][y+1]) 
		q.push_back(make_pair(degree[x+2][y+1], make_pair(x+2, y+1)));
	    if(isValid(visited, x+2, y-1, level) && degree[x+2][y-1]) 
		q.push_back(make_pair(degree[x+2][y-1], make_pair(x+2, y-1)));
	    if(isValid(visited, x-2, y+1, level) && degree[x-2][y+1]) 
		q.push_back(make_pair(degree[x-2][y+1], make_pair(x-2, y+1)));
	    if(isValid(visited, x-2, y-1, level) && degree[x-2][y-1]) 
		q.push_back(make_pair(degree[x-2][y-1], make_pair(x-2, y-1)));
	    sort(q.begin(), q.end(), comp);
	    for(int i = q.size()-1;i >= 0;i--) {
		q[i].first = level+1;
		res.push_back(q[i]);
//		cout << "(" << q[i].second.first << "," << q[i].second.second << ")";
	    }
//	    cout << endl;
	} else if((abs(x - start_x) == 2 && abs(y - start_y) == 1) || (abs(x - start_x) == 1 && abs(y - start_y) == 2)) {
	    solutions++;
	    show_vector_vector(visited);
	}
    }
    return solutions;
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
    int states = 0;
    vector<vector<int>> degree(xlength, vector<int>(ylength, 0));
    findDegree(degree);
    int solutions = 0;
    solutions = dfs_iter(visited, degree, start_x, start_y);
    cout << solutions << endl;
    return 0;
}


