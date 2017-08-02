#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


string intToWords1000(int num, unordered_map<int, string> need) {
    string s;
    if(num / 100) {
	if(s != "")
	    s += " ";
	s = s + need[num / 100] + " " + need[100];
	num = num - num / 100 * 100;
    }
    if(num / 10 >= 2) {
	if(s != "") 
	    s += " ";
	s = s + need[num / 10 * 10];
	num = num - num / 10 * 10;
    }
    if(num > 0) {
	if(s != "")
	    s += " ";
	s = s + need[num];
	return s;
    } else
	return s;
}

string intToWords(int num) {
    unordered_map<int, string> need;
    need[1] = "One";
    need[2] = "Two";
    need[3] = "Three";
    need[4] = "Four";
    need[5] = "Five";
    need[6] = "Six";
    need[7] = "Seven";
    need[8] = "Eight";
    need[9] = "Nine";
    need[10] = "Ten";
    need[11] = "Eleven";
    need[12] = "Twelve";
    need[13] = "Thirteen";
    need[14] = "Fourteen";
    need[15] = "Fifteen";
    need[16] = "Sixteen";
    need[17] = "Seventeen";
    need[18] = "Eighteen";
    need[19] = "Nineteen";
    need[20] = "Twenty";
    need[30] = "Thirty";
    need[40] = "Forty";
    need[50] = "Fifty";
    need[60] = "Sixty";
    need[70] = "Seventy";
    need[80] = "Eighty";
    need[90] = "Ninety";
    need[100] = "Hundred";
    need[1000] = "Thousand";
    need[1000000] = "Million";
    need[1000000000] = "Billion";
    string s;
    if(num / 1000000000) {
	s = need[num / 1000000000] + " " + need[1000000000];
	num = num - num / 1000000000 * 1000000000;
    }
    string temp = intToWords1000(num / 1000000, need);
    if(temp != "") {
	if(s != "")
	    s += " ";
	s = s + temp + " " + need[1000000];
	num = num - num / 1000000 * 1000000;
    }
    temp = intToWords1000(num / 1000, need);
    if(temp != "") {
	if(s != "")
	    s += " ";
	s = s + temp + " " + need[1000];
	num = num - num / 1000 * 1000;
    }
    temp = intToWords1000(num, need);
    if(temp != "") {
	if(s != "")
	    s += " ";
	s = s + temp;
    }
    return s;
}



int main() {
    for(int i = 1234567;i < 1000000000;) { 
	cout << intToWords(i) << endl;
	if(i < 1000)
	    i = i + 50;
	else if(i < 1000000)
	    i = i + 50000;
	else 
	    i = i + 50000000;
    }
    return 0;
}

