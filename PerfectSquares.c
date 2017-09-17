#include<iostream>
using namespace std;

int numSquares(int n) {
    cout << "n\t" << n;
    if(n <= 0) return 0;
    if(n == 1) return 1;
    int i = 1;
    while(i * i <= n) i++;
    cout << "\ti\t" << i << endl;
    return 1 + numSquares(n - (i - 1) * (i - 1));
}

int main() {
    cout << numSquares(12) << endl;
    return 0;
}
