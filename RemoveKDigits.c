#include<string>
#include<iostream>
using namespace std;

string removeKdigits(string num, int k) {
    int n = num.size(), top = 0, digits = n - k;
    string res(n,'0');
    for(int i = 0;i < n;i++) {
	while(top > 0 && k > 0 && res[top-1] > num[i]) {
	    k--;
	    top--;
	}
	res[top++] = num[i];
    }
    int i = 0;
    while(i < digits && res[i] == '0') i++;
    return (i == digits?"0":res.substr(i, digits - i));
}

int main() {
    string num = "1432219";
    int k = 3;
    string res = removeKdigits(num, k);
    cout << res << endl;
    return 0;
}
