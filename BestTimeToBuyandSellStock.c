#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int sum = 0, n = prices.size();
    if(n == 0)
	return sum;
    int minimum = prices[0];
    for(int i = 1;i < prices.size();i++) {
	minimum = min(minimum, prices[i]);
	sum = max(prices[i] - minimum, sum);
    }
    return sum;
}

int main() {
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(nums) << endl;
    return 0;
}

