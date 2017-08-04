#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

int getLength(ListNode *head) {
    int length = 0;
    while(head) {
	head = head->next;
	length++;
    }
    return length;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k <= 1) return head;
    int traverseTimes = getLength(head) / k;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *ins = &dummy;
    ListNode *cur = ins->next;
    while(traverseTimes--) {
	for(int i = 0;i < k - 1;i++) {
	    ListNode *move = cur->next;
	    cur->next = move->next;
	    move->next = ins->next;
	    ins->next = move;
	}
	ins = cur;
	cur = ins->next;
    }
    return dummy.next;
}

void show(ListNode* head) {
    cout << "show" << endl;
    int i = 0;
    while(head) {
	cout << head->val << "\t";
	head = head->next;
	i++;
	if(i % 10 == 0)
	    cout << endl;
    }
    cout << endl;
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
    ListNode *cur = reverseKGroup(head.next, 8);
    show(cur);
    return 0;
}
