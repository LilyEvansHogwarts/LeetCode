#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isPalindrome_1(string s) {
    string t;
    t.assign(s.rbegin(),s.rend());
    if (s == t)
	return true;
    else
	return false;
}

bool isPalindrome(string s) {
    int N = s.size();
    int l = 0, r = N - 1;
    while (l < r && s[l] == s[r]) {
	l++;
	r--;
    }
    if (s[l] == s[r])
	return true;
    else
	return false;
}

string longestPalindrome(string s) {
    int N = s.size();
    if (N <= 1)
	return s;
    string t,l;
    for (int i = 0; i < N; i++) {
	for (int j = N - 1; j >= i; j--) {
	    if (s[i] == s[j]) {
		t.assign(s.begin() + i, s.begin() + j + 1);
	//	cout << t << endl;
		if (isPalindrome(t) && (t.size() > l.size())) {
		    l = t;
		    cout << t << endl;
		    break;
		}
	    }
	}
	if (N - i < l.size())
	    break;
    }
    return l;
}


int main() {
 //   string s1 = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
    string s1 = "abcda";
    cout << longestPalindrome(s1) << endl;
    cout << s1.size() << endl;
    return 0;
}
