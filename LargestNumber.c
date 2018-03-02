#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> generate(int n) {
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++)
	nums[i] = rand()%1000;
    return nums;
}

void show(vector<int>& nums) {
    for(int i = 0;i < nums.size();i++)
	cout << nums[i] << "\t";
    cout << endl;
}

string largestNumber(vector<int>& nums) {
    auto change = [](const int& num){ return to_string(num); };
    auto compare = [](const string& p1,const string& p2) {return p1+p2 > p2+p1; };
    vector<string> strs;
    transform(nums.begin(),nums.end(),back_inserter(strs),change);
    sort(strs.begin(),strs.end(),compare);
    string p = accumulate(strs.begin(),strs.end(),string(""));
    int i = 0;
    while(p[i] == '0') i++;
    if(i == p.size()) return "0";
    return string(p.begin()+i,p.end());
}

int main() {
    vector<int> nums1 = {0,0};
    vector<int> nums2;
    vector<int> nums3 = generate(10);
    show(nums1);
    cout << largestNumber(nums1) << endl;
    show(nums2);
    cout << largestNumber(nums2) << endl;
    show(nums3);
    cout << largestNumber(nums3) << endl;
}
