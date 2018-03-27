#include<iostream>
#include<unordered_set>
#include<vector>
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
        for(int p:g)
            degrees[p]++;
    return degrees;
}

bool canFinish1(int numCourses, vector<pair<int,int>>& prerequisites) {
    vector<vector<int>> graph = make_graph(numCourses, prerequisites);
    vector<int> degrees = compute_degrees(numCourses, graph);
    for(int i = 0;i < numCourses;i++) {
        int j = 0;
        for(;j < numCourses;j++)
            if(!degrees[j]) break;
        if(j == numCourses) return false;
        degrees[j] = -1;
        for(auto p:graph[j])
            degrees[p]--;
    }
    return true;
}

bool dfs(vector<vector<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
    if(visited[node]) return false;
    onpath[node] = visited[node] = true;
    for(auto p:graph[node])
        if(onpath[p] || dfs(graph, p, onpath, visited))
            return true;
    return onpath[node] = false;
}

bool canFinish2(int numCourses, vector<pair<int,int>>& prerequisites) {
    vector<vector<int>> graph = make_graph(numCourses, prerequisites);
    vector<bool> onpath(numCourses, false), visited(numCourses, false);
    for(int i = 0;i < numCourses;i++)
        if(!visited[i] && dfs(graph, i, onpath, visited))
            return false;
    return true;
}

void show(bool flag) {
    cout << (flag?"True":"False") << endl;
}

int main() {
    int numCourses = 2;
    vector<pair<int,int>> prerequisites;
    prerequisites.push_back(make_pair(1,0));
    bool flag1 = canFinish1(numCourses, prerequisites);
    bool flag2 = canFinish2(numCourses, prerequisites);
    show(flag1);
    show(flag2);
    return 0;
}

