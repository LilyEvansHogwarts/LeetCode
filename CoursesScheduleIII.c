#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void show(vector<vector<int>>& res) {
    for(auto p:res)
	cout << "(" << p[0] << "," << p[1] << ")";
    cout << endl;
}

int scheduleCourses(vector<vector<int>>& courses) {
    int n = courses.size();
    if(n == 0) return 0;
    sort(courses.begin(),courses.end(),[](vector<int>& a,vector<int>& b){return a.back() < b.back();});
    show(courses);
    multiset<int> cls;
    int cursum = 0;
    for(int i = 0;i < n;i++) {
	if(cursum + courses[i][0] <= courses[i][1]) {
	    cursum += courses[i][0];
	    cls.insert(courses[i][0]);
	} else if(!cls.empty() && *cls.rbegin() > courses[i][0]) {
	    cursum += courses[i][0]-*cls.rbegin();
	    cls.erase(--cls.end());
	    cls.insert(courses[i][0]);
	}
    }
    return cls.size();
}

int main() {
    vector<vector<int>> res = {{914,9927},{333,712},{163,5455},{835,5040},{905,8433},{417,8249},{921,9553},{913,7394},{303,7525},{582,8658},{86,957},{40,9152},{600,6941},{466,5775},{718,8485},{34,3903},{380,9996},{316,7755}};
    vector<vector<int>> res1 = {{100,2},{32,50}};
    vector<vector<int>> res2 = {{7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18}};
    cout << scheduleCourses(res) << endl;
    cout << scheduleCourses(res1) << endl;
    cout << scheduleCourses(res2) << endl;
    return 0;
}
