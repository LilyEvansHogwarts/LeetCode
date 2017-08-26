#include<vector>
#include<iostream>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0, major1 = 0, major2 = 1;
    for(int i = 0;i < nums.size();i++) {
        if(major1 == nums[i])
            count1++;
        else if(major2 == nums[i])
            count2++;
        else if(count1 == 0) {
            count1++;
            major1 = nums[i];
        } else if(count2 == 0) {
            major2 = nums[i];
            count2++;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    vector<int> res;
    for(int i = 0;i < nums.size();i++) {
        if(major1 == nums[i])
            count1++;
        if(major2 == nums[i])
            count2++;
    }
    if(count1 > nums.size() / 3)
        res.push_back(major1);
    if(count2 > nums.size() / 3)
        res.push_back(major2);
    return res;
}

void show(vector<int>& nums) {
    for(int i = 0;i < nums.size();i++)
        cout << nums[i] << "\t";
    cout << endl;
}

int main() {
    vector<int> nums = {3,3,4,5,6,7,3,4,4,4,3};
    vector<int> res = majorityElement(nums);
    show(nums);
    show(res);
    return 0;
}
