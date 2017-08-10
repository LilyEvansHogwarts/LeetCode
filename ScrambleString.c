#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

bool scrambleString(string w1, string w2) {
    if(w1 == w2)
	return true;
    int n = w1.size();
    unordered_map<char, int> need;
    for(int i = 0;i < n;i++) {
	need[w1[i]]++;
	need[w2[i]]--;
    }
    for(int i = 0;i < n;i++) {
	if(need[w1[i]] != 0)
	    return false;
    }
    for(int i = 1;i < n;i++) {
	if(scrambleString(w1.substr(0,i), w2.substr(0,i)) && scrambleString(w1.substr(i), w2.substr(i)))
	    return true;
	if(scrambleString(w1.substr(0,i), w2.substr(n - i)) && scrambleString(w1.substr(i), w2.substr(0, n - i)))
	    return true;
    }
    return false;
}

int main() {
    cout << scrambleString("great", "regat") << endl;
    return 0;
}
