#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

bool isValid(vector<int>& temp, int k) {
    int N = temp.size();
    for(int i = 0;i < N;i++) {
	if(k == temp[i] || k + N == temp[i] + i || k - temp[i] == k - i)
	    return false;
    }
    return true;
}

void solve(vector<int> temp, int n, int begin, int& count) {
    if(begin == n) {
	count++;
	return;
    }

    for(int i = 0;i < n;i++) {
	if(isValid(temp,i)) {
	    temp.push_back(i);
	    solve(temp,n, begin + 1, count);
	    temp.pop_back();
	}
    }
}

int totalNQueens(int n) {
    vector<int> temp;
    int count = 0;
    solve(temp, n, 0, count);
    return count;
}

int main() {
    for(int i = 0;i < 12;i++) {
	cout << totalNQueens(i) << endl;
    }
    return 0;
}
