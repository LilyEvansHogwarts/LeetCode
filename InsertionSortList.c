#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void show(ListNode* l) {
    while(l) {
	cout << l->val << "\t";
	l = l->next;
    }
    cout << endl;
}

ListNode* insertionSortList(ListNode* head) {
    ListNode* new_head = new ListNode(0);
    new_head->next = head;
    ListNode* pre = new_head;
    ListNode* cur = head;
    while(cur) {
	if(cur->next && cur->next->val < cur->val) {
	    while(pre->next && pre->next->val < cur->next->val)
		pre = pre->next;
	    ListNode* temp = pre->next;
	    pre->next = cur->next;
	    cur->next = cur->next->next;
	    pre->next->next = temp;
	    pre = new_head;
	} else 
	    cur = cur->next;
    }
    ListNode* res = new_head->next;
  //  delete new_head;
    return res;
}

int main() {
    ListNode* head = new ListNode(65);
    ListNode* l0 = new ListNode(27);
    head->next = l0;
    ListNode* l1 = new ListNode(59);
    l0->next = l1;
    ListNode* l2 = new ListNode(64);
    l1->next = l2;
    ListNode* l3 = new ListNode(58);
    l2->next = l3;
    ListNode* k = insertionSortList(head);
    show(k);
    return 0;
}



