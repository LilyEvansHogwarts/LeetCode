#include<iostream>
#include<vector>
#include<unordered_map>
#include<string> 
using namespace std;

bool isValid1(char a) {
    return a != '0';
}

bool isValid2(char a, char b) {
    return (a == '1' || (a == '2' && b <= '6'));
}

int numDecodings(string s) {
    int n = s.size();
    if(n == 0 || s[0] == '0')
	return 0;
    if(n == 1)
	return 1;
    int f1 = 1, f2 = 1; // f1 means dp[i - 1], f2 means dp[i - 2]
    int res = 0;
    for(int i = 1;i < n;i++) {
	if(isValid1(s[i]) && isValid2(s[i - 1], s[i])) res = f1 + f2;
	if(!isValid1(s[i]) && isValid2(s[i - 1], s[i])) res = f2;
	if(isValid1(s[i]) && !isValid2(s[i - 1], s[i])) res = f1;
	if(!isValid1(s[i]) && !isValid2(s[i - 1], s[i])) return 0;
	f2 = f1;
	f1 = res;
    }
    return f1;
}

int main() {
    cout << numDecodings("1234") << endl;
    cout << numDecodings("0") << endl;
    cout << numDecodings("01") << endl;
    cout << numDecodings("3434") << endl;
    return 0;
}
