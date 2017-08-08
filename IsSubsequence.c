#include<iostream>
#include<string>
using namespace std;

bool isSequence(string s, string t) {
    int Ns = s.size(), Nt = t.size();
    int is = 0, it = 0;
    while(is < Ns && it < Nt) {
	if(s[is] == t[it]) {
	    is++;
	    it++;
	} else
	    it++;
    }
    if(is >= Ns)
	return true;
    else
	return false;
}

int main() {
    cout << isSequence("abc", "ahbgdc") << endl;
    return 0;
}
