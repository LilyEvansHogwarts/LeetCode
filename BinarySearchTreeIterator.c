#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class BSTIterator {
    public:
	BSTIterator(TreeNode* root) {
	    find_left(root);
	}

	bool hasNext() {
	    if(st.empty()) 
		return false;
	    return true;
	}

	int next() {
	    TreeNode* top = st.top();
	    st.pop();
	    if(top->right != NULL)
		find_left(top->right);
	    return top->val;
	}

	void find_left(TreeNode* root) {
	    TreeNode* p = root;
	    while(p != NULL) {
		st.push(p);
		p = p->left;
	    }
	}

    private:
	stack<TreeNode*> st;
};

vector<int> generateVector(int n) {
    vector<int> nums(n,0);
    for(int i = 0;i < n;i++)
	nums[i] = rand()%1000;
    sort(nums.begin(),nums.end());
    return nums;
}

TreeNode* generateTreeNode(vector<int>& res,int i,int n) {
    TreeNode *root = new TreeNode(res[i]);
    if(2*i+1 < n)
	root->left = generateTreeNode(res,2*i+1,n);
    if(2*i+2 < n)
	root->right = generateTreeNode(res,2*i+2,n);
    return root;
}

TreeNode* generateTreeNode(int n) {
    vector<int> res = generateVector(n);
    return generateTreeNode(res,0,n);
}

int main() {
    TreeNode *root = generateTreeNode(10);
    BSTIterator i = BSTIterator(root);
    while(i.hasNext())
	cout << i.next() << " ";
    cout << endl;
    return 0;
}
