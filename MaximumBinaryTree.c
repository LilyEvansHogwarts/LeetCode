#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)
	return NULL;
    int k = 0, sum = 0;
    for(int i = 0;i < n;i++) {
	if(nums[i] > sum) {
	    k = i;
	    sum = nums[i];
	}
    }
    TreeNode* root = new TreeNode(nums[k]);
    if(k > 0) {
	vector<int> tleft = vector<int>(nums.begin(), nums.begin() + k);
	root->left = constructMaximumBinaryTree(tleft);
    }
    if(k < n - 1) {
	vector<int> tright = vector<int>(nums.begin() + k + 1, nums.end());
	root->right = constructMaximumBinaryTree(tright);
    }
    return root;
}

void show(TreeNode* root) {
    if(root == NULL)
	return;
    cout << root->val << "(";
    show(root->left);
    show(root->right);
    cout << ")";
}

void show_vector(vector<int>& board) {


}

int main() {
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* h = constructMaximumBinaryTree(nums);
    show(h);
    cout << endl;
    return 0;
}

