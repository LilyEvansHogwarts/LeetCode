#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isMatch(string s, string p) {
    int Ns,Np;
    int Ntemp_p,Ntemp_s;
    string temp_p,temp_s;
    while(s != "") {
	cout << "s:\t" << s << "\tp:\t" << p << endl;
	if(p != "" && (s[0] == p[0] || p.substr(0,1) == "?")) {
	    Ns = s.size();
	    Np = p.size();
	    s = s.substr(1,Ns - 1);
	    p = p.substr(1,Np - 1);
	} else if(p != "" && p.substr(0,1) == "*") {
	    temp_p = p;
	    temp_s = s;
	    Np = p.size();
	    p = p.substr(1,Np - 1);
	} else if(temp_p != "") {
	    Ntemp_p = temp_p.size();
	    Ntemp_s = temp_s.size();
	    p = temp_p.substr(1,Ntemp_p - 1);
	    temp_s = temp_s.substr(1,Ntemp_s - 1);
	    s = temp_s;
	} else
	    return false;
    }
    while(p != "" && p.substr(0,1) == "*") {
	Np = p.size();
	p = p.substr(1,Np - 1);
    }
    return p == "";
}



int main() {
    string s = "aa";
    string p = "*";
    //cout << isMatch(s,p) << endl;
    cout << isMatch("aa","a") << endl;
    cout << isMatch("aa","aa") << endl;
    cout << isMatch("aaa","aa") << endl;
    cout << isMatch("aa","*") << endl;
    cout << isMatch("aa","a*") << endl;
    cout << isMatch("ab","?*") << endl;
    cout << isMatch("aab","c*a*b") << endl;
    cout << isMatch("absisgdisjdajshdauisdhshdkoaisdjkaoskdjosidhaoishdokasncoksoiaoi","a************b") << endl;
    cout << isMatch("b","*?*?") << endl;
    cout << isMatch("abefcdgiescdfimde","ab*cd?i*de") << endl;
    cout << isMatch("b","*?*") << endl;
    cout << isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb","b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a") << endl;
    cout << isMatch("zacabz","*a?b*") << endl;
    cout << isMatch("aaaa","***a") << endl;
    cout << isMatch("mississippi","m*si*") << endl;
    return 0;
}

