#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(string& s, int start, int end) {
    while(start < end) {
	if(s[start++] != s[end--])
	    return false;
    }
    return true;
}

void dfs(vector<vector<string> >& res, vector<string>& path, string& s, int begin, int n) {
    if(begin == n) {
	res.push_back(path);
	return;
    }
    for(int i = begin;i < n;i++) {
	if(isPalindrome(s, begin, i)) {
	    path.push_back(s.substr(begin, i - begin + 1));
	    dfs(res, path, s, i + 1, n);
	    path.pop_back();
	}
    }
}

vector<vector<string> > partition(string s) {
    int n = s.size();
    vector<vector<string> > res;
    vector<string> path;
    dfs(res, path, s, 0, n);
    return res;
}

void show(vector<vector<string> >& board) {
    for(int i = 0;i < board.size();i++) {
	for(int j = 0;j < board[i].size();j++) {
	    cout << board[i][j] << "\t";
	}
	cout << endl;
    }
}

int main() {
    vector<vector<string> > res = partition("aaaaaaabbbbbbbcccc");
    show(res);
    return 0;
}




