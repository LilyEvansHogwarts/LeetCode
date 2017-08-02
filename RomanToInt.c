#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> need;
    need['I'] = 1;
    need['V'] = 5;
    need['X'] = 10;
    need['L'] = 50;
    need['C'] = 100;
    need['D'] = 500;
    need['M'] = 1000;
    int sum = 0;
    int N = s.size();
    for(int i = 0;i < N;i++) {
	if(i < N - 1 && need[s[i]] < need[s[i + 1]])
	    sum -= need[s[i]];
	else
	    sum += need[s[i]];
    }
    return sum;
}

int main() {
    cout << romanToInt("MCDLXXVI") << endl;
    return 0;
}
