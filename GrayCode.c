#include<vector>
#include<iostream>
using namespace std;

/*
 Solution 1:
vector<int> graycode(int n) {
    vector<int> res, fact;
    res.push_back(0);
    for(int i = 0;i < n;i++) {
	if(i == 0)
	    fact.push_back(1);
	else
	    fact.push_back(fact[i - 1] * 2);
    }
    int prez;
    for(int i = 0;i < n;i++) {
	prez = res.size();
	for(int j = prez - 1;j >= 0;j--)
	    res.push_back(res[j] + fact[i]);
    }
    return res;
}

*/

//Solution 2:
vector<int> graycode(int n) {
    vector<int> res;
    res.push_back(0);
    int prez;
    for(int i = 0;i < n;i++) {
	prez = res.size();
	for(int j = prez - 1;j >= 0;j--)
	    res.push_back(res[j] | 1 << i);
    }
    return res;
}

void show(vector<int>& board) {
    for(int i = 0;i < board.size();i++) 
	cout << board[i] << "\t";
    cout << endl;
}

int main() {
    vector<int> res = graycode(3);
    show(res);
    return 0;
}

