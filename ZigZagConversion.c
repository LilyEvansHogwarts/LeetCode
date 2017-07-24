#include<string>
#include<iostream>
using namespace std;

string convert(string s, int numRows) {
    int N = s.size();
    if(numRows == 1 || N <= 1)
	return s;
    int period = 2 * numRows - 2;
    string result;
    for(int i = 0;i < numRows; i++) {
	for(int j = 0;(j*period + i) < N;j++) {
	    cout << s[j*period + i] << endl;
	    result.push_back(s[j*period + i]);
	    if(0 < i && i < numRows - 1 && j*period + period - i < N) {
		cout << s[j*period + period - i] << endl;
		result.push_back(s[j*period + period - i]);
	    }
	}
    }
    return result;
}

int main() {
    string s = "payapayapayapayapaya";
    int num = 3;
    string a = convert(s,num);
    cout << a << endl;
    return 0;
}
		
