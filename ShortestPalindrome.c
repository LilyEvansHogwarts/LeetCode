#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

void show(vector<int>& l) {
    for(int i = 0;i < l.size();i++)
	cout << l[i]; //<< "\t";
    cout << endl;
}

string shortestPalindrome(string s) {
    if(s == "" || s.size() <= 1)
	return s;
    string ss = s;
    reverse(ss.begin(), ss.end());
    ss = s + "#" + ss;
    cout << ss << endl;
    int n = ss.size();
    vector<int> map(n, 0);
    for(int i = 1, j = 0;i < n;) {
	if(ss[i] == ss[j]) 
	    map[i++] = ++j;
	else if(j > 0)
	    j = map[j-1];
	else 
	    i++;
    }
    show(map);
    string res = s.substr(map[n-1]);
    reverse(res.begin(), res.end());
    return res + s;
}

int main() {
    string s = "aacecaaa";
    cout << s << endl;
    cout << shortestPalindrome(s) << endl;
    return 0;
}
