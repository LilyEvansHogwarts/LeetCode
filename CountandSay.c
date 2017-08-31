#include<iostream>
#include<string>
using namespace std;

string solve(string num) {
    string res;
    int n = num.size(), pre = num[0], count = 1, i;
    for(i = 1;i < n;i++) {
	if(num[i] == pre) 
	    count++;
	else {
	    res += (count + '0');
	    res += num[i-1];
	    pre = num[i];
	    count = 1;
	}
    }
    res += (count + '0');
    res += num[i-1];
    return res;
}

string countAndSay(int n) {
    int i = 1;
    string res = "1";
    while(i < n) {
	res = solve(res);
	i++;
    }
    return res;
}

int main() {
    string res = countAndSay(10);
    cout << res << endl;
    return 0;
}
