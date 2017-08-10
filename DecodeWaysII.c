#include<iostream>
#include<vector>
#include<unordered_map>
#include<string> 
using namespace std;
/*
 * Solution 1: 即列举出所有可能的情况，然后用numDecodings去分别求解后加和
 * 这样操作存在的问题是，计算量巨大，并且会产生重复计算的问题
 * "********"会超时
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

int replaceStar(string s) {
    int n = s.size();
    int sum = 0, i = 0;
    while(i < n && s[i] != '*')
	i++;
    if(i < n) {
	for(int j = 0;j < 9;j++) {
	    s[i] = j + '1';
	    sum += replaceStar(s);
	}
    } else 
	sum = numDecodings(s);
    return sum % 1000000007;
}

测试方法:(replaceStar是主函数)
    cout << "**" << "\t" << replaceStar("**") << endl;
*/


/*
 * Solution 2:
int helper(string s) {
    if(s.size() == 1) {
	if(s[0] == '*')
	    return 9;
	return s[0] == '0'?0:1;
    }
    if(s == "**")
	return 15;
    if(s[0] == '*') {
	if(s[1] == '0')
	    return 2;
	return s[1] <= '6'?2:1;
    }
    if(s[1] == '*') {
	if(s[0] == '1')
	    return 9;
	return s[0] == '2'?6:0;
    }
    return stoi(s) <= 26 && stoi(s) >= 10?1:0;
}

int numDecodings(string s) {
    int n = s.size(), p = 1000000007;
    if(n == 0 || s[0] == '0')
	return 0;
    long f2 = 1, f1 = helper(s.substr(0,1));
    for(int i = 1;i < n;i++) {
	long res = f2 * helper(s.substr(i - 1, 2)) + f1 * helper(s.substr(i, 1));
	f2 = f1;
	f1 = res % p;
    }
    return f1;
}

*/

int numDecodings(string s) {
    int n = s.size(), p = 1000000007;
    if(n == 0 || s[0] == '0')
	return 0;
    long f2 = 1, f1, res;
    long one, two;
    f1 = (s[0] == '*'?9:1);
    for(int i = 1;i < n;i++) {
	char a = s[i - 1], b = s[i];
	if(b == '*') {
	    one = f1 * 9;
	    if(a == '*')
		two = f2 * 15;
	    else 
		two = f2 * (a == '1'?9:(a == '2'?6:0));
	} else if(a == '*') {
	    one = f1 * (b == '0'?0:1);
	    two = f2 * (b > '6'?1:2);
	} else {
	    f1 *= (b == '0'?0:1);
	    int temp = (a - '0') * 10 + b - '0';
	    two = f2 * (temp >= 10 && temp <= 26?1:0);
	}
	cout << f2 << "\t" << f1 << endl;
	res = one + two;
	f2 = f1;
	f1 = res % p;
    }
    return f1;
}

int main() {
    long a8 = numDecodings("*");
    long a9 = numDecodings("**");
    long a10 = numDecodings("***");
    cout << a8 << "\t" << a9 << "\t" << a10 << endl;
    cout << a8 * 15 << endl;
    cout << a9 * 9 << endl;
    return 0;
}


