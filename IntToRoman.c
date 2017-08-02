#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string intToRoman(int num) {
    unordered_map<int, string> need;
    need[1] = "I";
    need[5] = "V";
    need[10] = "X";
    need[50] = "L";
    need[100] = "C";
    need[500] = "D";
    need[1000] = "M";
    string s;
    int start = 1000;
    while(start > 0 && num > 0) {
	while(num / start > 0) {
	    num = num - start;
	    s = s + need[start];
	}
	if(num % start >= 0.9 * start) {
	    num = num - 0.9 * start;
	    s = s + need[start / 10] + need[start];
	} else if(num % start >= 0.5 * start) {
	    num = num - 0.5 * start;
	    s = s + need[start / 2];
	} else if(num % start >= 0.4 * start) {
	    num = num - 0.4 * start;
	    s = s + need[start / 10] + need[start / 2];
	}
	start = start / 10;
    }
    return s;
}

int main() {
    cout << intToRoman(1) << endl;
    cout << intToRoman(4) << endl;
    cout << intToRoman(9) << endl;
    cout << intToRoman(2444) << endl;
    return 0;
}
