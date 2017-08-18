#include<vector>
#include<iostream>
#include<algorithm>
#define INT_MIN -2147483648
using namespace std;

int maxProfit_1(vector<int>& prices) {
    int n = prices.size();
    if(n == 0)
	return 0;
    int left_min = prices[0];
    vector<int> left(n, 0);
    for(int i = 1;i < n;i++) {
	left[i] = max(left[i - 1], prices[i] - left_min);
	left_min = min(left_min, prices[i]);
    }
    int right_max = prices[prices.size() - 1];
    vector<int> right(n, 0);
    int sum = 0;
    for(int i = prices.size() - 2;i >= 0;i--) {
	right_max = max(prices[i], right_max);
	right[i] = max(right[i + 1], right_max - prices[i]);
	sum = max(sum, right[i] + left[i]);
    }
    return sum;
}

int maxProfit_2(vector<int>& prices) {
    int n = prices.size();
    if(n == 0)
	return 0;
    int hold1 = INT_MIN, hold2 = INT_MIN;
    int release1 = 0, release2 = 0;
    for(int i = 0;i < n;i++) {
	hold1 = max(hold1, -prices[i]);
	release1 = max(release1, hold1 + prices[i]);
	hold2 = max(hold2, release1 - prices[i]);
	release2 = max(release2, hold2 + prices[i]);
    }
    return release2;
}

int main() {
    vector<int> nums = {2,3,5,2,5,2,4,5,2,3,4,42,4,34,245,2};
    cout << maxProfit_2(nums) << endl;
    return 0;
}
