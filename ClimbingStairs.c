#include<iostream>
#include<vector>
using namespace std;

int climbStairs_1(int n) {
    int a = 1, b = 1;
    while(n--)
	a = (b += a) - a;
    return a;
}

int climbStairs_2(int n) {
    if(n == 1)
	return 1;
    if(n == 2)
	return 2;
    vector<int> res(n + 1, 1);
    for(int i = 2;i < n + 1;i++)
	res[i] = res[i - 1] + res[i - 2];
    return res[n];
}

int main() {
    cout << climbStairs_1(10) << endl;
    cout << climbStairs_2(10) << endl;
    return 0;
}
