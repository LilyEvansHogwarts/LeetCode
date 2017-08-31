#include<iostream>
#include<string> 
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;

int myAtoi(string str) {
    int i = 0, count = 0, n = str.size(), c, flag = 1;
    while(isspace(str[i])) i++;
    if(str[i] == '+' || str[i] == '-') 
	flag = 1 - 2 * (str[i++] == '-');
    while(i < n) {
	c = str[i] - '0';
	if(c >= 0 && c <= 9) {
	    if(count > INT_MAX / 10 || (count == INT_MAX / 10 && c > 7)) {
		if(flag == 1)
		    return INT_MAX;
		else
		    return INT_MIN;
	    } else {
		count = count * 10 + c;
		i++;
	    }
	} else 
	    break;
    }
    return flag * count;
}

int main() {
    string num = "-2147483648";
    cout << myAtoi(num) << endl;
    return 0;
}
