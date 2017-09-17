#include<vector>
#include<iostream>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void show(vector<vector<int> >& l) {
    for(int i = 0;i < l.size();i++) {
	for(int j = 0;j < l[i].size();j++) {
	    cout << l[i][j] << "\t";
	}
	cout << endl;
    }
    cout << endl;
}

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if(root == NULL) return res;
    deque<TreeNode*> deq;
    deq.push_back(root);
    int isZig = 1;
    while(!deq.empty()) {
	int sz = deq.size();
	isZig = 1 - isZig;
	vector<int> row;
	while(sz--) {
	    if(isZig) {
		root = deq.back();
		deq.pop_back();
		row.push_back(root->val);
		if(root->right)	deq.push_front(root->right);
		if(root->left) deq.push_front(root->left);
	    } else {
		root = deq.front();
		deq.pop_front();
		row.push_back(root->val);
		if(root->left) deq.push_back(root->left);
		if(root->right) deq.push_back(root->right);
	    }
	}
	res.push_back(row);
    }
    return res;
}

void show_Tree(TreeNode* root) {
    if(root == NULL) return;
    cout << root->val << "\t";
    show_Tree(root->left);
    show_Tree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* a0 = new TreeNode(9);
    TreeNode* a1 = new TreeNode(20);
    TreeNode* a2 = new TreeNode(15);
    TreeNode* a3 = new TreeNode(7);
    root->left = a0;
    root->right = a1;
    a1->left = a2;
    a1->right = a3;
    show_Tree(root);
    cout << endl;
    cout << endl;
    vector<vector<int> > res = zigzagLevelOrder(root);
    show(res);
    return 0;
}
