#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define INT_MAX 2147483647
using namespace std;

/* Solution 1:
//s: current expression
//pos: current position
//value: current value
void solve(vector<string>& res, string& nums, int target, string s, int pos, long value, long previous, char ops) {
    if(pos == nums.size() && target == value)
	res.push_back(s);
    for(int i = pos + 1;i <= nums.size();i++) {
	string t = nums.substr(pos, i - pos);
	long v = stol(t);
	if(to_string(v).size() != t.size())
	    continue;
	solve(res, nums, target, s+'+'+t, i, value + v, v, '+');
	solve(res, nums, target, s+'-'+t, i, value - v, v, '-');
	solve(res, nums, target, s+'*'+t, i, (ops == '+'?value - previous + previous * v:(ops == '-'?value + previous - previous * v:value * v)), v*previous, ops);
    }
}

vector<string> addOperators(string nums, int target) {
    vector<string> res;
    if(nums.empty()) 
	return res;
    for(int i = 1;i <= nums.size();i++) {
	string t = nums.substr(0, i);
	long v = stol(t);
	if(to_string(v).size() != t.size())
	    continue;
	solve(res, nums, target, t, i, v, v, '#');
    }
    return res;
}
*/

void solve(vector<string>& res, string nums, string s, int pos, long value, long pre, long val) {
    pre = pre * 10 + nums[pos] - '0';
    if(pre > INT_MAX)
	return;
    if(nums.size() - 1 == pos && value + pre * val == 0)
	res.push_back(s + nums[pos]);
    if(pos == nums.size() - 1)
	return;
    if(pre)
	solve(res, nums, s+nums[pos], pos + 1, value, pre, val);
    solve(res, nums, s+nums[pos]+'+', pos + 1, value + val * pre, 0, 1);
    solve(res, nums, s+nums[pos]+'-', pos + 1, value + val * pre, 0, -1);
    solve(res, nums, s+nums[pos]+'*', pos + 1, value, 0, val * pre);
}

vector<string> addOperators(string nums, int target) {
    vector<string> res;
    if(nums.size() == 0)
	return res;
    solve(res, nums, "", 0, -target, 0, 1);
    return res;
}

void show(vector<string>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i] << endl;
    cout << endl;
}

int main() {
    vector<string> res = addOperators("123",6);
    show(res);
    res = addOperators("232",8);
    show(res);
    res = addOperators("2147483648",-2147483648);
    show(res);
    return 0;
}


