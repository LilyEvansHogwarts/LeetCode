#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<string> stringToVector(string s) {
    int N = s.size();
    vector<string> result;
    for(int i = 0;i < N;i++) {
	result.push_back(s.substr(i,1));
    }
    return result;
}

vector<string> letterCombination(vector<string> vec,string s) {
    int Ns = s.size();
    int Nv = vec.size();
    vector<string> result;
    for(int i = 0;i < Ns;i++) {
	for(int j = 0;j < Nv;j++) {
	    result.push_back(vec[j] + s.substr(i,1));
	}
    }
    return result;
}

vector<string> letterCombinations(string s) {
    vector<string> keyboard;
    keyboard.push_back(" ");
    keyboard.push_back("");
    keyboard.push_back("abc");
    keyboard.push_back("def");
    keyboard.push_back("ghi");
    keyboard.push_back("jkl");
    keyboard.push_back("mno");
    keyboard.push_back("pqrs");
    keyboard.push_back("tuv");
    keyboard.push_back("wxyz");
    int N = s.size();
    vector<string> result;
    if(N == 0)
	return result;
    result = stringToVector(keyboard[s[0] - '0']);
    if(N == 1)
	return result;
    for(int i = 1;i < N;i++) {
	result = letterCombination(result,keyboard[s[i]-'0']);
    }
    return result;
}


int main() {
    string s = "234";
    vector<string> out = letterCombinations(s);
    for(int i = 0;i < out.size();i++) {
	cout << out[i] << endl;
    }
    return 0;
}

