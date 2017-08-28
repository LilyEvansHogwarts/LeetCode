#include<vector>
#include<iostream>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int start = 0, total = 0, tank = 0;
    for(int i = 0;i < n;i++) {
	if((tank += gas[i] - cost[i]) < 0) {
	    total += tank;
	    start = i + 1;
	    tank = 0;
	}
    }
    cout << "total\t" << total << "\ttank\t" << tank << endl;
    return (tank + total < 0? -1:start);
}

int main() {
    vector<int> gas = {4};
    vector<int> cost = {5};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
