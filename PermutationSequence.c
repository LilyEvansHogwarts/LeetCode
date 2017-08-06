#include<string>
#include<vector>
#include<iostream>
using namespace std;

string test(int n, int k) {
    string s(n,'0');
    int fact[n];
    for(int i = 0;i < n;i++) {
	s[i] = i + 1 + '0';
	if(i == 0)
	    fact[i] = 1;
	else
	    fact[i] = i * fact[i - 1];
    }
    int j, temp;
    for(int i = 0;i < n;i++) {
	j = (k - 1) / fact[n - 1 - i] + i;
	k = k - (j - i) * fact[n - 1 - i];
	temp = s[j];
	while(j > i) {
	    s[j] = s[j - 1];
	    j--;
	}
	s[i] = temp;
    }
    return s;
}

int main() {
    for(int i = 1;i <= 120;i++) {
	cout << test(5,i) << endl;
    }
    return 0;
}
