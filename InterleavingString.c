#include<string>
#include<iostream>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if(n1 + n2 != n3)
	return false;
    bool table[n1 + 1][n2 + 1];
    for(int i = 0;i <= n1;i++) {
	for(int j = 0;j <= n2;j++) {
	    if(i == 0 && j == 0)
		table[i][j] = true;
	    else if(i == 0)
		table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
	    else if(j == 0)
		table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
	    else
		table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
	}
    }
    return table[n1][n2];
}

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac", s4 = "aadbbbaccc";
    cout << isInterleave(s1, s2, s3) << endl;
    cout << isInterleave(s1, s2, s4) << endl;
    return 0;
}
    
