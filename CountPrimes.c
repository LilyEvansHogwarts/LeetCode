#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void show(vector<bool>& l) {
    for(int i = 0;i < l.size();i++) 
	cout << "(" << i << "," << l[i] << ")" << endl;
}

int countPrimes(int n) {
    vector<bool> primes(n, true);
    primes[0] = primes[1] = false;
    int t = sqrt(n), sum = n-2;
    for(int i = 0;i <= t;i++) {
	if(primes[i]) {
	    for(int j = i * i;j < n;j += i) 
		primes[j] = false;
	}
    }
    show(primes);
    return count(primes.begin(), primes.end(), true);
}

int main() {
    int n = 13;
    cout << countPrimes(n) << endl;
    return 0;
}
