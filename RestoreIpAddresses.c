#include<string>
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>& res, string s, string temp, int num, int begin, int n) {
    //begin: begin of the index
    //num: number of the '.'
    if(num > 4)
	return;
    if(begin == n && num == 4) {
	res.push_back(temp);
	return;
    }

    for(int i = 1;i < 4;i++) {
	if(begin + i > n) break;
	string k = s.substr(begin, i);
	if((k[0] == '0' && k.size() > 1) || (i == 3 && (k[0] - '0') * 100 + (k[1] - '0') * 10 + k[2] - '0' >= 256))
	    continue;
	solve(res, s, temp + k + (num == 3?"":"."), num + 1, begin + i, n);
    }
}


vector<string> restoreIpAddresses(string s) {
    string temp = "";
    int n = s.size();
    vector<string> res;
    solve(res, s, temp, 0, 0, n);
    return res;
}

void show(vector<string>& s) {
    for(int i = 0;i < s.size();i++)
	cout << s[i] << endl;
}

int main() {
    vector<string> res = restoreIpAddresses("25525511123");
    show(res);
    return 0;
}

