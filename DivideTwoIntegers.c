#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

int divide(int dividend, int divisor) {
    bool flag = (dividend < 0) ^ (divisor < 0);
    long long dividendll = abs((long long) dividend);
    long long divisorll = abs((long long) divisor);
    long long res = 0, d = divisorll, p = 1;

    while ((d << 1) <= dividendll) {
	d <<= 1;
	p <<= 1;
    }

    while (dividendll >= divisorll) {
	if (dividendll >= d) {
	    dividendll -= d;
	    res += p;
	}
	d >>= 1;
	p >>= 1;
    }

    if (flag == true) res = -res;
    if (res >= INT_MAX) return INT_MAX;
    return res;
}

int main() {
    int result = divide(2147483648,1);
    cout << result << endl;
    return 0;
}
