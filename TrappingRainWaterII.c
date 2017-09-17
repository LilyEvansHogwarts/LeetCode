#include<vector>
#include<iostream>
#include<queue>
#define INT_MIN -2147483648
using namespace std;

int trapRainWater(vector<vector<int> >& heightMap) {
    if(heightMap.size() == 0 || heightMap[0].size() == 0) return 0;
    int ans = 0, Max = INT_MIN, row = heightMap.size(), col = heightMap[0].size();
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    vector<pair<int, int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    for(int i = 0;i < col;i++) {
	visited[0][i] = true;
	visited[row-1][i] = true;
	que.push(make_pair(heightMap[0][i], i));
	que.push(make_pair(heightMap[row-1][i], (row-1)*col + i));
    }
    for(int i = 1;i < row-1;i++) {
	visited[i][0] = true;
	visited[i][col-1] = true;
	que.push(make_pair(heightMap[i][0], i*col));
	que.push(make_pair(heightMap[i][col-1], i*col + col - 1));
    }
    while(!que.empty()) {
	auto val = que.top();
	que.pop();
	int height = val.first, x = val.second / col, y = val.second % col;
	Max = max(Max, height);
	for(auto d:dir) {
	    int xx = x + d.first, yy = y + d.second;
	    if(xx < 0 || yy < 0 || xx >= row || yy >= col || visited[xx][yy]) continue;
	    ans += max(0, Max - heightMap[xx][yy]);
	    visited[xx][yy] = true;
	    que.push(make_pair(heightMap[xx][yy], xx*col + yy));
	}
    }
    return ans;
}

int main() {
    vector<vector<int> > nums = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << trapRainWater(nums) << endl;
    return 0;
}
