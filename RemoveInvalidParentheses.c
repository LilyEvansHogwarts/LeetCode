#include<vector>
#include<string>
#include<iostream>
#include<unordered_set>
using namespace std;

void show_vector(vector<string>& l) {
    for(auto ll:l)
	cout << ll << endl;
    cout << endl;
}

void solve(string s, int ind, int left, int right, int pair, string path, unordered_set<string>& res) {
    if(ind == s.size()) {
	if(left == 0 && right == 0 && pair == 0)
	    res.insert(path);
	return;
    }
    if(s[ind] != '(' && s[ind] != ')')
	solve(s, ind + 1, left, right, pair, path + s[ind], res);
    else if(s[ind] == '(') {
	if(left > 0)
	    solve(s, ind + 1, left - 1, right, pair, path, res);
	solve(s, ind + 1, left, right, pair + 1, path + s[ind], res);
    } else {
	if(right > 0)
	    solve(s, ind + 1, left, right - 1, pair, path, res);
	if(pair > 0)
	    solve(s, ind + 1, left, right, pair - 1, path + s[ind], res);
    }
}

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> res;
    int left = 0, right = 0;
    for(auto c:s) {
	if(c == '(')
	    left++;
	else if(c == ')') {
	    if(left > 0)
		left--;
	    else right++;
	}
    }
    solve(s, 0, left, right, 0, "", res);
    return vector<string>(res.begin(), res.end());
}

int main() {
    string s = "()())()";
    vector<string> res = removeInvalidParentheses(s);
    show_vector(res);
    return 0;
}

