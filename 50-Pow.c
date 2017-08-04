#include<iostream>
using namespace std;

double myPow(double x,int n) {
    if(x < 0) return (n % 2 == 0)? myPow(-x,n): -myPow(-x,n);
    if(x == 0 || x == 1) return x;
    if(n == 0) return 1.0;
    if(n < 0) 
	return 1.0 / x * myPow(1.0 / x, -(n + 1));
    if(n % 2 == 0)
	return myPow(x * x, n / 2);
    else
	return x * myPow(x * x, n / 2);
}

int main() {
    cout << myPow(2.0,-2147483648) << endl;
    return 0;
}

