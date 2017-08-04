#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void show(ListNode* head) {
    int i = 0;
    while(head) {
	cout << head->val << "\t";
	head = head->next;
	i++;
	if(i % 15 == 0)
	    cout << endl;
    }
    cout << endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *ins = head, *cur = head;
    while(n--) 
	ins = ins->next;
    if(!ins)
	return head->next;
    while(ins->next) {
	ins = ins->next;
	cur = cur->next;
    }
    cur->next = cur->next->next;
    return head;
}

int main() {
    ListNode head(0);
    ListNode *ins = &head;
    for(int i = 1;i < 100;i++) {
	ListNode* haha = new ListNode(i);
	ins->next = haha;
	ins = ins->next;
    }
    show(head.next);
    ListNode *cur = removeNthFromEnd(head.next,99);
    show(cur);
    return 0;
}

