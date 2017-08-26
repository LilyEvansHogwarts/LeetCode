#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

void show(vector<int> nums) {
    for(int i = 0;i < nums.size();i++) 
	cout << nums[i] << "\t";
    cout << endl;
}

vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    if(input.size() == 0)
	return res;
    for(int i = 0;i < input.size();i++) {
	if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
	    vector<int> res1 = diffWaysToCompute(input.substr(0,i));
	    cout << "s1\t" << input.substr(0,i) << "\ts2\t" << input.substr(i+1) << endl;
	    cout << "res1\t";
	    show(res1);
	    vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
	    cout << "res2\t";
	    show(res2);
	    cout << endl;
	    for(int k1 = 0;k1 < res1.size();k1++) {
		for(int k2 = 0;k2 < res2.size();k2++) {
		    if(input[i] == '+')
			res.push_back(res1[k1] + res2[k2]);
		    else if(input[i] == '-')
			res.push_back(res1[k1] - res2[k2]);
		    else
			res.push_back(res1[k1] * res2[k2]);
		}
	    }
	}
    }
    if(res.empty())
	res.push_back(atoi(input.c_str()));
    return res;
}

int main() {
    vector<int> res = diffWaysToCompute("10+5");
    show(res);
    return 0;
}
