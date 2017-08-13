#include<string>
#include<iostream>
#include<vector>
using namespace std;

int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    if(n > m)
	return 0;
    vector<vector<int> > res(m + 1, vector<int>(n + 1, 0));
    res[0][0] = 1;
    for(int i = 1;i <= m;i++) {
	res[i][0] = 1;
	for(int j = 1;j <= n;j++) 
	    res[i][j] = res[i - 1][j] + (s[i - 1] == t[j - 1]?res[i - 1][j - 1]:0);
    }
    return res[m][n];
}

int main() {
    cout << numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
