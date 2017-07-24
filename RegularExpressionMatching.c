#include<iostream>
#include<string>
using namespace std;

bool isMatch(string s,string p) {
    int N1 = s.size();
    int N2 = p.size();
    string temp_s,temp_p;
    if(p == "") 
	return s == "";
    if(p.substr(1,1) == "*") {
	temp_s = s;
	while((temp_s[0] == p[0] || p.substr(0,1) == ".") && (temp_s != "")) {
	    if(isMatch(temp_s,p.substr(2,N2 - 2)))
		return true;
	    temp_s = temp_s.substr(1,N1 - 1);
	    N1--;
	}
	return isMatch(temp_s,p.substr(2,N2 - 2));
    }
    if(s == "") return false;
    return (s[0] == p[0] || p.substr(0,1) == ".") && (isMatch(s.substr(1,N1 - 1),p.substr(1,N2 - 1)));
}


int main() {
    string s = "aaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";
    cout << isMatch(s,p) << endl;
    return 0;
}




