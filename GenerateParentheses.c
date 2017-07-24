#include<iostream>
#include<vector>
using namespace std;

void generateParenthesesRe(vector<string>& res,int left,int right,string s) {
    if(left == 0 && right == 0)
	res.push_back(s);
    if(left > 0) 
	generateParenthesesRe(res,left-1,right,s + "(");
    if(left < right) 
	generateParenthesesRe(res,left,right-1,s + ")");
}

vector<string> generateParentheses(int n) {
    vector<string> res;
    generateParenthesesRe(res,n,n,"");
    return res;
}

int main() {
    vector<string> out = generateParentheses(5);
    for(int i = 0;i < out.size();i++) {
	cout << out[i] << endl;
    }
    return 0;
}

