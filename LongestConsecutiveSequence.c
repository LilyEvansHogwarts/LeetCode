#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    int length = 0;
    for(int i = 0;i < nums.size();i++)
	s.insert(nums[i]);
    for(int i = 0;i < nums.size() && !s.empty();i++) {
	if(s.find(nums[i]) == s.end())
	    continue;
	int upper = nums[i], lower = nums[i];
	while(s.find(upper + 1) != s.end())
	    s.erase(++upper);
	while(s.find(lower - 1) != s.end())
	    s.erase(--lower);
	if(upper != lower)
	    s.erase(nums[i]);
	length = max(length, upper - lower + 1);
    }
    return length;
}

int main() {
    vector<int> nums = {100,4,200,1,2,3};
    cout << longestConsecutive(nums) << endl;
    return 0;
}
