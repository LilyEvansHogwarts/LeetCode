#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string> words) {
    int n = words.size();
    vector<int> res;
    if(s == "" || n == 0)
	return res;
    unordered_map<string, int> need;
    for(int i = 0;i < n;i++)
	need[words[i]]++;
    int m = words[0].size();
    for(int i = 0;i < m;i++) {
	unordered_map<string, int> find;
	for(int start = i, end = i, count = 0; end + m <= s.size(); end += m) {
	    string str = s.substr(end,m);
	    auto it = need.find(str);
	    if(it == need.end()) {
		find.clear();
		count = 0;
		start = end + m;
		continue;
	    }
	    while(find.find(str) != find.end() && find[str] >= need[str]) {
		string startSubstr = s.substr(start,m);
		find[startSubstr]--;
		start += m;
		count--;
	    }
	    find[str]++;
	    count++;
	    if(count != n) 
		continue;
	    res.push_back(start);
	}
    }
    return res;
}


int main() {
    vector<string> res;
    res.push_back("foo");
    res.push_back("bar");
    vector<int> out = findSubstring("barfoothefoobarman",res);
    for(int i = 0;i < out.size();i++) 
	cout << out[i] << endl;
    vector<string> res1;
    res1.push_back("aa");
    res1.push_back("aa");
    res1.push_back("aa");
    vector<int> out1 = findSubstring("aaaaaaaa",res1);
    for(int i = 0;i < out1.size();i++) 
	cout << out1[i] << endl;

/*
    res.push_back("word");
    res.push_back("good");
    res.push_back("best");
    res.push_back("good");
    vector<int> out = findSubstring("wordgoodgoodgoodbestword",res);
    for(int i = 0;i < out.size();i++) 
	cout << out[i] << endl;
*/
    return 0;
}
    
