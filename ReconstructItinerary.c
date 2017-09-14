#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

void show_vector(vector<pair<string, string> >& l) {
    for(int i = 0;i < l.size();i++) 
	cout << "(" << l[i].first << "," << l[i].second << ")";
    cout << endl;
}

void show_string(vector<string>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << "\t";
    cout << endl;
}

void solve(vector<pair<string, string>>& tickets, vector<string>& res, int i) {
    while(i < tickets.size() && tickets[i].first < res.back()) i++;
    if(i >= tickets.size() || tickets[i].first != res.back()) return;
    pair<string, string> p = tickets[i];
    res.push_back(tickets[i].second);
    tickets.erase(tickets.begin() + i);
    solve(tickets, res, 0);
    if(tickets.size() > 0) {
	res.pop_back();
	tickets.insert(tickets.begin() + i, p);
	solve(tickets, res, i + 1);
    } 
}

vector<string> findItinerary(vector<pair<string, string> > tickets) {
    auto comp = [](pair<string, string>& p1, pair<string, string>& p2) {
	return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second); 
    };
    sort(tickets.begin(), tickets.end(), comp);
    show_vector(tickets);
    vector<string> res = {"JFK"};
    solve(tickets, res, 0);
    return res;
}

int main() {
    vector<pair<string, string> > nums{{"EZE","MEL"},{"AUA","JFK"},{"MEL","OOL"},{"JFK","EZE"},{"LST","AUA"},{"JFK","LST"}};
    vector<string> res = findItinerary(nums);
    show_string(res);
    return 0;
}

