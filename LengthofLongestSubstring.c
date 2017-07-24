#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int N = s.size();
    if(N == 0)
	return 0;
    int result = 1;
    int flag;
    int k;
    for(int i = 0;i < N;i++) {
	for(int j = i + 1;j < N;j++) {
	    flag = 0;
	    for(k = j - 1;k >= i;k--) {
		if(s[k] == s[j]) {
		    flag = 1;
		    break;
		}
	    }
	    if(flag == 0 && result < j + 1 - i)
		result = j + 1 - i;
	    if(flag == 1) {
		i = k;
		break;
	    }
	}
    }
    return result;
}

int main() {
    string s = "abcabcdabcdef";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
