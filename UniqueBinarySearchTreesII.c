#include<string>
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* clone(TreeNode* root) {
    if(root == NULL)
	return NULL;
    TreeNode* newroot = new TreeNode(root->val);
    newroot->left = clone(root->left);
    newroot->right = clone(root->right);
    return newroot;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    if(n == 0)
	return res;
    res.push_back(NULL);
    for(int i = 1;i <= n;i++) {
	vector<TreeNode*> temp;
	for(int j = 0;j < res.size();j++) {
	    TreeNode* oldroot = res[j];
	    TreeNode* root = new TreeNode(i);
	    root->left = clone(oldroot);
	    temp.push_back(root);

	    if(oldroot != NULL) {
		TreeNode* tmpold = oldroot;
		while(tmpold->right != NULL) {
		    TreeNode* nonroot = new TreeNode(i);
		    TreeNode* tright = tmpold->right;
		    tmpold->right = nonroot;
		    nonroot->left = tright;
		    TreeNode* target = clone(oldroot);
		    temp.push_back(target);
		    tmpold->right = tright;
		    tmpold = tmpold->right;
		}
		tmpold->right = new TreeNode(i);
		TreeNode* target = clone(oldroot);
		temp.push_back(target);
		tmpold->right = NULL;
	    }
	}
	res = temp;
    }
    return res;
}

void show(TreeNode* root) {
    if(root == NULL)
	return;
    cout << root->val << "(";
    show(root->left);
    show(root->right);
    cout << ")";
}

int main() {
    vector<TreeNode*> res = generateTrees(4);
    for(int i = 0;i < res.size();i++) {
 	show(res[i]);
 	cout << endl;
    }
    return 0;
}
