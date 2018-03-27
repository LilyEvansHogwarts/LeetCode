#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> make_graph(int numCourses, vector<pair<int,int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for(auto p:prerequisites)
        graph[p.second].push_back(p.first);
    return graph;
}

vector<int> compute_degrees(int numCourses, vector<vector<int>>& graph) {
    vector<int> degrees(numCourses,0);
    for(auto g:graph)
        for(auto p:g)
            degrees[p]++;
    return degrees;
}

vector<int> findOrder1(int numCourses, vector<pair<int,int>>& prerequisites) {
    vector<vector<int>> graph = make_graph(numCourses, prerequisites);
    vector<int> degrees = compute_degrees(numCourses, graph);
    vector<int> res(numCourses,0);
    for(int i = 0;i < numCourses;i++) {
        int j = 0;
        for(;j < numCourses;j++)
            if(!degrees[j]) break;
        if(j == numCourses) return vector<int>{};
        res[i] = j;
        degrees[j] = -1;
        for(auto p:graph[j])
            degrees[p]--;
    }
    return res;
}

bool dfs(vector<vector<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& res) {
    if(visited[node]) return false;
    onpath[node] = visited[node] = true;
    for(auto p:graph[node])
        if(onpath[p] || dfs(graph,p,onpath,visited,res))
            return true;
    res.push_back(node);
    return onpath[node] = false;
}


vector<int> findOrder2(int numCourses, vector<pair<int,int>>& prerequisites) {
    vector<vector<int>> graph = make_graph(numCourses, prerequisites);
    vector<bool> onpath(numCourses, false), visited(numCourses, false);
    vector<int> res;
    for(int i = 0;i < numCourses;i++)
        if(!visited[i] && dfs(graph, i, onpath, visited,res))
            return vector<int>{};
    reverse(res.begin(),res.end());
    return res;
}

void show(vector<int>& nums) {
    for(auto num:nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    int numCourses = 2;
    vector<pair<int,int>> prerequisites;
    prerequisites.push_back(make_pair(0,1));
    vector<int> res1 = findOrder1(numCourses, prerequisites);
    vector<int> res2 = findOrder2(numCourses, prerequisites);
    show(res1);
    show(res2);
    return 0;
}
