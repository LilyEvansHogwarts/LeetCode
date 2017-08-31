#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
    auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    };
    sort(people.begin(), people.end(), comp);
    vector<pair<int, int> > res;
    int n = people.size();
    for(auto p : people) 
	res.insert(res.begin() + p.second, p);
    return res;
}

void show_pair(vector<pair<int, int> >& l) {
    cout << "[";
    for(int i = 0;i < l.size();i++) 
	cout << "(" << l[i].first << "," << l[i].second << ")";
    cout << "]" << endl;
}

int main() {
    vector<pair<int, int>> nums;
    nums.push_back(make_pair(7,0));
    nums.push_back(make_pair(4,4));
    nums.push_back(make_pair(7,1));
    nums.push_back(make_pair(5,0));
    nums.push_back(make_pair(6,1));
    nums.push_back(make_pair(5,2));
    vector<pair<int, int> > res = reconstructQueue(nums);
    show_pair(res);
    return 0;
}
