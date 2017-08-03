#include<string>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    for(int i = 0;i < s.size();i++) {
	if(s[i] == '(' || s[i] == '{' || s[i] == '[') 
	    stk.push(s[i]);
	else if(stk.empty() || abs(s[i] - stk.top()) > 2) 
	    return false;
	else 
	    stk.pop();
    }
    if(stk.empty())
	return true;
    else
	return false;
}

int main() {
    cout << isValid("{{)}") << endl;
    return 0;
}
